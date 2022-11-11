#include <assert.h>
#include <stdio.h>
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

static unsigned int get_bit(unsigned int x, int pos);
static unsigned int set_bit(unsigned int x, int pos);
static unsigned int clear_bit(unsigned int x, int pos);
static unsigned int toggle_bit(unsigned int x, int pos);
static unsigned int define_bit(unsigned int x, int pos, int val);
static unsigned int convert_to_bin(unsigned int n);

static unsigned int bin_product(unsigned int binary1, unsigned int b);
static unsigned int bin_division(unsigned int binary1, unsigned int b);
static void extract_bits(unsigned int x);
static void mirror_bin(unsigned int i);

static void test_get_bit(void);
static void test_set_bit(void);
static void test_clear_bit(void);
static void test_toggle_bit(void);
static void test_define_bit(void);
static void test_bin_product(void);

#define TRUE  1
#define FALSE 0

#define TEST  1

void
ex3(void) {
    if (TEST) {
        test_get_bit();
        test_set_bit();
        test_clear_bit();
        test_toggle_bit();
        test_define_bit();
        test_bin_product();
    }
    convert_to_bin(10);
    mirror_bin(00000001);
    extract_bits(0b1111111111110000000000);
}

static unsigned int
get_bit(unsigned int x, int pos) {
    return (x >> pos) & 1;
}

static unsigned int
set_bit(unsigned int x, int pos) {
    return x | (1 << pos);
}

static unsigned int
clear_bit(unsigned int x, int pos) {
    return x & ~(1 << pos);
}

static unsigned int
toggle_bit(unsigned int x, int pos) {
    return x ^ (1 << pos);
}

static unsigned int
define_bit(unsigned int x, int pos, int val) {
    return (x & ~(1 << pos)) | (val << pos);
}

static void
test_get_bit(void) {
    unsigned int x = 0b10101010;
    assert(get_bit(x, 0) == 0);
    assert(get_bit(x, 1) == 1);
    assert(get_bit(x, 2) == 0);
    assert(get_bit(x, 3) == 1);
    assert(get_bit(x, 4) == 0);
}

static void
test_set_bit(void) {
    unsigned int x = 0b10101010;
    assert(set_bit(x, 0) == 0b10101011);
    assert(set_bit(x, 1) == 0b10101010);
    assert(set_bit(x, 2) == 0b10101110);
    assert(set_bit(x, 3) == 0b10101010);
    assert(set_bit(x, 4) == 0b10111010);
}

static void
test_clear_bit(void) {
    unsigned int x = 0b10101010;
    assert(clear_bit(x, 0) == 0b10101010);
    assert(clear_bit(x, 1) == 0b10101000);
    assert(clear_bit(x, 2) == 0b10101010);
    assert(clear_bit(x, 3) == 0b10100010);
}

static void
test_toggle_bit(void) {
    unsigned int x = 0b10101010;
    assert(toggle_bit(x, 0) == 0b10101011);
    assert(toggle_bit(x, 1) == 0b10101000);
    assert(toggle_bit(x, 2) == 0b10101110);
    assert(toggle_bit(x, 3) == 0b10100010);
}

static void
test_define_bit(void) {
    unsigned int x = 0b10101010;
    assert(define_bit(x, 0, 0) == 0b10101010);
    assert(define_bit(x, 1, 0) == 0b10101000);
    assert(define_bit(x, 2, 0) == 0b10101010);
    assert(define_bit(x, 3, 0) == 0b10100010);
    assert(define_bit(x, 0, 1) == 0b10101011);
    assert(define_bit(x, 1, 1) == 0b10101010);
    assert(define_bit(x, 2, 1) == 0b10101110);
    assert(define_bit(x, 3, 1) == 0b10101010);
}

/* Convert int to binary number */
static unsigned int
convert_to_bin(unsigned int n) {
    if (n / 2 != 0) {
        convert_to_bin(n / 2);
    }
    printf("%d", n % 2);
    return n % 2;
}

/* Binary product of 2 digits*/
static unsigned int
bin_product(unsigned int binary1, unsigned int binary2) {
    /* Product of binary1 and binary2 */
    int result = 0;
    int i, taille;

    taille = 8;

    for (i = 0; i < taille; i++) {
        if (get_bit(binary2, i) == 1) {
            result = result + (binary1 << i);
        }
    }

    printf("%d\n\n", result);

    return result;
}

/* Binary division of 2 digits*/
static unsigned int
bin_division(unsigned int binary1, unsigned int binary2) {
    /* Division of binary1 and binary2 */
    unsigned int result = 0;
    int i, taille;

    taille = 4;

    for (i = 0; i < taille; i++) {
        if (get_bit(binary2, i) == 1) {
            result = result + (binary1 >> i);
        }
    }

    printf("%d\n\n", result);

    return result;
}

static void
test_bin_product(void) {
    int a = 0b00001010;
    bin_product(a, a);
    unsigned int b = 0b00000100;
    unsigned int c = 0b00000010;
    bin_division(b, c);
}

static void
mirror_bin(unsigned int i) {
    /* Display mirror of binary number */
    /* if n = 1010 then display 0101 */
    /* taille is log of n */

    printf("\n");
    printf("n = %d         ", i);
    int j;
    int taille = 4;
    for (j = 0; j < taille; j++) {
        printf("%d", get_bit(i, j));
    }

    printf(" base %d \n", taille);
}

static void
extract_bits(unsigned int x) {

    printf("\n");
    /* Extract 10 first bits of x */
    int i;
    for (i = 0; i < 10; ++i) {
        printf("%d", get_bit(x, i));
    }

    printf("\n");

    /* Extract 10 last bits of x */
    for (i = 0; i < 10; ++i) {
        printf("%d", get_bit(x, 31 - i));
    }

    /* Extract 12 middle bits of x */

    printf("\n");

    for (i = 10; i < 22; ++i) {
        printf("%d", get_bit(x, i));
    }
}