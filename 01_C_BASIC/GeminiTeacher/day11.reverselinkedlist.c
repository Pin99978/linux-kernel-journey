#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next ;
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

void append_node(struct Node **head_ref , int data){
    struct Node *new_node = create_node(data);
    // check if allocate memory fail
    if (new_node == NULL){
        printf("allocate new node memory fail");
        return ;
    }
    
    // if head_node current is NULL , let new node as new node list 
    if (*head_ref == NULL){
        *head_ref = new_node;
        return ;
    }

    // add node if head_ref has already owned some nodes

    struct Node *cur = *head_ref;
    while (cur -> next!= NULL){
        cur = cur -> next;
    }
    cur -> next = new_node;
    
}


void print_nodelist(struct Node *head_cp){
    struct Node *cur = head_cp;
    while (cur != NULL){
        printf("%d ->" , cur -> data);
        cur = cur -> next;
    }
    printf("NULL");
}

struct Node *reverse_list(struct Node *head_cp){
    struct Node *cur = head_cp;
    struct Node *pre = NULL;
    struct Node *next_node = NULL;
    
    while(cur){
        next_node = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = next_node; 
    }
    return pre;
}

void free_list(struct Node **head_ref){
    
    struct Node *cur = *head_ref;
    struct Node *next_node = NULL;

    while (cur){
        next_node = cur -> next;
        free(cur);
        cur = next_node;
    } 
    *head_ref = NULL;
}



int main(void){

    struct Node *head = NULL;
    append_node(&head, 15);
    append_node(&head, 25);
    append_node(&head, 40);
    append_node(&head, 35);

    printf("Original list: ");
    print_nodelist(head);
    printf("\n");

    // reverse the node list
    head = reverse_list(head); 
    
    print_nodelist(head);
    printf("\n");
    // clean memory 
    free_list(&head);

    return 0 ;
}