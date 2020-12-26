#include "bmp.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>

#define PRI_SPECIFIER(e) (_Generic( (e), uint16_t : "%" PRIu16, uint32_t: "%" PRIu32, default: "NOT IMPLEMENTED" ))

#define PRINT_FIELD( t, name ) \
    fprintf( f, "%-17s: ",  # name ); \
    fprintf( f, PRI_SPECIFIER( header-> name ) , header-> name );\
    fprintf( f, "\n");


void bmp_header_print( struct bmp_header const* header, FILE* f ) {
   FOR_BMP_HEADER( PRINT_FIELD )
}

static bool read_header( FILE* f, struct bmp_header* header ) {
    return fread( header, sizeof( struct bmp_header ), 1, f );
}

bool read_header_from_file( const char* filename, struct bmp_header* header ) {
    if (!filename) return false;
    FILE* f = fopen( filename, "rb" ); 
    if (!f) return false;
    if (read_header( f, header ) ) {
        fclose( f );
        return true; 
    }

    fclose( f );
    return false;
}

