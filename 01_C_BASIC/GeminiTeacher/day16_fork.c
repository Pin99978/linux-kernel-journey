#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t pid = fork();

    if (pid < 0 ){
        printf("Error occur");
    }else if (pid ==0){
        printf("Child: I am the child process (PID: %d).\n", getpid());
        printf("Child: I am doing some work...\n");
        sleep(2);
        printf("Child: I have finished my work.\n");
    }else{
        printf("Parent: I am the parent (PID: %d).\n", getpid());
        printf("Parent: I am waiting for my child (PID: %d) to finish...\n",pid);
        wait(NULL); // <-- 在這裡等待！
        
        printf("Parent: My child has finished. I can now continue.\n");
    }

    // 父子行程都會執行的程式碼
    printf("This line is printed by process %d\n", getpid());    
    return 0 ;
}

