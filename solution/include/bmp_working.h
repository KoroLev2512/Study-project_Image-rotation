#ifndef SOLUTION_BMP_WORKING_H
#define SOLUTION_BMP_WORKING_H

#include "bmp_header.h"

enum open_status {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_NO_FILE,
    READ_ERROR
};

enum close_status {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum open_status read_bmp(char *input, struct image *image);
enum close_status save_bmp(char *input, struct image const *image);

#endif
