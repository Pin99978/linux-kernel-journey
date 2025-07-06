#include <stdio.h>
#include <string.h>

int any(char s1[] , char s2[]){
    
    int i ;
    char ascii_table[256] = {0}; // 初始化所有元素為 0

    // loop the s2 , cvt it to ascii_table
    for ( i = 0 ; s2[i] != '\0' ; i++ ){
        ascii_table[(unsigned char)s2[i]] = 1;
    }

    // 在 s1 中尋找第一個出現在 s2 中的字元
    for ( i = 0; s1[i] !='\0'; i++){
        if (ascii_table[(unsigned char)s1[i]] ==1)
            return i;
    }
    return -1;
}

int main(){

    // 測試案例
    char s1[] = "hello world";
    char s2[] = "aeiou";
    
    int result = any(s1, s2);

    if (result != -1) {
        printf("第一個匹配的字元 '%c' 在位置 %d\n", s1[result], result);
    } else {
        printf("沒有找到匹配的字元\n");
    }
    
}