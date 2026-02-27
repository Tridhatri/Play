#include <stdio.h>
#include <stdlib.h>

// Reverse a string without using strrev()

char* reverse_string(char* input, int size){
    
    int i = 0;
    char* output = malloc(size * sizeof(char)); // Allocating memory for the output string
    //char* output = ""; 
    // Why Cant I do this?
    // This is because when you assign a string literal (like "") to a char* variable, it points to a read-only section of memory. WHY? 
    // String literals are stored in a read-only segment of memory, and they cannot be modified. 
    // When you try to write to this memory (like assigning characters to it), it results in undefined behavior, which can lead to crashes or other unexpected issues.
    // Attempting to modify this memory (like writing characters into it) results in undefined behavior, which can lead to crashes or other unexpected issues.
    // To fix this, you need to allocate writable memory for the output string, either by using malloc or by declaring a character array with sufficient size. 
    //
    // SO, you basically never do char* some_string = ""; if you want to modify some_string later on. 
    // Instead, you should do char* some_string = malloc((size + 1) * sizeof(char)); to allocate memory for the string and ensure it is null-terminated.
    //
    // A string literal is basically a constant array of characters that is stored in a read-only section of memory. When you assign a string literal to a char* variable, it points to this read-only memory.
    // Damn. 
    // For example:
    // char* output = malloc((size + 1) * sizeof(char)); 
    
    char* temp = output; // Saving the start address of the output in temp
    while(i < size){
    char get_element = input[size-1-i];    
    output[i] = get_element;
    i++;

    //You can also do this :
    /*
      while(i<size){
      *output = *(input + size-1-i); 
      i++;
      output++;
     
     
      }
    */


    }
    output[size] = '\0'; // Null-terminating the output string
    return temp;
}



int main(){

char *input = "racecar";
// To get the size of the char*input

int size = strlen(input);
int sizze = sizeof(input);

printf("The size of the input string is : %d\n", size);
printf("The size of the input pointer is : %d\n", sizze);

char* output = reverse_string(input,size);
printf("The output string is : %s", output);
free(output); // Freeing the allocated memory for output

return 0;
}
