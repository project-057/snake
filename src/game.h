#include "utils.h"
#include <stdbool.h>

typedef enum {
    NONE = 0,
    APPLE,
    SNAKE_TAIL,
    SNAKE_HEAD
} SpaceState;

// Doubly linked list
typedef struct {
    Coordinate pos;
    Point* next;
    Point* prev;
} Point;

typedef struct {
    Coordinate head_pos;
    //  Direction vector {x, y}, where x and y 1 or 0;
    Coordinate direction;
    Point* snake_points;
    size_t snake_len;
} Snake;

typedef struct {
    bool is_game_over;
    size_t field_height;
    size_t field_width;
    SpaceState** field;
    Snake snake;
} GameState;

GameState setup_game();

bool is_game_over(GameState* game);

void draw_field(GameState* game);

void scan_user_key(GameState* game);

void push_back_point(Snake* snake, const Coordinate* point);

void push_front_point(Snake* snake, const Coordinate* point);

void remove_back_point(Snake* snake);

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game);

void free_game(GameState* game);