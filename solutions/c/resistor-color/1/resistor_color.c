#include "resistor_color.h"

#include <stdlib.h>

int color_code(const resistor_band_t color) {
    return color;
}

const resistor_band_t* colors() {
    resistor_band_t *colors = malloc((WHITE+1)*sizeof(colors[0]));

    for(resistor_band_t i = BLACK; i <= WHITE; i++) {
        colors[i] = i;
    }

    return colors;
}