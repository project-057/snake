#include "utils.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>

void init_rand()
{
    srand(time(NULL));
}

Coordinate get_random_coords(GameState* game)
{
    Coordinate out;
    out.x = rand() % game->field_width;
    out.y = rand() % game->field_height;

    return out;
}