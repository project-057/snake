#pragma once

#include <stdio.h>

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#endif

#ifdef __FreeBSD__
#include <termios.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#include <conio.h>
#endif

#ifdef _TERMIOS_H

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#endif

/* In c-array x - is a number of column, y - is a row number */
typedef struct {
    int x, y;
} Coordinate;

void init_rand();

Coordinate get_random_coords(int width, int height);

int get_random_integer(int from, int to);
