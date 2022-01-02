typedef struct {
} Game;

Game setup_game();

int is_game_over(Game* game);

void draw_field(Game* game);

void scan_user_key(Game* game);

/* Run after void scan_user_key(Game* game) */
void next_step(Game* game);

void free_game(Game* game);
