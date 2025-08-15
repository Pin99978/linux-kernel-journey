#include <stdio.h>
#include <stdlib.h>

int main(void){

    int *grades = NULL;
    int num_grades;

    printf("How many grades do you want to enter? ");
    scanf("%d" , &num_grades);

    grades= malloc(num_grades * sizeof(int ) );

    if (grades == NULL){
        printf("fail to allocate memory");
        return 1;
    }
    free(grades);
    return 0 ;
}