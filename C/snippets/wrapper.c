#include <stdio.h>
#include <stdlib.h> // For malloc and free functions
/*
void* malloc(size_t size);
void free(void* ptr, size_t size);
Please Implement the wrapper functions:
void* my_malloc(size_t size) and void my_free(void* ptr).
Your implementation of my_free must correctly deallocate memory using the system free, even though it does not take a size argument directly.
*/

/*
 * Note : The standard free function in C does not take a size argument, it only takes a pointer to the memory that needs to be deallocated.
          This program will crash, because the free function is being called with two arguments, which is not the correct usage of the free function.
*/


void* my_malloc(size_t size) {
    //size_t_size = sizeof(size_t);
    size_t*start_address = (size_t*) malloc(size + sizeof(size_t));
    // Allocate an extra byte for storing the size of the allocated memory
     
    // Store the size of the allocated memory at the beginning of the allocated block
    *start_address = size;
    printf("Allocated memory of size: %zu bytes\n", size);

    return (void*)(start_address + 1);
    // You have to do start_address + 1 instead of start_address + sizeof(size_t) 
    // because start_address is a pointer to size_t, 
    // so adding 1 will move the pointer by the size of one size_t, 
    // which is exactly the extra byte we allocated for storing the size.
    // Doing +sizeof(size_t) would move the pointer by the sizeof(size_t) * sizeof(size_t), which is not what we want. 
}

void my_free(void* ptr) {
    if(ptr == NULL) {
        printf("Pointer is NULL, nothing to free\n");
        printf("Pointer does not point to any allocated memory\n");
        return;
    }

    size_t* start = (size_t*)ptr -1; // This is the address of the size that we stored at the beginning of the allocated block, which is one size_t before the pointer that was returned by my_malloc.
    size_t size_of_buffer = *(start); // This retrieves the size of the allocated memory that we stored at the beginning of the allocated block.

    printf("Freed size : %zu bytes\n", size_of_buffer);
    free(start,size_of_buffer + sizeof(size_t)); //  because we need to free the entire block of memory that was allocated by my_malloc, which includes the size of the buffer plus the extra byte that was allocated for storing the size.
    // **Note :** This free(start,size_of_buffer + sizeof(size_t)) is not the standard free function, it is a custom free function that takes two arguments, the pointer to the start of the allocated block and the size of the allocated block.
    return;
    // You have to free the size_of_buffer plus the extra byte that was allocated for storing the size
}

