#include <stdio.h>

unsigned fast_bitcount(unsigned x ){

    int count = 0;
    while ( x != 0 ){
        x &= (x-1);
        count ++;
    }
    return count;
}


int main(){
    // 測試不同的數值
    unsigned test_values[] = {077, 0xFF, 0x0F, 0x80, 0x00, 63, 255};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("Fast Bitcount Test:\n");
    printf("===================\n");
    
    for(int i = 0; i < num_tests; i++) {
        unsigned x = test_values[i];
        int count = fast_bitcount(x);
        
        printf("Value: %3u (0x%02X) Binary: ", x, x);
        
        // 印出二進制表示
        for(int j = 7; j >= 0; j--) {
            printf("%d", (x >> j) & 1);
        }
        
        printf(" -> 1-bits count: %d\n", count);
    }
    
    return 0;
}