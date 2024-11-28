#include "raylib.h"
#include "ui.h"

void DrawBorderRect(Rectangle rect, float border_width, bool filled, Color tint, Color border_tint) {
    Rectangle inner = {
        .x = rect.x + border_width,
        .y = rect.y + border_width,
        .width = rect.width - border_width * 2,
        .height = rect.height - border_width * 2};

    DrawRectangleRec(rect, border_tint);
    DrawRectangleRec(inner, filled ? tint : BLACK);
}
