#include <stdio.h>
#include <pthread.h>

#define SIZE 8

int arr[]     = {1, 2, 3, 4, 5, 6, 7, 8};
long results[SIZE];

void *factorial(void *arg) {
    int idx = *(int *)arg;
    int n   = arr[idx];

    long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;

    results[idx] = fact;
    return NULL;
}

int main() {
    pthread_t threads[SIZE];
    int indices[SIZE];

    for (int i = 0; i < SIZE; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, factorial, &indices[i]);
    }

    for (int i = 0; i < SIZE; i++)
        pthread_join(threads[i], NULL);

    for (int i = 0; i < SIZE; i++)
        printf("%d! = %ld\n", arr[i], results[i]);

    return 0;
}
