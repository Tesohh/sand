#ifndef ELEMENT_H
#define ELEMENT_H

#include <raylib.h>
#include <stdint.h>

typedef enum ElementID { ELEMENT_NOTHING,
                         ELEMENT_TUBRONIUM,
                         ELEMENT_END } element_id;

#define ELEMENTS_LEN 2

typedef struct Element {
    // chemical properties
    uint64_t halflife;    // ticks (0 = never decay)
    int64_t solid_point;  // kelvin
    int64_t liquid_point; // kelvin
    int64_t gas_point;    // kelvin

    // physical properties
    int64_t gravity; // px / tick (0 = static)
    int8_t min_sway; // px
    int8_t max_sway; // px

    // view properties
    Color color;
} element_t;

element_t* element_get_list(void);
#endif
