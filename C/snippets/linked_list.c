#include <stdio.h>
#include <stdlib.h>

/*
Reached the end of the list
The value at the last node is 6

**** Displaying the list ****
There are 8 nodes in the list
The values at the nodes are as follows :
Element 1 = 6
Element 2 = 5

**** Deletion ****
*/



typedef struct Node {
int value;
struct Node* prev;
struct Node* next;
} Node;

// Simple global variable for count
static int count = 0;

// Create a node
Node* create_node(int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = v;
    new_node->prev = NULL; // Initially
    new_node->next = NULL;
    count++;
    return new_node;
}

// Insert at head/front
Node* insert_head(Node* head, int v){
    
    if(head == NULL){
        Node* new_node = create_node(v);
        head = new_node;
        return new_node;
    }
    
    //if head != NULl
    Node* new_node = create_node(v);
    // so the head is basically somethinng else.
    new_node->next = head;
    new_node->prev = NULL;
    head->prev = new_node;
    return new_node; // Basically return the new head. Keep track of head in the main fucntion.
    
}



// Tracking the head in teh function itself, so the calller does not hve to worry about it. This is a better way to do it.

void insert_head_t(Node**head, int v) {
    if((*head) == NULL) {
        Node* new_node= create_node(v);
        *head = new_node;
        return;
    }

    // if *head != NULL
    Node* new_node= create_node(v);
    new_node->next = (*head);
    new_node->prev = NULL;
    // **head is a pointer to a pointer to a node. So *head is a pointer to a node. So (*head)->prev is the prev of the head node.
    (*head)->prev = new_node;
    (*head) = new_node; // Update the head to the new node.
    return;
}



// Insert at tail

void insert_at_tail(Node **head, int val){
// Traverse until end
Node** temp = head; // Literally does not make a difference because temp  and head will have the same address and anyway you are accessing the value at that address. 
                    // So you can use either temp or head to access the value at that address. 
                    // But using temp makes it more clear that we are traversing the list and not modifying the head pointer itself.
if(*head== NULL){
    insert_head_t(head,val);
    return;
}
else{
    while(((*temp)->next) != NULL) {
       temp = &((*temp)->next);
    }
    printf("Reached the end of the list\n");
    printf("The value at the last node is %d\n", (*temp)->value);

    // Now temp points to the last element.
    // Insert at tail
    Node *new_node = create_node(val);
    new_node->next = NULL;
    new_node->prev = *temp;
    (*temp)->next = new_node;
}
return;
}





// delete certain node

Node* delete_certain_node(Node* head, int node_number_from_head){
    if(head==NULL){
        printf("There is nothing to delete\n");
        return head;
    }
    // there is something
    // First traverse those many nodes
    Node* temp = head;
    if(node_number_from_head) {

    for(int i = 0; i < node_number_from_head; i++){
        head = head->next; 
    }

    }
    // Now, head->prev
    

    printf("\n**** Deletion ****\n");

    printf("The value at the node being deleted is %d\n", head->value);
    if(head == temp) {
        // Deletion from head
        temp = temp->next; 
        head->next = NULL;
        head->prev = NULL;
    }

    else {
    head->prev->next = head->next;
    head->next->prev = head->prev;

    }

    head->next = NULL;
    head->prev= NULL;
    count--;
    return temp;

}

// Delete at head/front
Node* delete_at_head(Node*head) {
    head = delete_certain_node(head, 0);
    return head;
}


void display_list(Node* head){
    printf("\n**** Displaying the list ****\n");
    if(count){
        int counter = 1;
        printf("There are %d nodes in the list\n", count);
    
        printf("The values at the nodes are as follows : \n");
        while(head !=NULL && counter < count+1){
        printf("Element %d = %d\n", counter, head->value);
        head = head->next;
        counter++;
        }
    }
    if(count == 0){
    printf("The list is empty\n");
    return;
    }

    return;
    }


int main() {

// Define the head
Node* head = NULL; 

//Node* new_node = create_node(5);
head = insert_head(head,6);
head = insert_head(head,7);
head = insert_head(head,8);
head = insert_head(head,9);
head = insert_head(head,10);
head = insert_head(head,11); 
insert_head_t(&head, 12);
insert_at_tail(&head, 5);
printf("The value at the head node is %d\n", head->value);
display_list(head);
head = delete_certain_node(head, 2);
display_list(head);
head = delete_at_head(head);
display_list(head);
return 0;

}
