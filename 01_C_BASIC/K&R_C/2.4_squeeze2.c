#include <stdio.h>

char *squeeze(char s1[],char s2[]){
    
    int i, j;
    int to_delete[256] = {0};  // ASCII 字元查找表
    
    // O(m): 標記要刪除的字元
    for (i = 0; s2[i] != '\0'; i++) {
        to_delete[(unsigned char)s2[i]] = 1;
    }
    
    // O(n): 過濾字元
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!to_delete[(unsigned char)s1[i]]) {
            s1[j++] = s1[i];
        }
    }
    
    s1[j] = '\0';
    return s1;

}


int main(){
    char s1[20] = "abccedffg";
    char s2[20] = "cf";

    printf("%s",squeeze(s1,s2));
    return 0;
}