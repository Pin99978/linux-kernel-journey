/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap( int * , int *);

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    
    int *arr = malloc( numsSize * sizeof(int));

    if (!arr) return NULL;

    for (int i = 0 ; i < numsSize ; i++){
        *(arr + i) = nums[i] * nums[i];
    }

    // set the size of arr
    *returnSize = numsSize;

    // test bubble sort in C
    for (int i = 0; i < numsSize - 1 ; i++){
        for ( int j = 0; j < numsSize - i - 1 ; j ++){
            if ( *(arr + j) >= *(arr + (j+1)) ){
                swap( &arr[j] , &arr[j+1]);
            }
        }
    }

    return arr;
}

void swap(int * a , int * b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

