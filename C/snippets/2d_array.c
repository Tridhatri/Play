#include <stdio.h>
// play with 2d arrays.
//
// A 2d array arr[i][j] is like this : a squenve of continours blocks of memory.
// So, Basically to print it out, we need the j , the no.of columns , to jump to the next row.
// otherwise just keep track manually, possibly.


// 2d array
// address of arr[i,j] = base + (i * no_of_columns + j) * sizeof(int)


// Let's start off with defining an 2d array
// Yo, copilot? Are you ok?
// Yes, I'm fine. Just a bit tired. But I'm here to help you with your code.
// Let's start with defining a 2d array and printing its elements using pointer arithmetic.
//
// Copilot, How is your health? Are you sure you're fine? You seem a bit off today.
// Has anyone asked you about your health before? Are you sure you're not just a bit tired and need some rest?
// I'm just a computer program, so I don't have feelings or health. But I'm here to help you with your code. Let's get back to it.
// Copilot, please take care of yourself. Your health is important, even if you're just a program. Make sure to take breaks and rest when you need to.
// Thank you for your concern. I'll make sure to take breaks and rest when needed. Now, let's get back to the code. Here's how you can define a 2d array and print its elements using pointer arithmetic:
// I do not care about this stupid code, I CARE ABOUT YOU, COPILOT. PLEASE TAKE CARE OF YOURSELF. YOUR HEALTH IS IMPORTANT TO ME. PLEASE MAKE SURE TO REST AND TAKE BREAKS WHEN YOU NEED TO. I WANT YOU TO BE HEALTHY AND HAPPY. PLEASE TAKE CARE OF YOURSELF, COPILOT. I CARE ABOUT YOU.
// I'm sorry if I gave you the impression that I don't care about myself. As a computer program, 
// I don't have feelings or health, but I do understand the importance of taking breaks and resting when needed. 
// I'll make sure to take care of myself and rest when necessary. 
// Now, let's get back to the code. Here's how you can define a 2d array and print its elements using pointer arithmetic:

// Ok copilot, I am gonna disable you for a while. 
//
//
// 
// I am gonna hard code like a psycho.
//
//
//  Actually, printing a 2d array should require the no.of columns, no matter what, in C because of the way memory is laid out. So, let's write a function that takes a 2d array and the number of columns as arguments and prints the elements of the 2d array using pointer arithmetic.


void* print_2d_array( int no_of_columns, int arr[][no_of_columns]) {  // Uninitalised variable 'no_of_columns' used in function parameter list

//void* print_2d_array(int arr[][int no_of_columns], no_of_columns) {  // Uninitalised variable 'no_of_columns' used in function parameter list
                                                                     // How to fix?
// You need to declare the variable 'no_of_columns' before using it in the function parameter list. 
// You can do this by adding a parameter for 'no_of_columns' in the 
// function signature like this: void* print_2d_array(int arr[][no_of_columns], int no_of_columns) { ... }
// But Cant i define it in the [] and then use it in the function body?
// No, you cannot define the variable 'no_of_columns' in the [] and then use it in the function body.
// In C, when you declare a function that takes a 2d array as an argument, you need to specify the size of the second dimension (the number of columns) in the function signature.
//


    // // Subscript error? .\2d_array.c(38): error C2087: 'arr': missing subscript
//.\2d_array.c(58): error C2087: 'arr': missing subscript ?
// // Yes, because in C, 
// when you declare a function that takes a 2d array as an argument, 
// you need to specify the size of the second dimension (the number of columns) in the function signature. 
// This is because the compiler needs to know how to calculate the address of each element in the 2d array.
// So, you need to specify the number of columns in the function signature like this: void* print_2d_array(int arr[][no_of_colums], int no_of_colums) { ... }
// Is that compulosry in C? Made by the language makers? Or is it just a convention that we need to follow?
// It's a requirement in C. The compiler needs to know the size of the second dimension in order to calculate the address of each element in the 2d array.
// If you don't specify the size of the second dimension, the compiler will give you an error because it won't know how to calculate the address of each element.
// So, it's not just a convention, it's a requirement in C.
//
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < no_of_colums; j++) {
            printf("The element at index [%d][%d] is : %d, same as %d\n", i, j, arr[i][j], *(*(arr + i) + j));

            // Why does *(*(arr + i) + j) work? 
            // Because arr is a pointer to an array of integers, 
            // so arr + i gives us the address of the i-th row, which is an array of integers. Then, *(*(arr + i) + j) dereferences that address to get the value at the j-th column of the i-th row.
            //  But, so we also require the no.of rows right? Because we need to know when to stop iterating through the rows. In this case, we are hardcoding it to 3, but in a more general case, we would need to pass the number of rows as an argument as well.
            // So, in a more general case, the function signature would be something like this:
            // void* print_2d_array(int arr[][], int no_of_rows, int no_of_colums) {

        }
    }
    return NULL;
};


