#include "utils.h"

#include <stdlib.h>

void init_rand()
{
    srand(time(NULL));
}

Coordinate get_random_coords(int width, int height)
{
    Coordinate out = {
        .x = get_random_integer(0, width),
        .y = get_random_integer(0, height)
    };
    return out;
}

int get_random_integer(int from, int to)
{
    return from + rand() % (to - from);
}

void msleep(int tms)
{
    struct timeval tv;
    tv.tv_sec  = tms / 1000;
    tv.tv_usec = (tms % 1000) * 1000;
    select (0, NULL, NULL, NULL, &tv);
}
