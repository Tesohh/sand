#ifndef UI_H
#define UI_H

#include "game/game.h"
#include <raylib.h>
typedef enum UIButtonState {
    BUTTON_ENABLED,
    BUTTON_DISABLED,
    BUTTON_SELECTED,
} ui_button_state;

typedef struct UIButton {
    Rectangle rect;
    char* text;
    char* id;
    Color tint;
    Color text_tint;
    float text_size;
    ui_button_state state;
    void (*fn)(game_t*, char*); // fns will be called with the global game and the id of the button (if it's empty it will pass the name)
    game_t* game;
} ui_button_t;

void DrawBorderRect(Rectangle rect, float border_width, bool filled, Color tint, Color border_tint);
void DrawCenteredText(Rectangle rect, char* text, float font_size, Color tint);
void DrawButton(ui_button_t button);

bool IsHovered(Rectangle rect, Camera2D camera);
#endif
