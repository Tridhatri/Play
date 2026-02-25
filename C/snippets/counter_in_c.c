#include <stdio.h>

// There is no dictionary in C
// How do you return the corresponding frquency, like a key -value pair
//Arrays, structs, unions, enums
// Structs?
// struct counter { int element, int count}
// Arrays of struct counter is one way
// Let's do that.

// Ok I am defining a stuct of counter here.
//
//
// Goal : counter(array a) ->  return a counter struct
typedef struct counter_of_single_element {
    int element;
    int count;
} counter_of_single_element;



//typedef counter_of_single_element counter[len_of_nums];

// array of elemen


void* counter(int* nums, int len_of_nums){


    // First create an array of the stuct          

    // Do we initialise the counter.elements to something?
    // Garbage it is currently
    // IF I initalise the counter.element to some value but it will conflict with nums[elements].
    // 
    // So, we create an array of struct counter_of_single_element of size len_of_counter
    // But, we cannot create an array of struct in C without defining the size at compile time, right?
    // Why?
    // Because we need to know how much memory to allocate for the array of struct. 
    // We can use dynamic memory allocation to create an array of struct at runtime,
    // but we cannot define an array of struct with a variable size at compile time.
    // But how is it variable, I am defining it as len_of_counter which is equal to len_of_nums, which is the size of the input array.
    // So, we can use dynamic memory allocation to create an array of struct at runtime,
    // but we cannot define an array of struct with a variable size at compile time.
    // My question is that, can we define an array of struct with a variable size at compile time, if we know the size of the input array at compile time?
    // Yes, we can define an array of struct with a variable size at compile time if we know the size of the input array at compile time.
    // So, what is the problem in this code?
    // The problem is that we cannot define an array of struct with a variable size at compile time, even if we know the size of the input array at compile time.
    // Here, variable size is referring to the fact that the size of the input array is not known at compile time, but it is known at runtime.
    // HOW is it not known at compile time, if we are passing the size of the input array as an argument to the function?
    // The size of the input array is not known at compile time because it is passed as an argument to the function, and the function can be called with different sizes of input arrays at runtime.
    // So, we cannot define an array of struct with a variable size at compile time, even if we know the size of the input array at compile time, because the function can be called with different sizes of input arrays at runtime.
    // What exactly is runtime and compile time?
    // Compile time is the time when the code is being compiled, and runtime is the time when the code is being executed.
    // In this context, 
    // the size of the input array is not known at compile time because it is passed as an argument to the function, and the function can be called with different sizes of input arrays at runtime.
    // So, an argument to a function is not known at compile time because it can be different each time the function is called, and the function can be called with different sizes of input arrays at runtime.
    // Runtime applies to always the arguments to a function called from main? Is that true?
    // Yes, runtime applies to the arguments to a function called from main, 
    // because the arguments can be different each time the function is called, 
    // and the function can be called with different sizes of input arrays at runtime.
    // How to get around this problem of defining an array of struct with a variable size at compile time?
    // I believe in contrast, an array defined in main with a specific size is known at compile time, because it is defined with a specific size in the code, and it cannot be changed at runtime.
    // So, we can define an array of struct with a variable size at compile time if we know the size of the input array at compile time, but we cannot define an array of struct with a variable size at compile time if we do not know the size of the input array at compile time, because the function can be called with different sizes of input arrays at runtime.
    //
    //
    // In contrast, can we do this func(int a)  and inside func, we do someting like int array[a] , and in main, int a = 5, and then call func(a)? 
    //  Is that true? No, that is not true, because the value of a can be changed at runtime, and the function can be called with different values of a at runtime, so we cannot define an array of struct with a variable size at compile time if we do not know the size of the input array at compile time, because the function can be called with different sizes of input arrays at runtime.
    //
    //
    // So, we can use dynamic memory allocation to create an array of struct at runtime, but we cannot define an array of struct with a variable size at compile time, even if we know the size of the input array at compile time, because the function can be called with different sizes of input arrays at runtime.
    
    // Can be modified as using malloc to create an array of struct at runtime
    


    int len_of_counter = len_of_nums; // worst case, all elements are different, so we need len(nums) space for counter

    counter_of_single_element *counter = (counter_of_single_element *)malloc(sizeof(counter_of_single_element) * len_of_counter);
    // malloc function signature is void* malloc(size_t size);
    // malloc allocates a block of memory of the specified size and returns a pointer to the beginning of the block.

    // So now we have a pointer to the array of struct counter_of_single_element, and we can use this pointer to access the elements of the array and populate it with the counts of the elements in the input array.

    // Layout
    //
    // counter array will have len(nums) elements in it.
    // each element of this array is a struct representing the element, count
    //
    //
    
    // before doing anything we need to actually set the count of each element in the counter array to 0, 
    // because we will be incrementing the count as we find the elements in the input array, so we need to initialize the count to 0 for each element in the counter array. 
    // Otherwise, we will be incrementing the count of uninitialized elements in the counter array, which will lead to incorrect counts for the elements in the input array.
    // Cuz, Garbage values in the count field of the counter array.
    // Can we do it directly at malloc stage?
    // No, we cannot initialize the count field of the counter array directly at the malloc stage, because malloc only allocates memory and does not initialize it.
    // Alternative to initalise it to all 0 ? calloc? 
    // Yes, we can use calloc to allocate memory and initialize it to 0. The calloc function has the following signature: void* calloc(size_t num, size_t size);
    //
    //
    //For now, we will initialize the count field of the counter array to 0 using a loop after allocating memory with malloc, and we can modify the code later to use calloc for better performance and cleaner code.
    

    for(int i = 0; i < len_of_counter; i++){
        counter[i].count = 0;
    }


   for(int i = 0; i < len_of_nums; i++){
    // int * nums is an array 
    // So, count the elements
    // Actually first populate the counter with the elements according to the nums array
    // So, 
    int to_find = (int)*(nums+i);
    // if *(nums+i) already there in counter[].element, then increase the counter[].count
    //
    //
    

    if(counter[i].element == to_find){
        // We have found the element already in the counter
        // WE increase the counter by 1
        counter[i].count++;
    }
    else{
        // We did not find the element, so we make space and allot it
        counter[i].element = to_find;
        counter[i].count++;
    }
   }

// counter is the pointer to the array, which is basically the array itself, 
// so we can return the pointer to the array of struct counter_of_single_element, 
// and the caller can use this pointer to access the elements of the array and get the counts of the elements in the input array.
//
   return counter;
}


int main(){

int nums[] = {1,2,2,3,3,3, 4};
int len_of_nums = (int)sizeof(nums)/sizeof(int);
counter_of_single_element *counter_result = counter(nums, len_of_nums);
// counter_result is a pointer to the array of struct counter_of_single_element, which is basically the array itself,
// so we can use this pointer to access the elements of the array and get the counts of the elements in the input array.
// Displaying the counter_result
for(int i = 0; i < len_of_nums; i++){
    printf("Element: %d, Count: %d\n", (counter_result[i]).element, (counter_result[i]).count);
}

};
