#include <stdio.h>
#include "tp1_ex9.h"

#define PREV_WORD  0
#define PREV_BLANK 1

void
wc(char* filename) {
    FILE* file;
    int c;
    int lines, words, chars, temp;
    lines = 0;
    words = 0;
    chars = 0;
    temp = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    while ((c = fgetc(file)) != EOF) {
        ++chars;
        if (c == '\n') {
            ++lines;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            if (temp == PREV_WORD) {
                ++words;
            }
            temp = PREV_BLANK;
        } else {
            if (temp == PREV_BLANK) {
                temp = PREV_WORD;
            }
        }
    }

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Chars: %d\n", chars);
}

void
ex9(void) {
    wc("tp1_ex9.c");
}