#include "element.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

element_t* element_get_list(void) {
    element_t* elements = malloc(sizeof(element_t) * ELEMENTS_LEN);

    elements[ELEMENT_NOTHING] = (element_t){.halflife = 0, .gravity = 0};
    elements[ELEMENT_TUBRONIUM] = (element_t){.halflife = 100, .gravity = 10, .color = {255, 128, 255, 255}};

    return elements;
}
