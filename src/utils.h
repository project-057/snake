#pragma once

/* In c-array x - is a number of column, y - is a row number */
typedef struct {
    int x, y;
} Coordinate;

void init_rand();

Coordinate get_random_coords(int width, int height);

int get_random_integer(int from, int to);
