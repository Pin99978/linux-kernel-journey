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