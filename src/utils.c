#include "utils.h"

#include <stdlib.h>
#include <time.h>

#ifndef _WIN32

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

#endif

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

bool is_opposite_directed(Coordinate first_vector, Coordinate second_vector)
{
    return first_vector.x * second_vector.x + first_vector.y * second_vector.y >= 0;
}
