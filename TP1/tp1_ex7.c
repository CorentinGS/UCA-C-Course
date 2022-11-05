/******************************************************************************
 * Copyright (c) 2022.                                                        *
 *                                                                            *
 * TP1                                    ______   _______      _______.      *
 * tp1_ex7.c                             /      | /  _____|    /       |      *
 *                                      |  ,----'|  |  __     |   (----`      *
 * By: CorentinGS                       |  |     |  | |_ |     \   \          *
 * <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |         *
 *                                       \______| \______| |_______/          *
 * Created: 2022/11/05 by CorentinGS                                          *
 * LICENCE: BSD 3-Clause License                                              *
 ******************************************************************************/

#include <stdio.h>
#include "tp1_ex7.h"

static int convert_to_f(int c);

static int
convert_to_f(int c) {
    return (c * 9 / 5) + 32;
}

static int convert_to_c(int f);

static int
convert_to_c(int f) {
    return (f - 32) * 5 / 9;
}

/*
 * distance in meters
 * time in minutes
 * speed in km/h
 */
static int average_speed(int distance, int time);

static int
average_speed(int distance, int time) {
    return distance / time * 3.6;
}

static void pymaride(int lines);

static void
pymaride(int lines) {
    int i, j;
    for (i = 0; i < lines; ++i) {
        for (j = 0; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

void
ex7(void) {
    int c, f, speed;
    c = convert_to_c(32);
    f = convert_to_f(0);
    speed = average_speed(1000, 10);
    printf("0C = %dF\n", f);
    printf("32F = %dC\n", c);
    printf("Average speed: %d km/h\n", speed);

    pymaride(5);
}
