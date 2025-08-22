#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool ascending(int a, int b){
    return a > b;
}

bool descending(int a , int b){
    return a < b;
}

void swap(int *a , int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void bubble_sort(int *arr, int size , bool(*compare_func)(int a ,int b)){

    int i , j ;
    for (int i = 0; i < size ; i ++){
        for (int j = 0 ; j < size - i - 1 ; j ++){
            if (compare_func(arr[j], arr[j+1])){
                swap(&arr[j] , &arr[j+1]);
            }
        }
    }
}


void print_array(int arr[] , int size){
    for (int i = 0 ; i < size ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int numbers[] = {5,2,8,1,9,4};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array: ");
    print_array(numbers , size);

    printf("\nSorting in ascending order...\n");
    bubble_sort(numbers, size , ascending);
    printf("Sorted array: ");
    print_array(numbers , size);

    int numbers2[] =  {5,2,8,1,9,4};
    printf("\nSorting in decending order...\n");
    bubble_sort(numbers2 , size , descending);
    printf("Sorted array: ");
    print_array(numbers2 , size);

}

