/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 * PROJECT                                ______   _______      _______.      *
 * file.c                                /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/          *
 * Created: 2022/11/05 by CorentinGS                                          *
 * LICENCE: BSD 3-Clause License                                              *
 ******************************************************************************/

#include <stdio.h>
#include <malloc.h>

#include "ex1.h"

static int*
doubler_tableau(const int* t, int n) {
    int i;

    int* t2 = malloc(n * 2 * sizeof(t2));

    for (i = 0; i < n; ++i) {
        t2[i] = t[i];
    }

    for (i = n; i < n * 2; ++i) {
        t2[i] = 0;
    }

    return t2;
}

static Tableau
realloc_tableau(Tableau t) {
    int i;
    int* t2 = malloc(t.n * 2 * sizeof(t2));

    for (i = 0; i < t.n; ++i) {
        t2[i] = t.t[i];
    }

    for (i = t.n; i < t.n * 2; ++i) {
        t2[i] = 0;
    }

    t.t = t2;
    t.n *= 2;

    return t;
}

void
ex1(void) {
    int i;
    int* t = malloc(10 * sizeof(int));
    for (i = 0; i < 10; ++i) {
        t[i] = i;
    }

    int* t2 = doubler_tableau(t, 10);
    for (i = 0; i < 20; ++i) {
        printf("%d ", t2[i]);
    }

    if (t2 != NULL) {
        free(t2);
    }

    printf("\n");

    Tableau t3;
    t3.t = malloc(10 * sizeof(int));
    t3.n = 10;
    for (i = 0; i < 10; ++i) {
        t3.t[i] = i;
    }

    Tableau t4 = realloc_tableau(t3);
    for (i = 0; i < 20; ++i) {
        printf("%d ", t4.t[i]);
    }

    if (t3.t != NULL) {
        free(t3.t);
    }
}
