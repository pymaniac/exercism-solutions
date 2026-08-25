#include "darts.h"
#include <stdio.h>

uint8_t score(coordinate_t pos) {
    float r = (pos.x * pos.x) + (pos.y * pos.y);

    //printf("r = %f\n", r);
    
    if (r > 100.0) return 0;
    if (r > 25.0) return 1;
    if (r > 1.0) return 5;
    return 10;
}