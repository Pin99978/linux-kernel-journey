#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    // user input
    char buffer[256];
    char *delimiters = " \t"; // both     consider space and tab

    while(1){
        printf("mysh>");
        
        char *argv[64];  // 存放分割後的指令參數
        int i = 0 ;

        // 當 stdin 被輸入 ctrl+D 時，break while loop
        if (fgets(buffer , sizeof(buffer) , stdin) == NULL){
            printf("Goodbye \n");
            break;
        }
        // replace the '\n' -> '\0'
        buffer[strcspn(buffer, "\n")] = 0;
        char *token ;    // 暫存每一個被接下來的字串
        char *saveptr;   // strtok_r 內部需要用到的輔助指標

        token = strtok_r(buffer , delimiters , &saveptr);
        while (token != NULL){
            argv[i] = token;
            i++;
            token = strtok_r(NULL, delimiters, &saveptr);
        }
        argv[i] = NULL;
        
        // let shell can execute the command in child process
        pid_t pid = fork();

        if( pid < 0){
            perror("fork process fail");
            return 1;
        }else if(pid == 0){
            execvp(argv[0] , argv);
            perror("fail to execute child process");
            exit(1);
        }else{
            wait(NULL);
        }
        
        /** only for testing if imput argument is correct
        printf("Parsed arguments:\n");
        for (int j = 0 ; argv[j] != NULL ; j++){
            printf("arg[%d]: %s\n" ,j , argv[j]);
            
        }**/ 
    }
    return 0 ;
}