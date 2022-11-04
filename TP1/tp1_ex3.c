

#include <stdio.h>
#include "tp1_ex3.h"

static void question1(void);

static void
question1(void) {
    float fi = 10.1f;
    float fj = 10.2f;

    printf("%.16f %.16f %.16f %d %d\n", fi, fj, fi + fj, (int) fi, fi);
    printf("%.32f %.32f %.32f %d %d\n", fi, fj, fi + fj, (int) fi, fi);
    printf("%.8f %.8f %.8f %d %d\n", fi, fj, fi + fj, (int) fi, fi);
    printf("%.2f %.2f %.2f %.2f\n", 5 / 2, 5.0 / 2, 5 / 2.0, 5.0 / 2.0);
}

static void question2(void);

static void
question2(void) {
    /* Display int from 1 to 100 with 10 per line */
    int i;
    for (i = 1; i <= 100; i++) {
        printf("%d ", i);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
}

static void question3(void);

void
exercice3(void) {
    question1();
    question2();
}