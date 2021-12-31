#ifndef SOLUTION_IMAGE_H
#define SOLUTION_IMAGE_H

#include <stdint.h>

struct pixel {
    uint8_t b, g, r;
};

struct image {
    uint32_t width, height;
    struct pixel *data;
};

struct image rotate(struct image const *image);

#endif