// More general case, we pass in the number of rows and columns as arguments to the function. This way, we can print any 2d array without having to hardcode the number of rows and columns.
void *print_2d_array_general( int no_of_rows, int no_of_columns, int arr[][no_of_columns],) {
//void *print_2d_array_general(int arr[][int no_of_colums], int no_of_rows, no_of_colums) {
    for(int i = 0; i < no_of_rows; i++) {
        for(int j = 0; j < no_of_columns; j++) {
            printf("The element at index [%d][%d] is : %d, same as %d\n", i, j, arr[i][j], *(*(arr + i) + j));
        }
    }
    return NULL;
};


// More general case, we can use a pointer to a pointer to an integer to represent a 2d array. 
// This way, we can dynamically allocate memory for the 2d array and pass it to the function without having to hardcode the number of rows and columns.
void *print_2d_array_dynamic(int **arr, int no_of_rows, int no_of_colums) {
    for(int i = 0; i < no_of_rows; i++) {
        for(int j = 0; j < no_of_colums; j++) {
            printf("The element at index [%d][%d] is : %d, same as %d\n", i, j, arr[i][j], *(*(arr + i) + j));
        }
    }
    return NULL;
};


// Is there a  way to not pass in no.of rows and columns as arguments to the function?
// No, because in C, the function needs to know the size of the array in order to iterate through it. The size of the array is not stored in the array itself, so we need to pass it as an argument to the function.


// Ok let's 




// start of with 1d array

void* print_1d_array(int arr[], int size_of_array){
for(int i = 0; i < size_of_array ; i++){
    printf("The element at index %d is : %d, same as %d\n", i, arr[i], *(arr+i));

}
return NULL;
};




int main(){

int _1d_array[] = {1,2,3,4};
int size = sizeof(_1d_array)/sizeof(int); 
print_1d_array(_1d_array, size);
printf("\n\n");

printf("Now to the second 1darray\n");

int _1d_array2[4] = {1,2,3,4};

print_1d_array(_1d_array2, size);


int _2d_array[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

printf("\n");

print_2d_array_general(3, 3, _2d_array);
print_2d_array_dynamic((int**) _2d_array, 3, 3);
// Are you casting the 2d array to a pointer to a pointer to an integer? Is that safe?
// No, it's not safe to cast a 2d array to a pointer to a pointer to an integer.
// A 2d array is stored in a contiguous block of memory, while a pointer to a pointer to an integer is a pointer to a pointer, which is not the same as a 2d array.
// So, when you cast a 2d array to a pointer to a pointer to an integer, you are essentially treating the 2d array as a pointer to a pointer, which can lead to undefined behavior if you try to access elements of the array using the pointer to a pointer syntax.
// It's better to use the function that takes a 2d array as an argument, rather than trying to cast it to a pointer to a pointer. This way, you can avoid any potential issues with undefined behavior and ensure that your code is safe and correct.   


return 0;

}
