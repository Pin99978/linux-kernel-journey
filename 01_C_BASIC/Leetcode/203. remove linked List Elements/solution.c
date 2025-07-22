/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode *cur = head; 
    struct ListNode dummy;
    struct ListNode *ptr = &dummy;
    
    dummy.next = NULL;

    while (cur != NULL ){
        if (cur -> val != val){
            ptr -> next = cur;
            ptr = ptr -> next;
        }
        cur = cur -> next;
    }
    ptr -> next =NULL;
    return dummy.next;
}