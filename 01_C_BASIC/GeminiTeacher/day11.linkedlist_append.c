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

/**
 * 將一個新節點附加到鏈結串列的末尾。
 * @param head_ref 指向 head 指標的指標。
 * @param new_data 要新增的資料。
 */

 void append_node(struct Node **head_ref , int new_data){
    struct Node *new_node = create_node(new_data);
    if (new_node == NULL){
        printf("Faill to allocate memory");
        return;
    }

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    struct Node *cur = *head_ref;
    while (cur -> next != NULL){
        cur = cur -> next;
    }
    cur -> next = new_node;

}

void print_list(struct Node *head){
    struct Node *cur = head;
    while (cur != NULL){
        printf( "%d -> " , cur -> data);
        cur = cur ->next;
    }
    printf("NULL\n");
}

void free_list(struct Node **head_ref){
    struct Node *cur = *head_ref;
    struct Node *next_node = NULL;

    while (cur != NULL){
        // 先用 next_node 紀錄 cur 的下一個node;
        next_node = cur -> next;
        free(cur);
        cur = next_node;
    }
}



int main(void){
    struct Node* head = NULL;
    append_node(&head , 10);
    append_node(&head , 20);
    append_node(&head , 30);
    printf("Appended 3 nodes.\n");
    print_list(head);
    // need to modify the head node , so pass the address of *head;
    free_list(&head);
    return 0;
}