#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Binary search (iterative + recursive) — Classic must‑know.
// what exactly is binary search? how does it work? how to implement it? what are the time and space complexities? when to use it?
// Binary search is a search algorithm that finds the position of a target value within a sorted array. 
// It works by repeatedly dividing the search interval in half. 
// If the value of the search key is less than the item in the middle of the interval, it continues searching in the lower half, or if it is greater, it continues searching in the upper half. This process continues until the value is found or the interval is empty.
// The time complexity of binary search is O(log n) and the space complexity is O(1) for the iterative version and O(log n) for the recursive version due to the call stack.

int binary_search(int* sorted_array, int size, int target_value) {
    // Find the midpoint
    int mid_point = size / 2;
    if(sorted_array[mid_point] == target_value) {
        printf("Target value found at index %d\n", mid_point);
        return mid_point;
    }
    // Left side
    if(target_value < sorted_array[mid_point]) {
        printf("Entered left side\n");
        return binary_search(sorted_array, size-mid_point, target_value);
    }

    // Right side
    if(target_value > sorted_array[mid_point]){
        printf("Entered right side\n");
        // Need to adjust index.
        int result = binary_search(sorted_array+mid_point+1, size-mid_point-1, target_value);
        if(result < 0){ return -1;}
        return mid_point + result + 1;
    }
    return -1;
}

int main(){
    int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target_value = 5;
    printf("Attempting to find target value %d in the sorted array...\n", target_value);
    printf("The original array is [");
    for(int i = 0; i < size; i++){
        printf(", %d", sorted_array[i]);
    }
    printf("]\n"); 
    int result = binary_search(sorted_array, size, target_value);

    if(result != -1){
        printf("Target value %d found at index %d\n", target_value, result);
    }
    else{
        printf("Target value %d not found in the array\n", target_value);
    }
}
