#ifndef ELEMENT_H
#define ELEMENT_H

#include <stdint.h>

typedef enum ElementID { ELEMENT_NOTHING,
                         ELEMENT_TUBRONIUM,
                         ELEMENT_END } element_id;

#define ELEMENTS_LEN 2

typedef struct Element {
    uint64_t halflife; // ticks     (0 = never decay)
    int64_t gravity;   // px / tick (0 = static)
} element_t;

element_t* element_get_list(void);
#endif
