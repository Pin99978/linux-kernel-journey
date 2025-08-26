#include <stdio.h>
#include <stdlib.h>

/* 1st tried , bruted force*/


//Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
};


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    struct ListNode dummy ;
    struct ListNode *l1 = list1;
    struct ListNode *l2 ;

    l2 = &dummy;
    l2 -> next = l1;
    for (int i = 0 ; i <= b ; i++){
        l1 = l1 -> next; // move cur to b next not
    }

    for (int i = 0 ; i < a ; i++){
        l2 = l2 -> next;
    }

    l2 -> next = list2;
    l2 = l2 -> next;
    
    while (l2->next){
        l2 = l2 -> next;
    }

    l2 -> next = l1;
    return dummy.next;
}

//2nd , use Pointer to Pointer method

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    struct ListNode **p = &list1; // store the list1's header pointer's address

    for (int i = 0 ; i < a ; i++){
        p = &(*p)->next;
    }

    struct ListNode **q = &list2;
    for (int i=0 ; i<= b ; i++){
        q = &(*q)->next;
    }
    *p = list2;
    while (list2 -> next != NULL){
        list2 = list2 ->next;
    }
    list2 -> next = *q;
    return *list1;
}




