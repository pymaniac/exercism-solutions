#ifndef DARTS_H
#define DARTS_H
#include <stdint.h>

typedef struct coordinate_t coordinate_t;
struct coordinate_t {
    float x;
    float y;
};

uint8_t score(coordinate_t pos);
#endif
