#include "game.h"
#include "element/element.h"
#include "grain.h"
#include <stdio.h>
#include <stdlib.h>

game_t game_init(void) {
    game_t game = {0};
    game.brush = (game_brush_t){.id = ELEMENT_NOTHING, .size = 1};
    game.grains = calloc(SANDBOX_LENGTH, sizeof(grain_t));

    for (int i = 0; i < SANDBOX_WIDTH * SANDBOX_HEIGHT; i++) {
        (game.grains + i)->id = ELEMENT_TUBRONIUM;
    }

    element_t* elements = element_get_list();

    for (int i = 0; i < ELEMENTS_LEN; i++) {
        game.elements[i] = elements[i];
    }

    free(elements);

    return game;
}

void game_deinit(game_t* game) {
    free(game->grains);
}

grain_t* game_get_grain(game_t* game, size_t x, size_t y) {
    if (x >= SANDBOX_WIDTH)
        return NULL;
    if (y >= SANDBOX_HEIGHT)
        return NULL;
    return game->grains + ((y * SANDBOX_WIDTH) + x);
}

element_t* game_get_element(game_t* game, element_id id) {
    return game->elements + id;
}
