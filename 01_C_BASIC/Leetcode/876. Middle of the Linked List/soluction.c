
//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* middleNode(struct ListNode* head) {
    // using slow / fast pointer to go through list node
    struct ListNode *fast = head; // create the fast pointer point to the head
    struct ListNode *slow = head; // create the slow pointer point to the head
    
    while ( fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;  // move fast two steps
        slow = slow -> next ;        // move slow 
    }

    return slow;
}