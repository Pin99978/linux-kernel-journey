#include <stdio.h>
#define MAXLINE 20

int get_line(char line[], int maxline);
void copy(char to[], char from[]);


int main(){

    int len;
    char line[MAXLINE];
    
    len = get_line(line, MAXLINE);
    printf("%d", len);
    
    
}

int get_line(char s[] , int lim){
    int c , i;
    for ( i = 0 ; i < lim - 1 && ( c = getchar() != EOF); ++i){
        s[i] = c;
    }
    if ( c == '\n' ){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


