#include <stdio.h>

#define MAXWORD 20  // max word length to track

int main() {
    int c, i, len = 0;
    int word_lengths[MAXWORD + 1] = {0};  // +1 to include words > MAXWORD

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (len > 0) {
                if (len <= MAXWORD)
                    ++word_lengths[len];
                else
                    ++word_lengths[0]; // overflow bin
                len = 0;
            }
        } else {
            ++len;
        }
    }

    // Print horizontal histogram
    for (i = 1; i <= MAXWORD; ++i) {
        if (word_lengths[i]) {
            printf("%2d: ", i);
            for (int j = 0; j < word_lengths[i]; ++j)
                putchar('*');
            putchar('\n');
        }
    }

    if (word_lengths[0]) {
        printf("> %d: ", MAXWORD);
        for (int j = 0; j < word_lengths[0]; ++j)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
