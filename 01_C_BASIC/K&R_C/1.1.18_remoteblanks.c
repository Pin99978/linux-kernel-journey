/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. */
#include <stdio.h>

#define MAXLINE 1000  // buffer size per line

int get_line(char line[], int maxline);
void trim_trailing_whitespace(char s[]);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        trim_trailing_whitespace(line);

        if (line[0] != '\0')  // skip completely blank lines
            printf("%s", line);  // 移除額外的 \n，因為字符串已經包含換行符
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

void trim_trailing_whitespace(char s[]) {
    int i = 0;

    // Move to end of string
    while (s[i] != '\0')
        ++i;
    --i;

    // Step back over newline if present
    if (i >= 0 && s[i] == '\n')
        --i;

    // Trim trailing spaces and tabs
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;

    // If we have any non-whitespace characters, restore newline
    if (i >= 0) {
        s[i + 1] = '\n';
        s[i + 2] = '\0';
    } else {
        // Completely blank line - make it empty string
        s[0] = '\0';
    }
}
