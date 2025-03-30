#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h>
#include <stdlib.h>

// Enum to define compiler states
enum {
    COMPILER_FILE_COMPILED_OK, 
    COMPILER_FAILED_WITH_ERRORS
};


struct compile_process {
    // Como o arquivo deve ser compilado
    int flags;

    struct compile_process_imput_filet{
    FILE* fp;
    const char* abs_path;
    } cfile;

    FILE* ofile;

};



// Function declarations
int compile_file(const char* filename, const char* out_filename, int flags);
struct compile_process* compile_process_create(const char* filename, const char* filename_out, int flags);

#endif  // End of COMPILER_H





