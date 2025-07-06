#include <stdio.h>

unsigned invert(unsigned x, int p, int n){
    // 00101101 if p =3 n =2 
    // -> 00100001

    // Step 1 , define the mask
    unsigned mask = ( (1<<n) - 1 ) << (p - n + 1);  
    // 00000011 << (p - n + 1)
    // 00001100

    // Step 2,  set bits on 
    unsigned x_invert = ( x ^ mask);


    return x_invert;
}

int main(){
    // Test case 1: 00101101 (45), p=3, n=2
    // Expected: 00100001 (33)
    unsigned x1 = 45;  // Binary: 00101101
    int p1 = 3, n1 = 2;
    unsigned result1 = invert(x1, p1, n1);
    printf("Test 1:\n");
    printf("Original: %u (Binary: ", x1);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (x1 >> i) & 1);
    }
    printf(")\n");
    printf("Inverted: %u (Binary: ", result1);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (result1 >> i) & 1);
    }
    printf(")\n");
    printf("p=%d, n=%d\n\n", p1, n1);
    
    // Test case 2: 11110000 (240), p=5, n=3
    // Should invert bits at positions 3,4,5
    unsigned x2 = 240; // Binary: 11110000
    int p2 = 5, n2 = 3;
    unsigned result2 = invert(x2, p2, n2);
    printf("Test 2:\n");
    printf("Original: %u (Binary: ", x2);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (x2 >> i) & 1);
    }
    printf(")\n");
    printf("Inverted: %u (Binary: ", result2);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (result2 >> i) & 1);
    }
    printf(")\n");
    printf("p=%d, n=%d\n\n", p2, n2);
    
    // Test case 3: 10101010 (170), p=6, n=4
    unsigned x3 = 170; // Binary: 10101010
    int p3 = 6, n3 = 4;
    unsigned result3 = invert(x3, p3, n3);
    printf("Test 3:\n");
    printf("Original: %u (Binary: ", x3);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (x3 >> i) & 1);
    }
    printf(")\n");
    printf("Inverted: %u (Binary: ", result3);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (result3 >> i) & 1);
    }
    printf(")\n");
    printf("p=%d, n=%d\n", p3, n3);
    
    return 0;
}