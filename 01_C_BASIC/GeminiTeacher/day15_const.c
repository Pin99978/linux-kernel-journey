#include <stdio.h>

int main(){
    int x = 10;
    int y = 20;

    const int *ptr_to_const = &x; // 指向常數的指標
    *ptr_to_const = 15;  // 不能修改指向常數的指標裡的常數值
    ptr_to_const = &y;   // 可以移到不同的記憶體位置

    int * const const_ptr = &x;
    *const_ptr = 15;  // 可以更改常數指標指定的值
    const_ptr = &y;   // 無法更改指向的位址
    return 0 ;
}