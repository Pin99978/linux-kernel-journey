#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(){


    printf("char: %d to %d\n" ,CHAR_MIN , CHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    
    // Unsigned types
    printf("unsigned char: %d to %d\n", 0, UCHAR_MAX);
    printf("unsigned short: %d to %d\n", 0, USHRT_MAX);
    printf("unsigned int: %u to %u\n", 0, UINT_MAX );
    printf("unsigned long: %lu to %lu\n", 0UL, ULONG_MAX);
    // floating types
    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
    
    
}