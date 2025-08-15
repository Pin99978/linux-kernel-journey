/*** goal : 

1. 撰寫「比對器」函式 (Callback Functions)

你需要先寫出兩個符合特定「形狀」的比對函式。它們都接受兩個整數（節點的資料和目標值），回傳一個布林值 (true 或 false)。

2. 實作通用的 find_node 函式

這個函式會走訪鏈結串列，並對每一個節點使用傳入的「比對器」函式來判斷是否符合條件。

***/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next ;
};

struct Node *createNode(int data){
    struct Node *new_node = malloc(sizeof(struct Node));
    // always check if allocate memory fail
    if ( new_node == NULL){
        printf("Allocate newnode fail");
        return NULL;
    }

    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void append_node( struct Node **head_ref , int data){
    struct Node *newNode = createNode(data);
    if (newNode == NULL){
        printf("create new node fail");
        return ;
    }
    // check if head is not empty 
    if (*head_ref == NULL){
        *head_ref = newNode ; 
        return ;
    }
    // create one node point to the head_ref;
    struct Node *cur = *head_ref;
    
    while (cur -> next != NULL){
        cur = cur -> next;
    }
    cur -> next = newNode;
}

void print_list(struct Node *head_cp){
    struct Node *cur = head_cp;

    while (cur != NULL){
        printf("%d ->" , cur->data);
        cur = cur -> next;
    }
    printf("NULL");
}

bool is_equal(int node_data , int target){
    return node_data == target;
}

bool is_greater_than(int node_data , int target){
    return node_data > target;
}


struct Node* find_node(struct Node *head_cp , int target , bool(*matcher_fun)(int,int)){
    struct Node *cur = head_cp;
    while (cur != NULL){
        if (matcher_fun(cur-> data , target)){
            return cur ;
        }
        cur = cur -> next;
    }
    return NULL;
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
    struct Node *head = NULL;
    append_node(&head , 10);
    append_node(&head , 15);
    append_node(&head , 30);
    append_node(&head , 40);

    printf("Original list:");
    print_list(head);
    printf("\n\n");

    printf("Searching for a node equal to 30...\n");
    struct Node *found_node = find_node(head, 30, is_equal);
    if (found_node != NULL) {
        printf("Found node with data: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }    

    // 測試 2: 尋找第一個大於 25 的節點
    printf("\nSearching for the first node greater than 25...\n");
    found_node = find_node(head, 25, is_greater_than);
    if (found_node != NULL) {
        printf("Found node with data: %d\n", found_node->data);
    } else {
        printf("Node not found.\n");
    }

    free_list(&head);
    return 0 ;
}