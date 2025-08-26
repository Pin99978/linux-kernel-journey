/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


 int gcd(int a,int b)
 {
    if(b==0) return a;
    return gcd(b,a%b);
 }

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode **p = &head;

    while ((*p) -> next != NULL){
        // cur node val 
        int gcd_value = gcd( (*p) -> val,(*p) -> next -> val);
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode -> val = gcd_value;
        newNode -> next = (*p) -> next;
        (*p) -> next = newNode;
        // move node to next -> next
        p = &(*p) -> next -> next;
    }
    return head;
}

