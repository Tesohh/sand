#ifndef UTILS_H
#define UTILS_H

#include <raylib.h>
#include <stddef.h>

Rectangle util_rect_from_radius(Vector2 center, float radius);
Vector2* util_get_circle_as_vector2s(Vector2 center, float radius);

void DebugRectangle(Rectangle r, char* prefix);
#endif
