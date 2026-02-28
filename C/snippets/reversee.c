#include <stdio.h>
#include <stdlib.h>

// Reverse a string and return a pointer to the reversed string

char* reverse_string(char* input , int size){
   int i = 0; 
   // Allocate reverse_string to the same size as input in the heap. We cant do char* reverse_string = "" , Read only memory.
   
   char* reverse_string = (char*) malloc(sizeof(char) * size);
   char *pointer_to_beginning_reverse_string = reverse_string;
   while(i <size){
       *reverse_string = *(input+size-i-1);
       reverse_string++;
       i++;
   }

return pointer_to_beginning_reverse_string;
};


int main(){

char* input = "race";
char* output = reverse_string(input,strlen(input));
printf("the input is %s\n", input);
printf("the output is %s\n", output);
free(output);
return 0;
}

