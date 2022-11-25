

#include <stdio.h>
#include "heures.h"
#include "pointeurs.h"
#include "pointeurbis.h"
#include "caracteres.h"

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

char* my_strcat(char* dest, const char* src);
char* my_strcpy(char* dest, const char* src);

int
main() {
    /*
    ex1();

    pointeur1();
    pointeur2();
*/

    ex3();
    printf("\n");

    char str1[100] = "Hello";
    char str2[100] = "World";
    char* mystr = my_strcat(str1, str2);
    printf("%s\n", mystr);

    char str3[100] = "Hello";
    char str4[100] = "World";
    char* mystr2 = my_strcpy(str3, str4);
    printf("%s", mystr2);

    return 0;
}

char*
my_strcat(char* dest, const char* src) {
    char* p = dest;
    while (*p != '\0') {
        p++;
    }
    while (*src != '\0') {
        *p = *src++;
        p++;
    }
    *p = '\0';
    return dest;
}

char*
my_strcpy(char* dest, const char* src) {
    char* p = dest;
    while (*src != '\0') {
        *p = *src++;
        p++;
    }
    *p = '\0';
    return dest;
}
