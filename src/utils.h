typedef struct {
} Game;

Game setup();

int is_over(Game* game);

void draw(Game* game);

void input(Game* game);

void next_step(Game* game);

void free_game(Game* game);
