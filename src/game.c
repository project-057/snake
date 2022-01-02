#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int get_random()
{
    
}

GameState setup_game()
{
    GameState game;

    printf("Enter field sizes:\nHeight: ");
    scanf("%d", &game.field_height);
    printf(" Width: ");
    scanf("%d", &game.field_width);


}

bool is_game_over(GameState* game)
{
}

void draw_field(GameState* game)
{
}

void scan_user_key(GameState* game)
{
}

/* Run after void scan_user_key(GameState* game) */
void next_step(GameState* game)
{
}

void free_game(GameState* game)
{
}
