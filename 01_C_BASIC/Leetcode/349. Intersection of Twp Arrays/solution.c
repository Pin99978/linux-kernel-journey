/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXLENGTH 1000

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // create the dynamic array for length is 1000 * int  and each value is 0
    int *is_exist_arr = calloc(MAXLENGTH  + 1, sizeof(int));

    int i = 0 ,j = 0;
    // through nums1 , if value appear , store in is_exist_arr  like if nums[4,9,5]
    // is_exist_arr[4] = 1
    for (int i = 0 ; i < nums1Size; i++){
        is_exist_arr[nums1[i]] = 1;
    }

    for (int j = 0 ; j < nums2Size; j++){
        if (is_exist_arr[nums2[j]] == 1 ){
            is_exist_arr[nums2[j]]++;
        }
    }

    int *arr = malloc(1001 * sizeof(int));
    int k = 0;
    for (i = 0 ; i < 1001 ; i++){
        if (is_exist_arr[i] == 2){
            arr[k] = i;
            k++;
        }
    }

    *returnSize = k;
    return arr;


}