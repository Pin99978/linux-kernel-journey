#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if (pid < 0){
        perror("error occur");
        return 1;
    }else if( pid == 0){
        printf("This is child process (PID: %d)", getpid());
        printf("Now we want to change child process to ls");
        execlp("ls" , "ls" , "-l" , NULL);
        
        perror("execlp failed");
        exit(1);

    }else{
        printf("Parent: My PID is %d, waiting for child (PID: %d) to finish...\n", getpid(), pid);

        wait(NULL);
        printf("Parent: Child command has finished .\n");

        return 0 ;
    }
}