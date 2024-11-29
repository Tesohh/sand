#include "utils.h"
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

// function assumes points has already been allocated for enough
// Vector2* util_get_circle_as_vector2s(Vector2 center, int radius, Vector2* points) {
//     // Calculate the size of the bounding box
//     int diameter = radius * 2 + 1;
//
//     // Allocate memory for points (worst-case allocation)
//     Vector2* points = malloc(diameter * diameter * sizeof(Vector2));
//     int count = 0;
//
//     // Iterate over the bounding box
//     for (int y = -radius; y <= radius; y++) {
//         for (int x = -radius; x <= radius; x++) {
//             // Check if the point lies within the circle
//             if (x * x + y * y <= radius * radius) {
//                 points[count++] = (Vector2){((int)center.x) + x, ((int)center.y) + y};
//             }
//         }
//     }
//
//     // Return the array of points
//     return points;
// }

Rectangle util_rect_from_radius(Vector2 center, float radius) {
    return (Rectangle){
        .x = round(center.x - radius),
        .y = round(center.y - radius),
        .width = round(radius * 2),
        .height = round(radius * 2),
    };
}

void DebugRectangle(Rectangle r, char* prefix) {
    TraceLog(LOG_INFO, "%s x=%f y=%f width=%f height=%f", prefix, r.x, r.y, r.width, r.height);
}
