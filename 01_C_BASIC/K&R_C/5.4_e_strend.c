#include <stdio.h>

int strend(char *s , char *t){

    char *s_start = s;
    char *t_start = t;

    // move both s & t to the last char
    while (*s != '\0')
        s++;
    while (*t != '\0')
        t++; 

    while (t != t_start){
        s--;
        t--;
        if (*s != *t)
            return 0;
        }
    return 1;        
    }

