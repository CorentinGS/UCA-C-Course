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

#ifndef _HEURES_H
#define _HEURES_H

#define HEURES 24
#define MINUTES 60
#define SECONDES 60

struct heure {
	short h; /* les heures 0 .. HEURES-1 */
	short m; /* les minutes 0 .. MINUTES-1 */
	short s; /* les secondes 0 .. SECONDES-1 */ 
};
typedef struct heure Heure;

/* syst24 = système 24h, syst12 = système 12h (am, pm) */
typedef enum {syst24, syst12} Systeme;

/* Rôle : renvoie l'heure actuelle de la machine sur laquelle
tourne l'exécutable */
/* POUR L'INSTANT, VOUS RENVOYEZ 0h0mn0s */
Heure heureLocale (void);

/* Rôle : renvoie l'heure lue sur l'entrée standard en système 24h
(les champs respectent les contraintes) */
Heure saisirHeure (void);

/* Rôle : renvoie l'heure à partir des données transmises en paramètres,
et si les données ne respectent pas les contraintes, renvoie 0h0mn0s */
Heure mettreHeure (short h, short m, short s);

/* Antécédent : h heure valide */
/* Rôle : écrit sur la sortie standard l'heure h sous la forme du système s */
void afficherHeure (Heure h, Systeme s);

/* Antécédent : h heure valide */
/* Rôle : renvoie le nombre de secondes correspondant à l'heure h */
long int heure2sec (Heure h);

/* Rôle : renvoie l'heure correspondant au nombre de secondes
(0h0mn0s si problème) */
Heure sec2heure (long int s);

/* Antécédent : h1 et h2 heures valides */
/* Rôle : renvoie h1 + h2 */
Heure ajouterHeure (Heure h1, Heure h2);

/* Antécédent : h1 et h2 heures valides */
/* Rôle : renvoie h1 - h2 */
Heure soustraireHeure (Heure h1, Heure h2);

extern void ex1(void);

#endif
