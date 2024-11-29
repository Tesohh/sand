#ifndef GAME_H
#define GAME_H

#include "element/element.h"
#include "grain/grain.h"
#include <raylib.h>
#include <stddef.h>
#include <stdint.h>

#define SANDBOX_WIDTH 200
#define SANDBOX_HEIGHT 150
#define SANDBOX_LENGTH SANDBOX_WIDTH* SANDBOX_HEIGHT

typedef struct GameBrush {
    element_id id;
    uint8_t size;
} game_brush_t;

typedef struct Game {
    grain_t* grains;
    element_t elements[ELEMENTS_LEN];

    Camera2D camera;
    game_brush_t brush;
} game_t;

// allocates memory for the grains, and populates the elements list
// doesn't do anything raylib related
game_t game_init(void);

// frees memory allocated by init
void game_deinit(game_t*);

// helper function to get a grain from the grid (which isn't really a grid)
grain_t* game_get_grain(game_t* game, size_t x, size_t y);

element_t* game_get_element(game_t* game, element_id id);

void game_element_switcheroo_callback(game_t* game, size_t id);

#endif
