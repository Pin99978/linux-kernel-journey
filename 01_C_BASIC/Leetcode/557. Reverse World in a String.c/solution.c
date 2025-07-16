#include <stdio.h>
#include <string.h>

void swap(int s_ptr , int e_ptr , char s[]);

char* reverseWords(char* s) {
    int begin  = 0 , end = 0;
    int isword = 0;
    // two pointer
    for (end = 0 ; end <= strlen(s); end++){
        if (s[end] ==' ' && isword ){
            swap(begin , end-1 , s);
            isword = 0; 
        }else if (s[end] != '\0'){
            if(!isword){
                begin = end;
            }    
            isword = 1;
        }else{
            swap(begin , end-1, s);
        }
    }
    return s;
}   

void swap(int s_ptr , int e_ptr , char s[]){
    int temp;

    while(s_ptr < e_ptr){
        temp = s[e_ptr];
        s[e_ptr] = s[s_ptr];
        s[s_ptr] = temp;
        s_ptr ++;
        e_ptr --;
    }
}
