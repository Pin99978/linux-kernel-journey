/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *missing = malloc(sizeof(int) * numsSize);
    int *arr = calloc( numsSize + 1, sizeof(int));

    for (int i = 0 ; i < numsSize  ; i++){
        arr[nums[i]] ++;
    }
    int j = 0;
    for (int i = 1 ; i <= numsSize ; i++ ){
        if (arr[i] == 0){
            missing[j] = i;
            j++;
        }
    }
    *returnSize = j;
    return missing;
}