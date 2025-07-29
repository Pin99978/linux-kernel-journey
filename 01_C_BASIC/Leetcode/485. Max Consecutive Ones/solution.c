int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int i = 0;
    int sum = 0;
    int max = 0;
    for (i = 0; i < numsSize; i++){
        if (nums[i] & 1 == 1){
            sum++;
        }else{
            sum = 0;
        }

        if (max <= sum){
            max = sum;
        }
    }
    return max;
}