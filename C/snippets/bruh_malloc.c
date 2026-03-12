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
    enum chunk_state chunk_state;
} metadata;

//[header- metadata : size_of_chunk, is_used | size of chunk ]
//

// Lets add footer, because to go back you need some metadata?

typedef metadata header;  // for header
typedef metadata footer;  // for footer

void* heap_start;

void* bruh_malloc(size_t size){

    // Store the metadata.
    header* h = sbrk(sizeof(header));
    h->size_of_chunk = size;
    h->chunk_size = USED; 
    
    // Next.
    void* ptr = sbrk(size);  // sbrk increments the heap end by size but returns the pointer to the old heap end.
    // Increment the space after the data segment by size.(increment the heap size by size)
    // Now after the chunk has finished being allocated also, we add a footer.
    footer* f = sbrk(sizeof(footer));
    f->size_of_chunk  =  h->size_of_chunk;
    f->chunk_state = h->chunk_state;
    

    return ptr; // Ptr does not include the metadata. 
}

// Basic aah coalescing 


void* fw_coalescing(void* chunk1) {

    // (Forward coalescing -> Merging with the next chunk)
    // 1. The current chunk is freed.
    // 2. The next chunk by its header is also not unused.
    // 3. So basically, you can combine both.
    // 4. Which means, size = existing_size+ footersize(chunk1) + sizeof(header) + sizeof(next_header). And modfitying 
    // 5. The current header to size = size1 + size2. And is_used = FREE;
    // 6. And yes, that's it?

    // First check if the current chunk is freed.

    // 1. Get the next chunk
    header* chunk1 =  (header*) chunk1;

    header* next_chunk_header = &(chunk1[chunk1->size_of_chunk + sizeof(footer)]);
    // Next_chunk is pointer to the header of the next_chunk.

    header *chunk1_header = (header*)chunk1 - sizeof(header);


    // 2. Check if coalesc is possible.
    if((chunk1_header->chunk_state == USED ) && (next_chunk->chunk_state == USED) {
        printf("Bruh.This chunk or the next chunk is still in use! Cannot coalesc!");
        return NULL;
    }

    // 3. At this point coalesc is possible, 
    // 3. use brk or sbrk. Ok why do you need brk or sbrk. Do not require this.
    //chunk1->size_of_chunk = chunk1->size_of_chunk + sizeof(next_chunk's header) + next_chunk->size_of_chunk;  
    chunk1_header->size_of_chunk = chunk1_header->size_of_chunk + sizeof(footer) + sizeof(header) + next_chunk_header->size_of_chunk;  

    // How to get teh next_chunk's header size.
    // I know it is basically sizeof(header)

    chunk1_header->chunk_state= FREE;

    // Get the chunk1's new footer.
    footer* chunk1_footer = &(chunk1[chunk1_header->size_of_chunk]);
    chunk1_footer->size_of_chunk = (chunk1_header->size_of_chunk);
    chunk1_footer->footer = chunk1_header->chunk_state;

    // Now just return the pointer to the bin (chunk1 + next_chunk).

    return (void*)chunk1;


}

// TODO : Interfaces for getting to the header and footers.

void* bw_coalescing(void* chunk) {

// Backward coalescing.
// Which means merging with the previous chunk.
// 1. The current chunk is free and previous chunk is also free

// 1. Get the headers and footers of the current chunk.

header* chunk = (header*) chunk;


header* chunk_header  = chunk - sizeof(header);
footer* chunk_footer = (footer*)(chunk + (chunk_header->size_of_chunk));


// 2. Get the headers and footers of the next chunk.

footer* prev_chunk_footer  =  (footer*)chunk - sizeof(header);
// To-do can you not just use generic sizeof(header).
// Instead do something like sizeof(*chunk_header)

header* prev_chunk_header = (header*)prev_chunk_footer - (prev_chunk_footer->size_of_chunk);


//3. Now, check if backward coalesc is possible.

if((chunk_header->chunk_state != FREE) && (prev_chunk_header->chunk_state != FREE)){
        printf("Bruh.This chunk or the prev chunk is still in use! Cannot coalesc!");
        return NULL;
}

    // Now what. Both of them are free.
    // You should combine these two
    prev_chunk_header->size_of_chunk = (prev_chunk_header->size_of_chunk) + sizeof(footer) + sizeof(header) + (next_chunk_header->size_of_chunk);
    prev_chunk_header->chunk_status = FREE;
    


    prev_chunk_footer->size_of_chunk = (prev_chunk_header->size_of_chunk);
    prev_chunk_header->chunk_status = FREE;

     return ((void*)prev_chunk_header + sizeof(prev_chunk_header));
}


// TO-do : can you do merge_two_chunks_atomic interface 











}



int main() {
    void*a = bruh_malloc(256);
}



























