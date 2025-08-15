#include <stdio.h>
#include <string.h>


int lengthOfLongestSubstring(char* s) {

    int last_index[128];

    for (int i = 0 ; i < 128 ; i++){
        last_index[i] = -1;
    }

    int max_len = 0;
    int start   = 0;

    for (int i = 0 ; s[i] != '\0'; i++){
        char c = s[i];

        if (last_index[(int)c] >= start)
            start = last_index[(int)c] + 1;
        last_index[(int)c] = i;
        int current_len = i - start + 1;
        
        if (current_len > max_len){
            max_len = current_len;
        }
        
    }
    return max_len;
}