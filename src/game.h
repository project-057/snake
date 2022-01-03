#ifndef GAME_H
#define GAME_H

#include "utils.h"
#include <stdbool.h>

typedef enum SpaceState {
    NONE = 0,
    APPLE,
    SNAKE_TAIL,
    SNAKE_HEAD
} SpaceState;

typedef struct Snake {
    Coordinate head_pos;
    //  Direction vector {x, y}, where x and y 1 or 0;
    Coordinate direction;
    Point* snake_points;
    size_t snake_len;
} Snake;

typedef struct GameState {
    bool is_game_over;
    size_t field_height;
    size_t field_width;
    SpaceState** field;
    Snake snake;
} GameState;

GameState setup_game();

bool is_game_over(GameState* game);

void draw_field(GameState* game);

void scan_user_key(GameState* game);

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game);

void free_game(GameState* game);

#endif