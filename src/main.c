#include "game/game.h"
#include "raylib.h"
#include <stdio.h>

int main(void) {
    const int screenWidth = 854;
    const int screenHeight = 480;

    game_t game = game_init();

    InitWindow(screenWidth, screenHeight, "sand");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("sand", 0, 0, 10, BLACK);
        EndDrawing();
    }

    CloseWindow();
}