int main() {
    // Use my_malloc to allocate memory for an integer. 
    
    void* ptr2 = my_malloc(100); 
    // Example usage of my_malloc to allocate memory for a buffer of 100 bytes. 
    // so if sizeof(size_t) is 8 bytes, then the total allocated memory will be 108 bytes 
    // (100 bytes for the buffer + 8 bytes for storing the size).
    
     
    // Now in these 100 bytes, you can store any data you want, 
    // for example,
    // you can cast the pointer to an integer pointer and store an integer value in it.
    

    int* ptr = (int*)ptr2; // This basically casts the void pointer returned by my_malloc to an integer pointer, so that we can point to an integer value in the allocated memory.
    *ptr = 42; // This assigns the value 42 to the memory location pointed to by ptr, which is the memory allocated by my_malloc.    

    *(ptr + 1) = 84; // This assigns the value 84 to the memory location that is one integer size away from the location pointed to by ptr.
                     // Since ptr is an integer pointer, 
                     // adding 1 to it will move the pointer by the size of one integer (4 bytes on most systems), 
                     // so this will store the value 84 in the next 4 bytes of the allocated memory after the integer 42.
    
    *(ptr + 3) = 168; // This assigns the value 168 to the memory location that is three integer sizes away from the location pointed to by ptr.
                      // Since ptr is an integer pointer, 
                      // adding 3 to it will move the pointer by the size of three integers (12 bytes on most systems), 
                      // so this will store the value 168 in the next 12 bytes of the allocated memory after the integer 42.
                      // But, we did not assign *(ptr + 2) = some value, 
                      // so the memory location that is two integer sizes away from the location pointed to by ptr will contain garbage value.
                      // Will the garbage value be an integer or a float or a character?
                      // The garbage value can be anything, it depends on what was previously stored in that memory location.
                      
    // So now at this point we have allocated memory for 100 bytes, and we have stored the integer values 42, 84, and 168 in the first, second, and fourth integer positions of that allocated memory respectively.
    // The memory layout of the allocated memory will look something like this:
    // | 42 (4 bytes) | 84 (4 bytes) | garbage value (4 bytes) | 168 (4 bytes) | ... (remaining bytes) |
    // And the total allocated memory is 108 bytes (100 bytes for the buffer + 8 bytes for storing the size), 
    // so we have 108 - 16 = 92 bytes of remaining memory that can be used to store other data if needed.
    // The garbage value can be anything, it depends on what was previously stored in that memory location.
    // The user readily sees the values 42, 84, and 168 in the allocated memory, but the garbage value is not visible to the user and can be anything, it depends on what was previously stored in that memory location.
    // Let's print out the values stored in the allocated memory to verify that they are correct.
    //
    //
    //
    *(ptr + 99) = 178;
    
    for(int i = 0; i < 100 ; i++) {
        printf("Value at ptr + %d: %d\n", i, *(ptr + i));
    }


    // Doing something undefined.
    printf(" Doing something undefined by accessing memory beyond the allocated buffer...\n"); 
    printf("Value at ptr + 100: %d before assigning anything to ptr+100\n", *(ptr + 100)); 

    printf("Assiging value to memory location beyond the allocated buffer...\n");
    printf("i.e, Assigning value to ptr + 100 as 256\n");
    *(ptr + 100) = 256; // This is undefined behavior, because we are trying to access memory that is beyond the allocated buffer. 
                          // The allocated buffer is only 100 bytes, which can hold 25 integers (assuming 4 bytes per integer), so the valid indices for ptr are from 0 to 24. 
                          // Accessing ptr + 100 is trying to access memory that is 100 integers away from the start of the allocated buffer, which is definitely beyond the allocated memory and can lead to undefined behavior, such as crashing the program or corrupting data.
    printf("After assigning value to memory location beyond the allocated buffer...\n");
    printf("(After assigning) Value at ptr + 100: %d\n", *(ptr + 100)); // This is also undefined behavior, because we are trying to access memory that is beyond the allocated buffer. 
                                                     // The value at ptr + 100 can be anything, it depends on what was previously stored in that memory location, and it can lead to undefined behavior, such as crashing the program or corrupting data.


    if(ptr == NULL)  {
        printf("Memory allocation failed\n");
        return -1;
    }
    
    // Use my_free to deallocate the memory. 
    my_free(ptr);

    // After calling my_free, the memory that was allocated by my_malloc is deallocated, 
    // and the pointer ptr becomes a dangling pointer, 
    // which means it still points to the same memory location, 
    // but that memory location is no longer valid and can be reused by other parts of the program.
    // So a dangling pointer is a pointer that points to a memory location that has been deallocated, 
    // but its value itself will be the address of the memory location that was allocated by my_malloc,
    // But accessing the memory through a dangling pointer can lead to undefined behavior, such as crashing the program or corrupting data, because the memory location that the pointer points to is no longer valid and can be reused by other parts of the program.
    // But in some cases, it can seem like the program is still working and not crashing, even though we are trying to access memory that has been freed, because the memory location that the pointer points to may not have been reused yet by other parts of the program, so it may still contain the same data that was stored there before it was freed.
    // So, freeing the memory does not immediately erase the data that was stored there, it just marks that memory location as available for reuse by other parts of the program.
    // Whereas, allocating memory using my_malloc will reserve a block of memory and return a pointer to the beginning of that block, and the data stored in that block will remain there until it is explicitly deallocated using my_free, or until the program terminates.
    // And other parts of the program cannot access that memory until it is deallocated, 
    // but once it is deallocated,
    // other parts of the program can reuse that memory location for their own purposes, 
    // which can lead to undefined behavior if we try to access the memory through a dangling pointer after it has been deallocated.

    // Why does the following lines of code not cause a crash or undefined behavior, even though we are trying to access memory that has been freed?

    printf("Memory deallocated successfully\n");
    printf("The value of the pointer after freeing the memory: %p\n", ptr); // This will print the value of the pointer after freeing the memory, which is still the same as before, because we did not set it to NULL after freeing the memory.
    // It is a good practice to set the pointer to NULL after freeing the memory, to avoid dangling pointers and potential undefined behavior if we try to access the pointer after it has been freed.
    
    // But printing the value of the pointer after freeing the memory is not undefined behavior, because we are not trying to access the memory that the pointer points to, we are just printing the value of the pointer itself, which is still valid even after freeing the memory.

    printf("The value pointed by the pointer after freeing the memory: %d\n", *ptr); // This is undefined behavior, because we are trying to access memory that has been freed. 
    // After freeing the memory, the pointer becomes a dangling pointer, which means it still points to the same memory location, but that memory location is no longer valid and can be reused by other parts of the program. 
    // Accessing *ptr after freeing the memory can lead to undefined behavior, such as crashing the program or corrupting data.
    
    printf("The value at ptr + 1 after freeing the memory: %d\n", *(ptr + 1)); // This is also undefined behavior, because we are trying to access memory that has been freed.
    printf("The value at ptr + 100 after freeing the memory: %d\n", *(ptr + 100)); // This is also undefined behavior, because we are trying to access memory that has been freed.
    return 0;
}
