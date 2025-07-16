#include <stdio.h>

int binsearch(int x , int v[] , int n){

    int low , high , mid;

    low = 0 ;
    high = n - 1;
    while(low <= high){
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low  = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main(){
    
    int v[10] = {1,3,5,20,35,45,67,80,91,120};
    int x = 35;
    int n = 10;
    int result;
    result = binsearch(x, v , n );
    printf("The value %d found at index %d\n", x, result);
}