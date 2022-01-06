#include "game.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

GameState setup_game() {
    GameState game;

    /* getting field sizes from user */
    puts("Enter field sizes:\nHeight: ");
    scanf("%u", &game.field_height);
    puts("Width: ");
    scanf("%u", &game.field_width);

    /* Creating snake at random position */
    game.snake.body = (Coordinate *) calloc(game.field_height * game.field_width, sizeof(Coordinate));
    game.snake.snake_len = 0;

    game.snake.head_pos = get_random_coords(game.field_width, game.field_height);
    push_front_point(&game.snake, game.snake.head_pos);

    /* Random direction */
    game.snake.direction.x = rand() % 2;
    game.snake.direction.y = !game.snake.direction.x;

    return game;
}

bool is_game_over(GameState *game) {
	return true;
}

void draw_field(GameState *game) {
}

void scan_user_key(GameState *game) {
}

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState *game) {
}

void free_game(GameState *game) {
}

void remove_back_point(Snake *snake) {
    snake->snake_len--;
}

void push_front_point(Snake *snake, Coordinate point) {
    remove_back_point(snake);

    for (int i = 0; snake->snake_len-1; ++i){ 
        snake->body[i+1] = snake->body[i];
    }
    
    snake->body[0] = point;
}
