#include "element.h"
#include "game/game.h"
#include "grain.h"
#include "raylib.h"
#include "ui/ui.h"
#include "utils/utils.h"
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
        ClearBackground(BLACK);
        BeginMode2D(game.camera);

        DrawButton((ui_button_t){
            .rect = {0, SANDBOX_HEIGHT, 20, 10},
            .tint = PINK,
            .text = "tubronium",
            .text_size = 4.0,
            .text_tint = WHITE,
            .state = game.brush.id == ELEMENT_TUBRONIUM ? BUTTON_SELECTED : BUTTON_ENABLED,
            .fn = game_element_switcheroo_callback,
            .id = ELEMENT_TUBRONIUM,
            .game = &game,
        });
        DrawButton((ui_button_t){
            .rect = {20, SANDBOX_HEIGHT, 20, 10},
            .tint = RED,
            .text = "sloni",
            .text_size = 4.0,
            .text_tint = WHITE,
            .state = game.brush.id == ELEMENT_SILONIUM ? BUTTON_SELECTED : BUTTON_ENABLED,
            .fn = game_element_switcheroo_callback,
            .id = ELEMENT_SILONIUM,
            .game = &game,
        });

        for (int y = 0; y < SANDBOX_HEIGHT; y++) {
            for (int x = 0; x < SANDBOX_WIDTH; x++) {
                grain_t* grain = game_get_grain(&game, x, y);
                if (grain->id == ELEMENT_NOTHING)
                    continue;

                element_t* element = game_get_element(&game, grain->id);
                DrawRectangle(x, y, 1, 1, element->color);
            }
        }

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 screenMousePosition = GetMousePosition();
            Vector2 mousePosition = GetScreenToWorld2D(screenMousePosition, game.camera);

            element_t* element = game_get_element(&game, game.brush.id);
            Rectangle rect = util_rect_from_radius((Vector2){.x = mousePosition.x, .y = mousePosition.y}, game.brush.size / 2.0);

            for (int x = rect.x; x < rect.x + rect.width; x++) {
                if (x >= SANDBOX_WIDTH || x < 0)
                    continue;

                for (int y = rect.y; y < rect.y + rect.height; y++) {
                    if (y >= SANDBOX_HEIGHT || y < 0)
                        continue;
                    grain_t* grain = game_get_grain(&game, x, y);
                    grain->id = game.brush.id;
                    grain->state = GRAIN_NORMAL;
                    grain->lifetime = 0;
                    grain->temperature = element->nominal_temperature; // FIX:
                }
            }

            // DrawRectangleRec(rect, element->color);
        }

        EndDrawing();
        if (IsKeyPressed(KEY_MINUS)) {
            if (game.brush.size > 1)
                game.brush.size--;
        }
        if (IsKeyPressed(KEY_EQUAL)) {
            game.brush.size++;
        }
    }

    CloseWindow();
}
