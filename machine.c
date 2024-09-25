#include <stdio.h>
#include <stdlib.h>

//a size for the memory(2^16 words = 32k words)
#define MEMORY_SIZE_IN_WORDS 32768

//Reads the binary object file
unsigned char* read_file(const char *fileName, long *fileSize) {

    // opens the binary object file
    FILE *file = fopen(fileName, "rb");
    //file cant be open
    if(file == NULL) {
        return NULL;
    }

    //find the size of the file
    fseek(file, 0, SEEK_END);
    //getting the file size
    *fileSize = ftell(file);
    //return the file pointer to the beginning
    rewind(file);

    unsigned char *buffer = (unsigned char *) malloc(*fileSize);
    //if the memory allocation fails
    if(buffer == NULL) {
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, *fileSize, file);
    //memory allocation fails
    if(bytes_read != *fileSize) {
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    //returns the contents of the file
    return buffer;

}




/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */