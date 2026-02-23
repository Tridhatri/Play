#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 10 // The maximum number of elements the buffer can hold

typedef struct {
    unsigned char buffer[BUFFER_SIZE];
    int head; // Index where the next data will be written
    int tail; // Index where the next data will be read from
    int count; // Current number of items in the buffer
} CircularBuffer;

// Function Prototypes
void init_buffer(CircularBuffer *cb);
bool buffer_push(CircularBuffer *cb, unsigned char data);
bool buffer_pop(CircularBuffer *cb, unsigned char *data);
bool buffer_is_full(CircularBuffer *cb);
bool buffer_is_empty(CircularBuffer *cb);

// Initialize the buffer
void init_buffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if the buffer is full
bool buffer_is_full(CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

// Check if the buffer is empty
bool buffer_is_empty(CircularBuffer *cb) {
    return cb->count == 0;
}

// Insert data into the buffer
bool buffer_push(CircularBuffer *cb, unsigned char data) {
    if (buffer_is_full(cb)) {
        return false; // Buffer is full, insertion failed
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
    return true; // Insertion successful
}

// Read data from the buffer
bool buffer_pop(CircularBuffer *cb, unsigned char *data) {
    if (buffer_is_empty(cb)) {
        return false; // Buffer is empty, pop failed
    }

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return true; // Pop successful
}

// Example usage in main function
int main() {
    CircularBuffer my_buffer;
    init_buffer(&my_buffer);

    // Push some data
    for (int i = 0; i < 5; i++) {
        if (!buffer_push(&my_buffer, (unsigned char)i + '0')) {
            printf("Buffer full when pushing %c\n", (char)(i + '0'));
        }
    }

    // Pop and print data
    unsigned char value;
    while (buffer_pop(&my_buffer, &value)) {
        printf("Popped value: %c\n", value);
    }
    
    // Attempt to pop from an empty buffer
    if (!buffer_pop(&my_buffer, &value)) {
        printf("Buffer is empty\n");
    }

    return 0;
}


