#pragma once

#include "utils.h"

typedef struct {
    /* Direction vector {x, y}, where x and y 1 or 0; */
    Coordinate direction;
    Coordinate* body;
    Coordinate* head;
    unsigned snake_len;
} Snake;

typedef struct
{
    unsigned field_height;
    unsigned field_width;
    Snake snake;
    Coordinate melon;
} GameState;

GameState setup_game();

bool is_game_over(GameState* game);

void draw_field(GameState* game);

void scan_user_key(GameState* game);

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game);

void free_game(GameState* game);

void remove_back_point(Snake* snake);

void push_front_point(Snake* snake, Coordinate point);
