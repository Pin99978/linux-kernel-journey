/* Exercise 1-17. Write a program to print all input lines that are longer than 10 characters.  */
#include <stdio.h>
#define MAXLINE 1000  // 增加緩衝區大小以容納長行

int get_line(char line[], int maxline);


#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main() {
    int len, extra;
    int c;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        extra = 0;

        // If the last char stored wasn't newline, line was clipped
        if (line[len - 1] != '\n') {
            while ((c = getchar()) != '\n' && c != EOF)
                ++extra;
        }

        if (len + extra > 10) {
            printf("長度超過80的行: %s", line);
        }
    }

    return 0;
}

int get_line(char s[], int lim){
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i] = c;  // 保留換行符
        ++i;
    }
    
    s[i] = '\0';  // 添加字符串結束符
    return i;     // 返回行的長度（包括換行符）
}