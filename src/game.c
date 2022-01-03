#include "game.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

GameState setup_game() {
    GameState game;

    /* getting field sizes from user */
    puts("Enter field sizes:\nHeight: ");
    scanf("%llu", &game.field_height);
    puts(" Width: ");
    scanf("%llu", &game.field_width);

    /* Creating snake at random position */
    game.snake.snake_points = (Coordinate *) calloc(game.field_height * game.field_width, sizeof(Coordinate));
    game.snake.snake_len = 0;

    game.snake.head_pos = get_random_coords(&game);
    push_front_point(&game.snake, &game.snake.head_pos);

    /* Random direction */
    game.snake.direction.x = rand() % 2;
    game.snake.direction.y = !game.snake.direction.x;

    return game;
}

bool is_game_over(GameState *game)
{
}

void draw_field(GameState *game)
{
}

void scan_user_key(GameState *game)
{
}

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState *game)
{
}

void free_game(GameState *game)
{
}
