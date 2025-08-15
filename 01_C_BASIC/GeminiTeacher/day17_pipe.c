#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>
#include <string.h>

int main(){

    int pipefd[2] ;
    char buffer[1000];

    if (pipe(pipefd) == -1){
        perror("fail to establish pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0){
        printf("error occur");
    }else if (pid == 0){
        printf("I am a child process\n");
        close(pipefd[1]);
        // 儲存實際讀取到的位元組數
        int bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1); // 保留一個空間給 '\0'
        
        if (bytes_read > 0) {
            // 手動加上字串結束符
            buffer[bytes_read] = '\0';
            printf("Child received: %s", buffer);
        }
        close(pipefd[0]);
        exit(0);

    }else{
        printf("I am a parent process\n");
        // close PID 
        close(pipefd[0]);
        char message[] = "Hello child, from your parent!\n";
        write(pipefd[1] , message , strlen(message));

        close(pipefd[1]);
        wait(NULL);

    }

}