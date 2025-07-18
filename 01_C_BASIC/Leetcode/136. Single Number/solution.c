#include <stdio.h>

int singleNumber(int * nums , int numSize){
    int result = 0;

    for ( int i = 0 ; i < numSize ; i++){
        result ^= nums[i];
    }
    // bitwise operation 符合 結合 & 交換律定律
    // for leetcode case [4,1,2,1,2]
    // -> 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
    // -> 0 ^ 4 ^ (1 ^ 1) ^ (2 ^ 2)
    // -> 0 ^ 4 ^ 0 ^ 0
    // -> 4

    return result;
}