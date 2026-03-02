// Merge two sorted arrays — Two‑pointer technique.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* mergetwosorted_arrays(int* nums1, int nums1size, int * nums2, int nums2size){

// first let's put some storage to the resultant merged array
int * merged_array = (int*) malloc((nums1size + nums2size) * sizeof(int));

// Compare
// To compare, we will have i = left, r = right, k = for iterating thru merged
int i = 0;
int j = 0;
int k = 0;

while(i < nums1size && j < nums2size) {
// compare
if(nums1[i] <= nums2[j]) {
    merged_array[k++] = nums1[i++];
}
else{
merged_array[k++] = nums2[j++];
}
}

// Now what if i is equal to nums1 size and still j is left?
while(i < nums1size) {
    merged_array[k++] = nums1[i++];
}
while(j < nums2size) {
    merged_array[k++] = nums2[j++];
}
return merged_array;
}

int main() {
    int nums1[] = {1, 3, 5, 7};
    int nums2[] = {2, 4, 6, 8};
    int nums1size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2size = sizeof(nums2) / sizeof(nums2[0]);

    int* merged_array = mergetwosorted_arrays(nums1, nums1size, nums2, nums2size);
    int merged_size = nums1size + nums2size;

    printf("Merged array: ");
    for (int i = 0; i < merged_size; i++) {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    free(merged_array); // Don't forget to free the allocated memory
    return 0;
}

