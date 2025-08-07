int missingNumber(int* nums, int numsSize) {
    
    // n = numsSize , sizeof(nums)= 


    int *arr = calloc(numsSize + 1 , sizeof(int));
    int i ;
    int missing ;
    // create the HASH Table arr whose value is 0

    for ( i = 0 ; i < numsSize  ; i++){
        arr[nums[i]] ++;
    }
    
    for ( i = 0 ; i <= numsSize  ; i++){
        
        if (arr[i] == 0){

            missing = i ;
        }
    }
    free(arr);
    return missing;
   
}