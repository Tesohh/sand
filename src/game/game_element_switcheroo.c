#include "game.h"
#include <stdio.h>

void game_element_switcheroo_callback(game_t* game, size_t id) {
    game->brush.id = id;
}
