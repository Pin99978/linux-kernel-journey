#include <string.h>


void strncpy_ptr(char *s, const char *t, int n) {
    int i = 0;

    // Copy characters from t to s using pointers
    while (i < n && *t != '\0') {
        *s = *t;
        s++;
        t++;
        i++;
    }

    // Pad the rest with nulls if t is shorter than n
    while (i < n) {
        *s = '\0';
        s++;
        i++;
    }
}