#include "game.h"
#include "utils.h"

#include <ncurses.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    init_rand();

    GameState game = setup_game();

    while (!is_game_over(&game)) {
        draw_field(&game);
        scan_user_key(&game);
        next_step(&game);
        sleep(1);
        /* usleep((unsigned)300000); */
    }

    free_game(&game);

    return 0;
}
