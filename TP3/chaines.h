#ifndef _CHAINES_H
#define _CHAINES_H

/* Antécédent : s doit être une chaîne à la C */
/* Rôle : renvoie la longueur de s */
int longueur (const char s[]);

/* Antécédent : s doit être une chaîne à la C */
/* Rôle : renvoie une copie de s */
char *copieChaine (const char s[]);

/* Antécédent : s1 et s2 doivent être des chaînes à la C */
/* Rôle : renvoie s1 + s2 */
char *concateneChaines (const char s1[], const char s2[]);

/* Antécédent : s doit être une chaîne à la C */
/* Rôle : renvoie une copie de s dont les caractères sont en majuscules */
char *miseEnMajuscules (const char s[]);

/* Antécédent : s1 et s2 doivent être des chaînes à la C */
/* Rôle : renvoie un nombre positif si s1 > s2, 0 si s1 = s2, un nombre
 * négatif sinon */
int compareChaines (const char s1[], const char s2[]);

#endif

