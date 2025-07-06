#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

int main(){

    int c , nl, nc , nw, state;
    // initialize the state
    state = OUT;
    nl = nc = nw = 0;
    while (( c = getchar()) != EOF) {
        ++nc;
    if (c == '\n')
        ++nl;
    if(c == ' ' || c== '\n' || c == '\t')
        state = OUT;
    else if (state ==OUT) {
        state = IN;
        ++nw;
        }
    }
    printf("%d %d %d\n" , nl, nw ,nc);
}

