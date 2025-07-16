#include <stdio.h>
#include <math.h>



// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // 先用快針走到n+1
    for (int i = 0 ; i <= n ; i++){
        fast = fast -> next;
    }

    // 快針走到結束 (n + 1) + x  x 為走到NULL的步數 , 此時slow走x步

    // ( n + 1 ) + x = len + 1
    //  x = len - n ! 
    while (fast != NULL){ 
        fast = fast -> next;
        slow = slow -> next;
    }
    
    // arrive the n - 1 path , remove ;
    slow -> next = slow -> next -> next;

    return dummy.next;
}