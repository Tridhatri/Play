// POSIX
// using sbrk and brk

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Define an enum for the state of the chunk (used or free).

enum chunk_state {
    USED = 0,
    FREE = 1
};

typedef struct metadata {
    uint32_t size_of_chunk;
    enum chunk_state is_free;
} metadata;

//[header- metadata : size_of_chunk, is_used | size of chunk ]

void* heap_start;

void* bruh_malloc(size_t size){

    // Store the metadata.
    metadata* mtdata = sbrk(sizeof(metadata));
    mtdata->size_of_chunk = size;
    mtdata->is_free = USED; 
    
    // Next.



    void* ptr = sbrk(size);  // sbrk increments the heap end by size but returns the pointer to the old heap end.
    // Increment the space after the data segment by size.(increment the heap size by size)
    return ptr;
}





int main() {
    void*a = bruh_malloc(256);
}

