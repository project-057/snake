#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#ifndef _WIN32

#include <termios.h>
#include <unistd.h>

#else
#include <conio.h>
#endif

#ifndef _WIN32

int getch(void);

#endif

/* In c-array x - is a number of column, y - is a row number */
typedef struct {
    int x, y;
} Coordinate;

void init_rand();

Coordinate get_random_coords(int width, int height);

int get_random_integer(int from, int to);

void msleep(int tms);
