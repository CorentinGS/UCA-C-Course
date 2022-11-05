/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 * TP1                                    ______   _______      _______.      *
 * tp1_ex5.c                             /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/          *
 * Created: 2022/11/05 by CorentinGS                                          *
 * LICENCE: BSD 3-Clause License                                              *
 ******************************************************************************/

#include <stdio.h>
#include "tp1_ex5.h"

static void question1(void);

static void
question1(void) {
    /* read user input */
    int i, max, min;
    max = 20;
    min = 0;
    printf("Enter a number: ");
    scanf("%d", &i);
    if (i > max) {
        printf("The number is too big\n");
    } else if (i < min) {
        printf("The number is too small\n");
    } else {
        printf("The number is in the range\n");
    }
}

static void question2(void);

int read_number(int min, int max);

int
read_number(int min, int max) {
    int i;
    printf("Enter a number between %d and %d: ", min, max);
    if (scanf("%d", &i) != 1) {
        while ((i = getchar()) != '\n' && i != EOF) {}
        printf("Invalid input dude, be careful!\n");
        return -1;
    }
    if (i == 99) {
        return -1;
    }
    while (i < min || i > max) {
        printf("The number is not in the range\n");
        printf("Enter a number between %d and %d: ", min, max);
        scanf("%d", &i);
    }
    return i;
}

#define MAX 20
#define MIN 0

static void
question2(void) {
    int sum, i, n;
    sum = 0;
    i = read_number(MIN, MAX);
    n = 0;
    while (-1 != i) {
        i = read_number(MIN, MAX);
        if (-1 != i) {
            sum += i;
            ++n;
        }
    }

    printf("The average is %d\n", sum / n);
}

static void question3(void);

int f(void);

static void
question3(void) {
    int nb;
    nb = f();
    printf("nb = %d\n", nb);
}

int
f(void) {
    int i;
    printf("Nombre stp");
    scanf("%d", &i);
    return i;
}

void
ex5(void) {
    question1();
    question2();
    question3();
}
