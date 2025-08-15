#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left; 
    struct TreeNode *right;
};


struct TreeNode* stack[MAX_SIZE];

int top = -1;

bool isEmpty(){
    return top == -1 ;  
}

void push(struct TreeNode* node){
    stack[++top] = node;
}

int pop(){
    return stack[top--] ;
}


