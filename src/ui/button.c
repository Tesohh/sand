#include "game/game.h"
#include "raylib.h"
#include "ui.h"
#include <stdlib.h>
#include <string.h>

void DrawButton(ui_button_t button) {
    if (button.game == NULL) {
        TraceLog(LOG_ERROR, "button drawn without game");
        return;
    }

    bool hovered = IsHovered(button.rect, button.game->camera);

    DrawBorderRect(button.rect, 0.1, button.state == BUTTON_SELECTED, button.tint, button.tint);
    DrawCenteredText(button.rect, button.text, button.text_size, button.text_tint);

    if (hovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawRectangleRec(button.rect, GetColor(0x00000055));
    } else if (hovered && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        if (button.fn != NULL) {
            char* id = button.id;
            if (strlen(button.id) == 0)
                id = button.text;

            button.fn(button.game, id);
        }
    } else if (hovered) {
        DrawRectangleRec(button.rect, GetColor(0xFFFFFF55));
    }
}
