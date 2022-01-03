#include "game.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

GameState setup_game()
{
    GameState game;
    game.is_game_over = false;

    /* getting field sizes from user */
    puts("Enter field sizes:\nHeight: ");
    scanf("%llu", &game.field_height);
    puts(" Width: ");
    scanf("%llu", &game.field_width);

    /* filling game field with NONE value */
    SpaceState** field = (SpaceState**) malloc(height * sizeof(SpaceState*));
    SpaceState* field_data = (SpaceState*) malloc(width * height * sizeof(SpaceState));
    for (int i = 0; i < height; ++i) {
        field[i] = field_data + i * width;
    }

    /* Creating snake at random position */
    game.snake.snake_points->next = NULL;
    game.snake.snake_points->prev = NULL;
    game.snake.tail_point = NULL;
    game.snake.snake_len = 0;

    game.head_pos = get_random_coords(&game);
    push_back_point(&game.snake, &game.snake.head_pos);

    /* Random direction */
    game.snake.direction.x = rand() % 2;
    game.snake.direction.y = !game.snake.direction.x;

    /* updating game field */
    game.field[game.snake.head_pos.y][game.snake.head_pos.x];

    return game;
}

bool is_game_over(GameState* game)
{
}

void draw_field(GameState* game)
{
}

void scan_user_key(GameState* game)
{
}

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game)
{
}

void free_game(GameState* game)
{
}
