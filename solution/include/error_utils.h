#ifndef SOLUTION_ERROR_UTILS_H
#define SOLUTION_ERROR_UTILS_H

#include "bmp_working.h"

const char *read_error(enum open_status status);

const char *write_error(enum close_status status);

#endif
