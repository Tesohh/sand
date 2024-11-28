#include "raylib.h"
#include "ui.h"

bool IsHovered(Rectangle rect, Camera2D camera) {
    if (!IsCursorOnScreen())
        return false;

    Vector2 screenMousePosition = GetMousePosition();
    Vector2 mousePosition = GetScreenToWorld2D(screenMousePosition, camera);

    bool xMatch = mousePosition.x >= rect.x && mousePosition.x <= rect.x + rect.width;
    bool yMatch = mousePosition.y >= rect.y && mousePosition.y <= rect.y + rect.height;

    return xMatch && yMatch;
}
