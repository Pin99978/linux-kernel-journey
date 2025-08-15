## Project : mini shell

### Goal: develop own shell-like program

### learning list:
1. 解析字串
2. 建立process
3. 處理 I/O
4. Process 溝通
5. 執行外部指令


### Progress:
step 1 : 
基礎的「讀取-執行-列印」循環 (REPL)
目標：建立一個永不停止的迴圈，它可以顯示提示符（例如 mysh> ）、讀取使用者輸入的一整行指令，然後再顯示下一次的提示符。

concept: while 迴圈、printf、fgets 讀取 stdin (標準輸入)。

:::info
補充: stdin (standard input)
* 它是一個在 <stdio.h> 中預先定義好的 FILE * 指標
你的程式一啟動，就自動會有三條這樣的輸送帶：
* stdin：標準輸入 (預設是鍵盤)
* stdout：標準輸出 (預設是螢幕)
* stderr：標準錯誤輸出 (預設也是螢幕)
:::


```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    // user input
    char buffer[256];
    while(1){
        printf("mysh>");
        if (fgets(buffer , sizeof(buffer) , stdin) == NULL){
            printf("Goodbye \n");
            break;
        }
        printf("You typed : %s" , buffer);
    }
}

/* output:
mysh>hello
You typed : hello
mysh>你好
You typed : 你好
/*
```

step1 重點: fgets : char *fgets (char *string, int n, FILE *stream);

fgets 留下的一個小問題。fgets 會把使用者按下的換行符 (\n) 一起讀進 buffer 中。我們需要先把這個換行符去掉，不然它會被當成最後一個參數的一部分。


---

step2: 解析:
現在我們的 Shell 已經可以「聽」到使用者說話了，下一步就是要**「聽懂」使用者說了什麼。這一步稱為解析 (Parsing)**。

我們的目標是將使用者輸入的一整行字串，例如 ls -l /home，分割成一個字串陣列，就像這樣：
["ls", "-l", "/home", NULL]

這個格式正是 exec 函式家族所需要的參數格式，所以這一步是執行指令前的必要準備。 


```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    // user input
    char buffer[256];
    char *delimiters = " \t"; // both     consider space and tab
    while(1){
        printf("mysh>");
        char *argv[64];  // 存放分割後的指令參數
        int i = 0 ;
        // 當 stdin 被輸入 ctrl+D 時，break while loop
        if (fgets(buffer , sizeof(buffer) , stdin) == NULL){
            printf("Goodbye \n");
            break;
        }

        // replace the '\n' -> '\0'
        buffer[strcspn(buffer, "\n")] = 0;
        char *token ;    // 暫存每一個被接下來的字串
        char *saveptr;   // strtok_r 內部需要用到的輔助指標
        token = strtok_r(buffer , delimiters , &saveptr);
        while (token != NULL){
            argv[i] = token;
            i++;
            token = strtok_r(NULL, delimiters, &saveptr);
        }
        argv[i] = NULL;
        printf("Parsed arguments:\n");
        /**
        for (int j = 0 ; argv[j] != NULL ; j++){

            printf("arg[%d]: %s\n" ,j , argv[j]);
        //*
       
        }
    }
    return 0 ;
}

// output test
mysh>ls -ltr /home
Parsed arguments:
arg[0]: ls
arg[1]: -ltr
arg[2]: /home
mysh>pwd
Parsed arguments:
arg[0]: pwd
mysh>echo "test"
Parsed arguments:
arg[0]: echo
arg[1]: "test"
mysh>
```
step2 重點: 
strtok_r : 

strtok_r 是 C 語言中用來分割字串，定義在 <string.h> 中

strtok vs. strtok_r:
strtok (non thread-safe) ，如果兩個 thread 同時呼叫 strtok來處理不同的文字，可能產生錯亂。
strtok_r(現代版 strtok)，考慮了 thread-safe 的形式
(因額外提供一個指標 saveptr)，讓function 把上下文狀態儲存在你提供的變數裡，而不是一個隱藏的全域變數裡。

`char *strtok_r(char *str, const char *delim, char **saveptr);`
```c
char *saveptr; // 宣告一個 saveptr 變數給 strtok_r 使用

// 1. 第一次呼叫，傳入 buffer，strtok_r 會回傳第一個 token "ls"
token = strtok_r(buffer, " \t", &saveptr);

while (token != NULL) {
    argv[i++] = token; 
    // 2. 後續呼叫，第一個參數傳入 NULL
    //    這是在告訴 strtok_r：「請不要從一個新字串開始，
    //    繼續從你上次用 saveptr 記錄的位置，幫我切同一個字串。」
    token = strtok_r(NULL, " \t", &saveptr);
}
argv[i] = NULL;

```


strcspn  : 
* 作用: 從第一個字串 (buffer) 的開頭開始搜尋，找出第一個也存在於第二個字串 ("\n") 中的字元，然後回傳那個字元在第一個字串中的索引位置 (index)。

以上面程式碼為例: 假如 buffer  = "ls -l" 然後按enter 則: buffer = "ls -l\n\0" , index of \n = 5
-> buffer[5] = 0; -> 將\n 替換成 \0



---
step3:執行:
 將 fork-exec-wait 邏輯整合到主迴圈中，來執行解析後的指令。

```c
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
        
        // check if the argv[0] is the bulit-in command , e.g exit, cd ...etc

        if (argv[0] == "exit"){
                
        }
        
        
        
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
        
    }
    return 0 ;
}

```


step 4: deal with built-in command
* cd、exit、help 這種需要改變 Shell 本身狀態或直接結束 Shell 的指令，不能作為外部程式執行。
原因:
1. (parent process): mysh 建立了一個子行程。
2. (child process):  成功地執行了 cd 並改變了它自己的工作目錄。
3. (child process):  立刻就結束了，它的改變也隨之消失。
4. (parent process): (你的 mysh）的工作目錄從頭到尾都沒有被改變過。

修正方法: 在 fork 之前，先檢查使用者輸入的是不是內建指令。如果是，就由父行程親自執行；如果不是，才交給子行程去 exec

```c
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
        // because i++ , make last command = NULL
        argv[i] = NULL;
        
        // 處理兩個bulit-in指令 cd & exit
        if (strcmp(argv[0], "exit") == 0){
            break;
        }else if (strcmp(argv[0], "cd") == 0){
            if (argv[1] == NULL){
                fprintf(stderr, "mysh: cd: missing argument\n");
                continue
            }else{
                if (chdir(argv[1]) == -1){
                    perror("chdir failed");
                }
            }
        }else{
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
        }


        
        /** only for testing if imput argument is correct
        printf("Parsed arguments:\n");
        for (int j = 0 ; argv[j] != NULL ; j++){
            printf("arg[%d]: %s\n" ,j , argv[j]);
            
        }**/ 
    }
    return 0 ;
}
```

