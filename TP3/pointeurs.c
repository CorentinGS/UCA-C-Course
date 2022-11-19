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
#include "pointeurs.h"

int pointeur1 (void) {
	int j = 2;
	int i = 100;
	int *pi = &i;

	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	*pi = 1000;
	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	pi[1] = -4; /* mais où va-t-on? */
	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	pi++; /* et là? */
	*pi = -100;
	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	return 0;
}
