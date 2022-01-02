#include "utils.h"

int main(int argc, char* argv[])
{
    Game game = setup();
    while (!is_over(&game)) {
        draw(&game);
        input(&game);
        next_step(&game);
    }
}
