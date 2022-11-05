/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 * TP1                                    ______   _______      _______.      *
 * tp1_ex9.c                             /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/          *
 * Created: 2022/11/05 by CorentinGS                                          *
 * LICENCE: BSD 3-Clause License                                              *
 ******************************************************************************/

#include <stdio.h>
#include "tp1_ex9.h"

#define PREV_WORD  0
#define PREV_BLANK 1

void
wc(const char* filename) {
    FILE* file;
    int c;
    int lines, words, chars, temp;
    lines = 0;
    words = 0;
    chars = 0;
    temp = 0;
    file = fopen(filename, "r");
    if (NULL == file) {
        printf("Error opening file\n");
        return;
    }
    while ((c = fgetc(file)) != EOF) {
        ++chars;
        if ('\n' == c) {
            ++lines;
        }
        if (' ' == c || '\n' == c || '\t' == c) {
            if (PREV_WORD == temp) {
                ++words;
            }
            temp = PREV_BLANK;
        } else {
            if (PREV_BLANK == temp) {
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
