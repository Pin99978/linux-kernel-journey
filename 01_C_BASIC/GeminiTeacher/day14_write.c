#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *file_pointer = fopen("log.txt","w");
    if (file_pointer == NULL){
        printf("Open file fail");
        return 1;
    }
    fprintf(file_pointer , "Player status: OK.\n");
    fclose(file_pointer);

    return 0;
}