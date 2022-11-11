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

#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include "ex1.h"

static void saisie_tab(int* tab, int n);
static void display_tab(int* tab, int n);
static int char_exists(char a, const char* s);
static int is_valid(const char* s);

static void test_char_exists(void);
static void test_is_valid(void);

#define TRUE  1
#define FALSE 0

#define TEST  1

void
ex1(void) {
    int n;
    int* tab;
    printf("Entrez la taille du tableau: ");
    scanf("%d", &n);
    tab = malloc(n * sizeof(int));
    /*
    saisie_tab(tab, n);
    display_tab(tab, n);
     */
    free(tab);
    if (TEST) {
        test_char_exists();
        test_is_valid();
    }
}

/* Read int from sdtin */
static void
saisie_tab(int* tab, int n) {
    int x;
    for (x = 0; x < n; ++x) {
        printf("Entrez un entier: ");
        scanf("%d", &tab[x]);
    }
}

static void
display_tab(int* tab, int n) {
    int x;
    for (x = 0; x < n; ++x) {
        printf("%d ", tab[x]);
    }
    printf("\n");
}

/* Check if char a exists in string s */
static int
char_exists(char a, const char* s) {
    int x;
    for (x = 0; s[x] != '\0'; ++x) {
        if (s[x] == a) {
            return TRUE;
        }
    }
    return FALSE;
}

/* Check if string contains a valid number multiple of 3 */
static int
is_valid(const char* s) {
    int x;
    size_t status;
    for (x = 0; s[x] != '\0'; ++x) {
        if (char_exists(s[x], "0123456789")) {
            if (atoi(s) % 3 == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

static void
test_char_exists(void) {
    assert(char_exists('a', "abc") == TRUE);
    assert(char_exists('a', "def") == FALSE);
    assert(char_exists('a', "a") == TRUE);
    assert(char_exists('a', "b") == FALSE);
}

static void
test_is_valid(void) {
    assert(is_valid("123") == TRUE);
    assert(is_valid("456") == TRUE);
    assert(is_valid("789") == TRUE);
    assert(is_valid("abc") == FALSE);
    assert(is_valid("def") == FALSE);
    assert(is_valid("ghi") == FALSE);
    assert(is_valid("123abc") == TRUE);
    assert(is_valid("abc123") == TRUE);
    assert(is_valid("123456") == TRUE);
    assert(is_valid("456789") == TRUE);
    assert(is_valid("789123") == TRUE);
    assert(is_valid("123456789") == TRUE);
}
