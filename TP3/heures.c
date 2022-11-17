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
#include <time.h>
#include "heures.h"

Heure
heureLocale(void) {
    Heure h;
    /* Get local time */
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    /* Set heure */
    h.h = tm.tm_hour;
    h.m = tm.tm_min;
    h.s = tm.tm_sec;

    return h;
}

Heure
saisirHeure(void) {
    Heure h;
    printf("Entrez l'heure: ");
    scanf("%hd", &h.h);
    printf("Entrez les minutes: ");
    scanf("%hd", &h.m);
    printf("Entrez les secondes: ");
    scanf("%hd", &h.s);
    return h;
}

Heure
mettreHeure(short h, short m, short s) {
    Heure heure;
    heure.h = h;
    heure.m = m;
    heure.s = s;
    return heure;
}

void
afficherHeure(Heure h, Systeme s) {
    /* Hour in 12h format */
    if (s == 12) {
        if (h.h > 12) {
            h.h -= 12;
            printf("%hd:%hd:%hd PM  ", h.h, h.m, h.s);
        }
    } else {
        printf("%hd:%hd:%hd AM  ", h.h, h.m, h.s);
    }
}

long int
heure2sec(Heure h) {
    long int sec = h.h * 3600 + h.m * 60 + h.s;
    return sec;
}

Heure
sec2heure(long int s) {
    Heure h;
    h.h = s / 3600;
    h.m = (s % 3600) / 60;
    h.s = (s % 3600) % 60;
    return h;
}

Heure
ajouterHeure(Heure h1, Heure h2) {
    Heure h;
    h.h = h1.h + h2.h;
    h.m = h1.m + h2.m;
    h.s = h1.s + h2.s;
    return h;
}

Heure
soustraireHeure(Heure h1, Heure h2) {
    Heure h;
    h.h = h1.h - h2.h;
    h.m = h1.m - h2.m;
    h.s = h1.s - h2.s;
    return h;
}

void
ex1(void) {
    Heure h1 = heureLocale();
    Heure h2 = saisirHeure();
    Heure h3 = mettreHeure(12, 30, 00);
    afficherHeure(h1, 24);
    afficherHeure(h2, 24);
    afficherHeure(h3, 12);
    printf("%ld\n", heure2sec(h1));
    Heure h4 = sec2heure(heure2sec(h1));
    afficherHeure(h4, 24);
    Heure h5 = ajouterHeure(h1, h2);
    afficherHeure(h5, 24);
    Heure h6 = soustraireHeure(h1, h2);
    afficherHeure(h6, 24);
}
