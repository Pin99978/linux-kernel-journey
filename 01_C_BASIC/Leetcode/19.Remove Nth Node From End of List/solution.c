#include <stdio.h>
#include <math.h>



// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    // get the full length first    
    struct ListNode *ptr = head;
    int len = 0; 

    while ( ptr != NULL ){
        ptr = ptr -> next;
        len ++ ;
    }

    // Create dummy 
    struct ListNode dummy;
    struct ListNode *ptr2 = &dummy;
    
    dummy.next = head; 
    
    int target_from_head = len - n;
    int count = 0; 

    while ( ptr2 != NULL && ptr2 -> next != NULL){
        
        if (count == target_from_head){
            ptr2 -> next = ptr2 -> next -> next;
        }
        ptr2 = ptr2 -> next;
        count++; 
    }
    return dummy.next;
}