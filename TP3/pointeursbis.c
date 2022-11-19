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

#include "pointeurbis.h"


void init (int t[], int n, int v) {
	int i;

	for (i = 0; i < n; i++)
		t[i] = v;
}

void imp (char *nom, int t[], int n) {
	int i;

	printf("%s = {", nom);
	if (n > 0) {
		printf("%d", t[0]);
		for (i = 1; i < n; i++)
			printf(", %d", t[i]);
	}
	printf("}\n");
}

#define NB1 5
#define NB2 3

int pointeur2 (void) {
	int t1[NB1], t2[NB2];
	int *pi = t2;

	printf("pi = %p, t1 = %p, t2 = %p\n", pi, t1, t2);
	printf("&pi = %p, &t1 = %p, &t2 = %p\n", &pi, &t1, &t2);
	imp("t1", t1, NB1);
	imp("t2", t2, NB2);
	init(t1, NB1, 10);
	init(t2, NB2, -10);
	imp("t1", t1, NB1);
	imp("t2", t2, NB2);
	init(pi, NB1 + NB2, 2); /* belle pagaille */
	imp("pi", pi, NB1 + NB2);
	imp("t1", t1, NB1);
	imp("t2", t2, NB2);
	return 0;
}
