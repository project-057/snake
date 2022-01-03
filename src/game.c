#include "game.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

GameState setup_game()
{
    GameState game;

    //  getting field sizes from console
    printf("Enter field sizes:\nHeight: ");
    scanf("%llu", &game.field_height);
    printf(" Width: ");
    scanf("%llu", &game.field_width);

    // Creating snake at random position
    game.snake.snake_points->next = NULL;
    game.snake.snake_points->prev = NULL;
    game.snake.snake_len = 0;

    game.head_pos = get_random_coords(&game);
    push_back_point(&game.snake, &game.snake.head_pos);

    game.snake.direction.x = rand() % 2;
    game.snake.direction.y = (x == 0 ? 1 : 0);
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

void push_back_point(Snake* snake, const Coordinate* point)
{
}
