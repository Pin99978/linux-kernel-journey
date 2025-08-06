# define STACK_SIZE 100


typedef struct {
    int inStack[STACK_SIZE];
    int intop;
    int outStack[STACK_SIZE];
    int outop;
} MyQueue;


MyQueue* myQueueCreate() {

    MyQueue *queue = malloc(sizeof(MyQueue)); 
    queue -> intop = -1 , queue -> outop = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj -> intop < STACK_SIZE -1){
        obj -> inStack[++(obj->intop)] = x;
    }
}

int myQueuePop(MyQueue* obj) {
    if (obj -> outop == -1){
        while (obj -> intop != -1){
           obj->outStack[++(obj->outop)] = obj->inStack[(obj->intop)--];
        }
    }   
    return obj -> outStack[ (obj->outop)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj -> outop == -1){
        while (obj -> intop != -1){
            obj->outStack[++(obj->outop)] = obj->inStack[(obj->intop)--];
        }
    }
    return obj ->outStack[ obj->outop] ;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->intop == -1 && obj->outop == -1;
}

void myQueueFree(MyQueue* obj) {
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/