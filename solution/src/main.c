#include <stdio.h>
#include <stdlib.h>

#include "../include/error_utils.h"

void usage() {
    fprintf(stderr, "Incorrect amount of arguments\n");
}

int main(int argc, char**argv) {
    if (argc != 3) usage();
    if (argc < 3) fprintf(stderr, "Less tha 3 arguments");
    if (argc > 3) fprintf(stderr, "More tha 3 arguments");
    struct image image = {0};
    enum open_status input_status = read_bmp(argv[1], &image);
    if (input_status != READ_OK) {
        fprintf(stderr, "Program closed with error: %s\n", read_error(input_status));
        return 1;
    }
    struct image output_image = rotate(&image);
    free(image.data);
    enum close_status output_status = save_bmp(argv[2], &output_image);
    if (output_status == WRITE_OK) fprintf(stderr, "%s\n", write_error(output_status));
    else {
        fprintf(stderr, "Program closed with error: %s\n", write_error(output_status));
        return 2;
    }
    free(output_image.data);
    return 0;
}
