#include "game.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

GameState setup_game()
{
    GameState game;

    /* getting field sizes from user */
    puts("Enter field sizes:\nHeight: ");
    scanf("%u", &game.field_height);
    puts("Width: ");
    scanf("%u", &game.field_width);

    /* Creating snake at random position */
    game.snake.body = (Coordinate*)calloc(game.field_height * game.field_width, sizeof(Coordinate));
    game.snake.snake_len = 0;

    game.snake.head_pos = get_random_coords(game.field_width, game.field_height);
    push_front_point(&game.snake, &game.snake.head_pos);

    /* Random direction */
    game.snake.direction.x = rand() % 2;
    game.snake.direction.y = !game.snake.direction.x;

    return game;
}

bool is_game_over(GameState* game)
{
    int length = game->snake.snake_len;
    /* The snake can't crash if length is less than 4 */
    for (int i = 4; i < length; i++) {
        if (game->snake.head_pos.x == game->snake.body[i].x && game->snake.head_pos.y == game->snake.body[i].y)
            return true;
    }
    return false;
}

void draw_field(GameState* game)
{
    enum field_components {
        CELL = '.',
        HEAD = '*',
        BODY = '*',
        MELON = '0'
    };
    int length = game->snake.snake_len;

    for (int i = 0; i < game->field_height; i++) {
        for (int j = 0; j < game->field_width; j++) {
            int body_part = 0;
            for (; body_part < length; body_part++) {
                if (game->snake.body[body_part].y == i && game->snake.body[body_part].x == j) {
                    break;
                }
            }
            /* if body_part == length then we haven't drawn part of snake's body */
            if (body_part == 0)
                printf("%c", HEAD);
            else if (body_part < length)
                printf("%c", BODY);
            else {
                // TODO: draw a melon
                printf("%c", CELL);
            }
        }
        printf("\n");
    }
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

    if (input_key == KEY_RIGHT || input_key == 'l')
        game->snake.direction = right;
    if (input_key == KEY_LEFT || input_key == 'h')
        game->snake.direction = left;
    if (input_key == KEY_DOWN || input_key == 'j')
        game->snake.direction = down;
    if (input_key == KEY_UP || input_key == 'k')
        game->snake.direction = up;
}

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game)
{
}

void free_game(GameState* game)
{
}

void remove_back_point(Snake* snake)
{
}

void push_front_point(Snake* snake, const Coordinate* point)
{
}
