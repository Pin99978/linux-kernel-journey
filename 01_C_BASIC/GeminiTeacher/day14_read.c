#include <stdio.h>
#include <stdlib.h>

int main(){

    char buffer[256];

    FILE *file_pointer = fopen("log.txt", "r");

    if (file_pointer ==NULL ){
        perror("fail to open log.txt");
        return 1;
    }

    while(fgets(buffer , sizeof(buffer) ,file_pointer ) != NULL){
        printf("%s" , buffer);
    }

    fclose(file_pointer);
    return 0;
}