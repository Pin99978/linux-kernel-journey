#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


// create Test Node;

TreeNode* createNode(int val){
    // allocate memory 
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    if(!node){
        fprintf(stderr , "Memory allocation failed for TreeNode");
    }
    exit(EXIT_FAILURE);
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

//  free Tree
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 實作資料結構 queue

typedef struct QNode{
    TreeNode* data;
    struct QNode* next;
}QNode ; 

typedef struct Queue{
    QNode* front; // first node of queue
    QNode* last;  // last node of queue
    size_t size;  // Number of elements currently in the queue
}Queue;

void initQueue(Queue* q){
    q -> front = q -> last = NULL;
    q -> size = 0;
}

bool isEmptyqueue(const Queue* q){
    return q->size == 0;
}

void enqueue(Queue* q , TreeNode* x){
    QNode* n = (QNode*)malloc(sizeof(QNode));
    if (!n){
        exit(EXIT_FAILURE);
    }

    n -> data = x;
    n -> next = NULL;

    if (q -> last){
        q -> last -> next = n;
        q -> last = n;
         
    }else{
        q -> front = q -> last = n;
    }
    q -> size ++;
}