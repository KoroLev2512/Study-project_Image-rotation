#include "../include/error_utils.h"

const char *open_messages[] = {
        [READ_INVALID_SIGNATURE] = "Invalid type of file",
        [READ_NO_FILE] = "No file found",
        [READ_ERROR] = "An error with reading file"
};

const char *read_error(enum open_status status) {
    return open_messages[status];
}

const char *close_messages[] = {
        [WRITE_OK] = "Rotated successfully",
        [WRITE_ERROR] = "An error with saving file"
};

const char *write_error(enum close_status status) {
    return close_messages[status];
}
