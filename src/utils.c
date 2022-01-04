#include "utils.h"
#include "game.h"

#include <stdlib.h>
#include <time.h>

void init_rand() {
    srand(time(NULL));
}

Coordinate get_random_coords(GameState *game) {
    Coordinate out = {
            .x = get_random_integer(0, game->field_width),
            .y = get_random_integer(0, game->field_height)
    };
    return out;
}

void push_front_point(Snake *snake, const Coordinate *point) {
}

void remove_back_point(Snake *snake) {
}

int get_random_integer(int from, int to) {
    return from + rand() % (to - from);
}