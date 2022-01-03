#include <stdio.h>
#include <stdlib.h>

#include "../include/bmp_working.h"

static uint8_t image_padding(struct image const *image) {
    return image -> width % 4;
}

static struct bmp_header new_header(struct image const *image) {
    struct bmp_header header = {
            .bfType =  BF_TYPE,
            .bfileSize = sizeof(struct bmp_header) + image_padding(image) *  image -> height,
            .bfReserved = 0,
            .bOffBits = sizeof(struct bmp_header),
            .biSize = 40,
            .biWidth = image -> width,
            .biHeight = image -> height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = image -> height * (image -> width + image_padding(image)),
            .biXPelsPerMeter = 0,
            .biYPelsPerMeter = 0,
            .biClrUsed = 0,
            .biClrImportant = 0
    };
    return header;
}

enum open_status read_status(FILE *in_file, struct image *image) {
    struct bmp_header header = {0};
    fread(&header, sizeof(struct bmp_header), 1, in_file);
    if (header.bfType != BF_TYPE) return READ_INVALID_SIGNATURE;
    image -> height = header.biHeight;
    image -> width = header.biWidth;
    const uint8_t padding = image_padding(image);
    struct pixel *data = malloc(image -> height * image -> width * sizeof(struct pixel));
    for (size_t i = 0; i < image -> height; i++) {
        size_t counter = fread (&(data[i * image -> width]), sizeof(struct pixel), image -> width, in_file);
        if (!counter) return READ_ERROR;
        fseek(in_file, padding, SEEK_CUR);
    }
    image -> data = data;
    return READ_OK;
}

enum open_status read_bmp(char *input, struct image *image) {
    FILE *in_file = fopen(input, "rb");
    if (!in_file) return READ_NO_FILE;
    enum open_status status = read_status(in_file, image);
    return status;
}

enum close_status write_status(FILE *out_file, struct image const *image) {
    struct bmp_header header = new_header(image);
    fwrite(&header, sizeof(struct bmp_header), 1, out_file);
    const uint8_t padding = image_padding(image);
    const uint32_t padd_bytes = 0;
    for (size_t i = 0; i < image -> height; i++) {
        size_t write_data = fwrite(&image -> data[i * image -> width], sizeof(struct pixel), image -> width, out_file);
        if (!write_data) return WRITE_ERROR;
        fwrite(&padd_bytes, 1, padding, out_file);
    }
    return WRITE_OK;
}

enum close_status save_bmp(char *output, struct image const *image) {
    FILE *out_file = fopen(output, "wb");
    enum close_status status = write_status(out_file, image);
    return status;
}
