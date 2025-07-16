#include <stdio.h>

void escape_fwd(char s[], char t[]);
void escape_inv(char s[], char t[]);


int main(){

    char original[1000] = "\tHello\nWorld";
    char escaped[2000];
    char recovered[1000];

    // Step 1: 轉成跳脫序列
    escape_fwd(escaped, original);
    printf("Escaped: %s\n", escaped);

    // Step 2: 反轉成控制字元
    //escape_inv(recovered, escaped);
    //printf("Recovered: %s\n", recovered);

    return 0;
}

void escape_fwd(char s[] , char t[]){
    
    int i = 0;
    int j = 0;
    
    while (t[i] !='\0'){
        switch(t[i]){
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        } 
        i++;
    }
    s[j]='\0'; // 
}

void escape_inv(char s[] , char t[]){
    int i = 0;
    int j = 0;

    while (t[i] != '\0'){
        if (t[i] == '\\'){
            switch (t[i+1]){
                case 'n':
                    s[j++] ='\n';
                    i += 2;
                    break;
                case 't':
                    s[j++] = '\t';
                    i += 2;
                    break;
                default:
                    s[j++] = t[i++];
                    s[j++] = t[i++];
                    break;
            }
        } else{
            s[j++] = t[i++];
        }
    }
    s[j] = '\0';
}