#include "game.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    init_rand();

    GameState game = setup_game();

    while (!is_game_over(&game)) {
        draw_field(&game);
        scan_user_key(&game);
        next_step(&game);
    }

    free_game(&game);

    return 0;
}
