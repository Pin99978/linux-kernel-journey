/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    
    int *arr = malloc( numsSize * sizeof(int));

    int arr_even[ numsSize / 2];
    int arr_odd[ numsSize / 2];
    int i = 0 , j = 0 , k = 0;

    for (i = 0; i < numsSize ; i++){
        if (nums[i] % 2 == 0 ){
            arr_even[j] = nums[i];
                j++;
        }else{
            arr_odd[k] = nums[i];
                k++; 
        }
    }

    
    int odd = 0 , even = 0;
    for ( i = 0 ; i < numsSize ; i++){
        if (i % 2 == 0){
            arr[i] = arr_even[even];
            even++;
        }else{
            arr[i] = arr_odd[odd];
            odd++;
        }
    }
    *returnSize = numsSize;
    return arr;
}