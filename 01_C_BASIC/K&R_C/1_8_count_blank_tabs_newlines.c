#include <stdio.h>

int main()
{
    int c, nc;

    nc = 0;

    while ( (c = getchar()) != EOF )
        if (c == ' ' || c == '\t' || c == '\n')  
             ++nc;
    printf("%d" , nc);
    return 0;
}

