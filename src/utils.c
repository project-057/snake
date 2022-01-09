#include "utils.h"

#include <stdlib.h>
#include <time.h>

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
