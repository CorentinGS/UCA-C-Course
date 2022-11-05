/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 * TP1                                    ______   _______      _______.      *
 * tp1_ex2.c                             /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/          *
 * Created: 2022/11/05 by CorentinGS                                          *
 * LICENCE: BSD 3-Clause License                                              *
 ******************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "tp1_ex2.h"

static void question1(void);

static void question2(void);

static void question3(void);

static void question4(void);

static void
question1(void) {
    /* Display number from 65 to 90 */
    int i;
    for (i = 65; i <= 90; i++) {
        printf("%d ", i);
    }

    printf("\n");
}

static void
question2(void) {
    /* Display ASCII char from 65 to 90 */
    int i;
    for (i = 65; i <= 90; i++) {
        printf("%c ", i);
    }

    printf("\n");
}

static void
question3(void) {
    double pi;
    /* string with "Pi vaut" */
    char* s;
    s = malloc(10 * sizeof(char));
    strcpy(s, "Pi vaut");
    /* Float pi */
    pi = 3.14159265358979323846;
    /* Display string and float */
    printf("%s %.8f\n", s, pi);
    free(s);
}

static void
question4(void) {
    char c = 'a';
    int i, j;
    i = 65;
    printf("Valeur de c en char est %c, et en dec est %d\n", c, c);
    printf("Valeur de i en char est %c, et en dec est %d\n", i, i);

    /* Display ASCII char from 97 to 122 */
    for (j = 97; j <= 122; j++) {
        printf("%c ", j);
    }
}

void
ex2(void) {
    question1();
    question2();
    question3();
    question4();
}
