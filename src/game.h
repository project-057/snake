#include <stdbool.h>

typedef enum {
    NONE = 0,
    APPLE,
    SNAKE_TAIL,
    SNAKE_HEAD
} SpaceState;

typedef struct {
    bool is_game_over;
    size_t field_height;
    size_t field_width;
    Coordinate tail_pos;
    Coordinate head_pos;
    Coordinate direction;
    SpaceState** field;
} GameState;

GameState setup_game();

bool is_game_over(GameState* game);

void draw_field(GameState* game);

void scan_user_key(GameState* game);

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game);

void free_game(GameState* game);
