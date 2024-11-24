#ifndef GRAIN_H
#define GRAIN_H

#include "element/element.h"

typedef enum GrainState {
    NORMAL,
} grain_state;

typedef struct Grain {
    element_id id;
    uint64_t lifetime;
    grain_state state;
} grain_t;

#endif
