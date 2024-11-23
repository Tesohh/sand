#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
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
