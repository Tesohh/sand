#include "raylib.h"
#include "ui.h"

void DrawCenteredText(Rectangle rect, char* text, float font_size, Color tint) {
    Font font = GetFontDefault();

    Vector2 size = MeasureTextEx(font, text, font_size, 0.5);
    float x = rect.width / 2 - size.x / 2 + rect.x;
    float y = rect.height / 2 - size.y / 2 + rect.y;

    DrawTextEx(font, text, (Vector2){x, y}, font_size, 0.5, tint);
}
