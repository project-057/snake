#ifndef UTILS_H
#define UTILS_H

// In c-array x - is a number of column, y - is a row number
typedef struct {
    int x, y;
} Coordinate;

void init_rand();

Coordinate get_random_coords(GameState* game);

#endif // UTILS_H
