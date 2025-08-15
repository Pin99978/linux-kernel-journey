#include <stdio.h>

int sum_array(int *arr , int size);

int main(void){

    int my_grades[] = {90,85,95,100};
    int size_arr = sizeof(my_grades) / sizeof(my_grades[0]);
        
    int sum = sum_array(my_grades , size_arr);
    printf("the sum of array is %d\n", sum);
    return 0;
}

int sum_array(int *arr ,int  size){

    int i ;
    int sum = 0;
    for (i = 0; i < size ; i ++){
        sum += arr[i];
    }
    return sum;

}