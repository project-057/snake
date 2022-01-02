typedef struct {
} GameState;

GameState setup_game();

int is_game_over(GameState* game);

void draw_field(GameState* game);

void scan_user_key(GameState* game);

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game);

void free_game(GameState* game);
