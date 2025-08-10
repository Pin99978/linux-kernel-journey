/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy ;
    struct ListNode *cur = &dummy; // point to the dummy memory
    dummy.next = NULL;
    
    int carry = 0;

    while ( l1 != NULL || l2 != NULL){
        int x = (l1 != NULL) ? l1 -> val : 0;
        int y = (l2 != NULL) ? l2 -> val : 0;
        int sum = carry + x + y ;
        carry = sum / 10 ; // new carry ,and carry is declare outside the while scope , can share 
        cur -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (!cur -> next) return NULL;

        cur->next->val = sum % 10;
        cur->next->next = NULL;
        cur = cur ->next ; // move the cur to next node (which we just create)
        if (l1 != NULL )  l1 = l1 -> next;
        if (l2 != NULL )  l2 = l2 -> next;
    }
    // carry >0 means need one more node
    if (carry > 0){
        cur -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur -> next -> val = 1;
        cur -> next -> next = NULL;
        cur = cur -> next;
    }

    return dummy.next;
    
}