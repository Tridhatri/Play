#include <stdio.h>
#include <stdlib.h>

void* my_malloc(size_t size) {

    // allocate extra space for metadata
    size_t total_size = size + sizeof(size_t);

    // allocate
    size_t *start = malloc(total_size);
    if (!start) return NULL;

    // store size in first sizeof(size_t) bytes
    *start = size;

    // return pointer AFTER metadata
    return (void*)(start + 1);
}

void my_free(void* ptr) {

    if (!ptr) return;

    // move back to metadata
    size_t *real_ptr = (size_t*)ptr - 1;

    size_t stored_size = *real_ptr;

    printf("Freeing block of size: %zu\n", stored_size);

    free(real_ptr);
}

int main() {

    int *arr = my_malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
        arr[i] = i;

    my_free(arr);

    return 0;
}
