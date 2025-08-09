#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char** fizzBuzz(int n, int* returnSize) {

    char **arr = malloc(n * sizeof(char *));
    char snum[12];
    for (int i = 0 ; i < n ; i++){
        if ( (i+1) % 3 == 0 && (i+1) % 5 == 0) {
            arr[i] = malloc(strlen("FizzBuzz") + 1);
            strcpy(arr[i], "FizzBuzz");
        } else if( (i+1) % 3 == 0) {
            arr[i] = malloc(strlen("Fizz") + 1);
            strcpy(arr[i], "Fizz");
        } else if( (i+1) % 5 == 0) {
            arr[i] = malloc(strlen("Buzz") + 1);
            strcpy(arr[i], "Buzz");
        } else {
            sprintf(snum, "%d", i+1);     // 將 i 轉成字串
            arr[i] = malloc(strlen(snum) + 1);
            strcpy(arr[i], snum);
        }
    }
    
    *returnSize = n;
    
    return arr;

}
// ...existing