#include <stdio.h>

unsigned setbits(unsigned x , int p, int n , int y);

int main(){
    // 測試範例：將 y 的最右邊 3 位複製到 x 的第 4-6 位置
    unsigned x = 0b11110000;  // x = 240 (binary: 11110000)
    unsigned y = 0b00000101;  // y = 5   (binary: 00000101)
    int p = 6;                // 結束位置 (0-based)
    int n = 3;                // 複製 3 位

    printf("原始 x: %u (binary: ", x);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf(")\n");

    printf("原始 y: %u (binary: ", y);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (y >> i) & 1);
    }
    printf(")\n");

    unsigned result = setbits(x, p, n, y);
    
    printf("結果:   %u (binary: ", result);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (result >> i) & 1);
    }
    printf(")\n");

    printf("\n說明: 將 y 的最右邊 %d 位 (101) 複製到 x 的第 %d-%d 位置\n", n, p+1-n, p);

    return 0 ;
}

unsigned setbits(unsigned x , int p, int n , int y){

    // step 1 : create the mask which extract the n-bit from rightmost 
    unsigned mask = (1 << n) - 1;

    // step 2 : attach mask to y than move the y_mask to x p( target position)
    unsigned y_bits = (y & mask) << (p + 1 -n);

    // step 3 : clear n bits at position p in x , set other x unchanged
    unsigned x_clean = x & ~(mask << (p + 1 - n));

    // step 4 : 
    return x_clean | y_bits; 

}