#include "game.h"
#include "utils.h"

#include <ncurses.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    init_rand();

    GameState game = setup_game();

    draw_field(&game);
    while (!is_game_over(&game)) {
        /* sleep(1); */
        scan_user_key(&game);
        next_step(&game);
		game.snake.snake_len > 5 ? msleep(130) : msleep(230);
        draw_field(&game);
        /* usleep((unsigned)300000); */
    }

    free_game(&game);

    return 0;
}
