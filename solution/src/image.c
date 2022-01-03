#include <stdlib.h>

#include "../include/image.h"

static void set_new_data(struct pixel *data, struct image const *image) {
    for (size_t width = 0; width < image -> width; width++) {
        for (size_t height = 0; height < image -> height; height++) {
            data[width * image -> height + (image -> height - height - 1)] = image -> data[width + image -> width * height];
        }
    }
}

struct image rotate(struct image const *image) {
    struct image new_image = {.width = image -> height, .height = image -> width};
    struct pixel *data = malloc(image -> height * image -> width * sizeof(struct pixel));
    set_new_data(data, image);
    new_image.data = data;
    return new_image;
}
