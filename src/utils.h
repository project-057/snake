#ifndef UTILS_H
#define UTILS_H

#include "game.h"

/* In c-array x - is a number of column, y - is a row number */
typedef struct {
    int x, y;
} Coordinate;

/* Doubly linked list */
typedef struct {
    Coordinate pos;
    Point* next;
    Point* prev;
} Point;

void init_rand();

Coordinate get_random_coords(GameState* game);

int get_random_integer(int from, int to);

void push_back_point(Snake* snake, const Coordinate* point);

void push_front_point(Snake* snake, const Coordinate* point);

void remove_back_point(Snake* snake);

#endif