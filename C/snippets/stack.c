#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comments written only for my understanding, not for the reader

// what is a stack?
//Stack works like a array
//where you pop from the end
//pop the latest
//insert at the latest
//pop the first element last
//FILO

// You can implement pop, push,
// peek, is_empty, is_full
//

// First, define the struct
// Actually stack is static
// on the stack , not on the heap.
//

#define SIZE 10

typedef struct stack{
int data[SIZE];
int head;
//int tail;
//Tail is not required in a stack cuz we are only concerned about one end of the dataframe.
int count;
}stack;

void init(stack *sp){
sp->head = 0;
sp->count = 0;
// sp->data ...
// Again intialisng stack is unnecessary cuz we keep track of the state by the head and tail
printf("Initialised the stack to be empty\n");
}

bool is_empty(stack *sp){
    if(sp->count) return false;
    return true;
}

bool is_full(stack *sp){
    if(sp->count == SIZE) return true;
    return false;
}




int pop(stack *sp){
//First check if the data is there or not
   if(is_empty(sp)) {
        printf("There is no data to pop");
        return -1;
   }
    //pop at the head
    //
    int ret = sp->data[sp->head-1];

    // Decrease the head pointer

    sp->head = sp->head -1; 
    sp->count = sp->count -1;

    printf("Popped %d to the stack\n", ret);

    return ret;
}
bool push(stack *sp, int value){

if(is_full(sp)){
    printf("Already full. On the verge of Stack overflow.");
    return false;
    }

sp->data[sp->head] = value;
sp->head = sp->head +1;
sp->count = sp->count +1;
printf("Pushed %d to the stack\n", value);
return true;
}

int peek(stack *sp){
    // Dont alter the state of the stack
    // Just peek and return the value at the head of the stack
    if(is_empty(sp)){
        printf("The stack is empty, nothing to peek!");
        return -1;
    }

    int ret = sp->data[sp->head-1];

    printf("Peeked the stack. The head is at %d\n", ret);
    printf("The stack is unchanged after peeking\n");
    printf("The no.of elements in the stack currently is %d\n", sp->count);



    return ret;
}


int display(stack *sp){
    if(is_empty(sp)){
        printf("The stack is empty, nothing to display!");
        return -1;
    }
    for(int i = sp->head -1; i >= 0; i--){
        printf("%d ", sp->data[i]);
    }
    
    printf("\n");


    return 0;
}



int main(){

stack st;
stack *sp = &st;
init(sp);
push(sp, 10);
display(sp);
push(sp, 20);
display(sp);
pop(sp);
display(sp);
push(sp, 30);
display(sp);
peek(sp);
display(sp);
return 0;
};

