#ifndef UTILS_H
#define UTILS_H

#include "game.h"

/* In c-array x - is a number of column, y - is a row number */
struct Coordinate {
    int x, y;
};

void init_rand();

Coordinate get_random_coords(GameState *game);

int get_random_integer(int from, int to);

void push_front_point(Snake *snake, const Coordinate *point);

void remove_back_point(Snake *snake);

#endif