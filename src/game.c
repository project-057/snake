#include "game.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIELD_SPACE_SIZE 300

GameState setup_game()
{
    GameState game;

    puts("Enter field sizes:");
    puts("Height:");
    scanf("%u", &game.field_height);
    puts("Width:");
    scanf("%u", &game.field_width);

    if (game.field_height == 0 || game.field_width == 0 || game.field_height * game.field_width >= MAX_FIELD_SPACE_SIZE) {
        puts("Not valid sizes, set values to default 10x10.");
        game.field_height = 10;
        game.field_width = 10;
    }

    /* Generate snake head at random position */
    game.snake.body = calloc(game.field_height * game.field_width, sizeof(Coordinate));
    game.snake.snake_len = 0;

    push_front_point(&game.snake, get_random_coords(game.field_width, game.field_height));
    game.snake.head = &game.snake.body[0];

    /* Generate random direction */
    game.snake.direction.x = rand() % 2;
    game.snake.direction.y = !game.snake.direction.x;

    do {
        game.melon = get_random_coords(game.field_width, game.field_height);
    } while (game.melon.x != game.snake.head->x && game.melon.y != game.snake.head->y);

    return game;
}

bool is_game_over(GameState* game)
{
    int length = game->snake.snake_len;
    /* The snake can't crash if length is less than 4 */
    for (int i = 4; i < length; i++) {
        if (game->snake.head->x == game->snake.body[i].x && game->snake.head->y == game->snake.body[i].y)
            return true;
    }
    return false;
}

void draw_field(GameState* game)
{
    enum field_components {
        CELL = '.',
        HEAD = '*',
        BODY = '+',
        MELON = '0'
    };
    int length = game->snake.snake_len;

    char** field = calloc(game->field_height, sizeof(char*));
    char* field_data = calloc(game->field_width * game->field_height + game->field_height + 1, sizeof(char));

    // fill the field_data with CELLs
    for (int i = 0; i < game->field_height * game->field_width + game->field_height + 1; i++) {
        field_data[i] = CELL;
    }

    for (int i = 0; i < game->field_height; i++) {
        field[i] = field_data + i * (game->field_width + 1);
        field_data[(i + 1) * (game->field_width) + i] = '\n'; // add '\n' for the correct drawing
    }

    // add snake to the field
    for (int i = 0; i < length; i++) {
        Coordinate body = game->snake.body[i];
        field[body.y][body.x] = i ? BODY : HEAD;
    }

    // add melon to the field
    field[game->melon.y][game->melon.x] = MELON;

    puts(field_data);

    free(field_data);
    free(field);
}

#ifdef _WIN32
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80
#define ARROW_PRESSED 0
#else
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_UP 65
#define KEY_DOWN 66
#define ARROW_PRESSED 27
#define TERMIOS_ARROW_KEY_PRESSED 91
#endif

void scan_user_key(GameState* game)
{
    int input_key = getch();

    /* When user press arrow key getch() returns 0 */
    if (input_key == ARROW_PRESSED) {
        input_key = getch();
#ifndef _WIN32
        if (input_key == TERMIOS_ARROW_KEY_PRESSED)
            input_key = getch();
#endif
    }

    const Coordinate right = { 1, 0 };
    const Coordinate left = { -1, 0 };
    const Coordinate down = { 0, 1 };
    const Coordinate up = { 0, -1 };
    Coordinate new_direction = game->snake.direction;

    if (input_key == KEY_RIGHT || input_key == 'l') {
        new_direction = right;
    }
    if (input_key == KEY_LEFT || input_key == 'h') {
        new_direction = left;
    }
    if (input_key == KEY_DOWN || input_key == 'j') {
        new_direction = down;
    }
    if (input_key == KEY_UP || input_key == 'k') {
        new_direction = up;
    }
    if (game->snake.direction.x * new_direction.x + game->snake.direction.y * new_direction.y >= 0) {
        game->snake.direction = new_direction;
    }
}

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game)
{
    /* Moving */
    Coordinate next_move = {
        .x = (game->snake.head->x + game->snake.direction.x + game->field_width) % game->field_width,
        .y = (game->snake.head->y + game->snake.direction.y + game->field_height) % game->field_height
    };
    push_front_point(&game->snake, next_move);

    /* Melon check */
    if (next_move.x != game->melon.x || next_move.y != game->melon.y) {
        remove_back_point(&game->snake);
        return;
    }

    /* Updating melon position */
    bool** free_coordinates = malloc(game->field_height * sizeof(bool*));
    bool* data = malloc(game->field_width * game->field_height * sizeof(bool));

    for (int i = 0; i < game->field_height; ++i) {
        free_coordinates[i] = data + i * game->field_width;
    }

    for (int i = 0; i < game->field_height; ++i) {
        for (int j = 0; j < game->field_width; ++j) {
            free_coordinates[i][j] = true;
        }
    }

    /* Removing all snakes points */
    for (int i = 0; i < game->snake.snake_len; ++i) {
        free_coordinates[game->snake.body[i].y][game->snake.body[i].x] = false;
    }

    Coordinate stack_coords[MAX_FIELD_SPACE_SIZE];

    int stack_coords_size = 0;

    for (int i = 0; i < game->field_height; ++i) {
        for (int j = 0; j < game->field_width; ++j) {
            if (free_coordinates[i][j]) {
                stack_coords[stack_coords_size++] = (Coordinate) { .x = j, .y = i };
            }
        }
    }

    game->melon = stack_coords[get_random_integer(0, stack_coords_size)];

    /* free */
    free(free_coordinates);
    free(data);
}

void free_game(GameState* game)
{
    free(game->snake.body);
}

void remove_back_point(Snake* snake)
{
    snake->snake_len--;
}

void push_front_point(Snake* snake, Coordinate point)
{
    for (int i = snake->snake_len++; i >= 1; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = point;
}
