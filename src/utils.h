#ifndef UTILS_H
#define UTILS_H

#include "game.h"

// In c-array x - is a number of column, y - is a row number
typedef struct Coordinate {
    int x, y;
} Coordinate;

// Doubly linked list
typedef struct Point {
    Coordinate pos;
    Point* next;
    Point* prev;
} Point;

void init_rand();

Coordinate get_random_coords(GameState* game);

void push_back_point(Snake* snake, const Coordinate* point);

void push_front_point(Snake* snake, const Coordinate* point);

void remove_back_point(Snake* snake);

#endif // UTILS_H
