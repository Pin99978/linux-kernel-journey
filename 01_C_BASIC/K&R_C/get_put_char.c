#include <stdio.h>

main()
{
    int c;

    while ( (c = getchar()) != EOF) {
        printf("%d" , getchar() != EOF );
        putchar(c);
    }
}
