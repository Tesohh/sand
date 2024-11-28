#include "element.h"
#include "game/game.h"
#include "raylib.h"
#include "ui/ui.h"
#include <stdio.h>

#define ZOOM 4
#define UI_HEIGHT 20

int main(void) {
    const int screenWidth = SANDBOX_WIDTH * ZOOM;
    const int screenHeight = SANDBOX_HEIGHT * ZOOM + UI_HEIGHT * ZOOM;

    game_t game = game_init();
    game.camera = (Camera2D){.zoom = ZOOM};

    InitWindow(screenWidth, screenHeight, "sand");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode2D(game.camera);

        DrawButton((ui_button_t){
            .rect = {0, SANDBOX_HEIGHT, 20, 10},
            .tint = PINK,
            .text = "cissy",
            .text_size = 4.0,
            .text_tint = WHITE,
            .state = BUTTON_ENABLED,
            .fn = NULL,
            .game = &game,
        });

        ClearBackground(BLACK);
        {
            for (int y = 0; y < SANDBOX_HEIGHT; y++) {
                for (int x = 0; x < SANDBOX_WIDTH; x++) {
                    grain_t* grain = game_get_grain(&game, x, y);
                    if (grain->id == ELEMENT_NOTHING)
                        continue;

                    element_t* element = game.elements + grain->id;
                    DrawRectangle(x, y, 1, 1, element->color);
                }
            }
        }
        EndDrawing();
    }

    CloseWindow();
}
