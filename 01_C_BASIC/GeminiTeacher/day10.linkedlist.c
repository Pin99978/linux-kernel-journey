#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* create_node(int data){
    // 1. Declare a new node pointer. 
    struct Node *new_node = NULL;

    // 2. Allocate memory for one 'struct Node' on the heap.
    new_node = malloc(sizeof(struct Node));
    // 3. check if malloc fail , if so return NULL;
    if (!new_node) return NULL;

    // 4. if allocation success
    new_node -> data = data;
    new_node -> next = NULL;

    return new_node;
}

int main(void){
    struct Node *head = NULL;
    head = create_node(10);

    if (head != NULL){
        printf("First node created with data: %d\n", head->data);
        free(head);
    }else{
        printf("Fail to create node .\n");
    }

    return 0;
}