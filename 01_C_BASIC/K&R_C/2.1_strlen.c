#include <stdio.h>
#include <string.h>

// manually implement strlen function

int my_strlen(char s[]){
    int i;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}





int main(){
    char str[] = "hello,world";
    size_t str_len = strlen(str);
    
    printf("the string is \"%s\"\n", str);
    printf("the length of the string is %zu\n", str_len);

    // run with function
    int my_len = my_strlen(str);
    printf("the length of the string is %d\n", my_len);
}