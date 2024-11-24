#ifndef GAME_H
#define GAME_H

#include "element/element.h"
#include "grain/grain.h"
#include <stddef.h>

#define SANDBOX_WIDTH 854
#define SANDBOX_HEIGHT 480

typedef struct Game {
    grain_t* grains;
    element_t elements[ELEMENTS_LEN]; // yea this is correct, i don't want to include the end
} game_t;

// allocates memory for the grains, and populates the elements list
// doesn't do anything raylib related
game_t game_init(void);

// frees memory allocated by init
void game_deinit(game_t*);

// helper function to get a grain from the grid (which isn't really a grid)
grain_t* game_get_grain(game_t* game, size_t x, size_t y);

#endif
