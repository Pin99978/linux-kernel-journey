#include <stdio.h>

float sum_elements(float a[] , unsigned length){
    int i ;
    float result = 0;

    // 當
    for (i = 0 ; i <= length -1 ; i++){
        result += a[i];
    }
    return result;
}