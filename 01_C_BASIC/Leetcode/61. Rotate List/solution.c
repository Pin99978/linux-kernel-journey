
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;

};


#include <stdio.h>

struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (head == NULL){
        return head;
    }


    struct ListNode *tail = head;
    struct ListNode *cur = head;

    // get the length of linked list
    int len = 1;
    
    while (tail -> next != NULL){
        tail = tail -> next;
        len++;
    }

    // get the position where we need to interrup the node
    k = k % len; 
    int breakpoint = len - k - 1;

    // boundary condition
    if (k == 0 || len == 1) {
        return head;
    }

    // move the cur node before the break point
    for (int i = 0 ; i < breakpoint ; i++){
        cur = cur -> next;
    }

    // new node will be the cur node next
    struct ListNode *new = cur -> next;
    // break the cur node next
    cur -> next = NULL;
    // link the last node to the head
    tail -> next = head;
    return new;

}