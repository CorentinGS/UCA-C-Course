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
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void affCar (char c) {
	printf("%c\n", c);
}

void majCar (char c) {
	c = toupper(c);
}

int majCarF (char c) {
	return toupper(c);
}

void majCarP (char *c) {
	printf("1 dans majCarP, c = %p, *c = %c\n", c, *c);
	*c = toupper(*c);
	printf("2 dans majCarP, c = %p, *c = %c\n", c, *c);
}

void majCarPbis (char *c) {
	printf("1 dans majCarPbis, c = %p, *c = %c\n", c, *c);
	c = malloc(sizeof(char));
	*c = 'a';
	printf("2 dans majCarPbis, c = %p, *c = %c\n", c, *c);
}

void ecrire_chaine(char *chaine);

void ecrire_chaine(char *chaine) {
        while(*chaine != '\0') {
                printf("%c", *chaine);
                ++chaine;
        }
}

#define TOLOWER(c) ((c) | 0x20)
#define TOUPPER(c) ((c) & ~0x20)

void upper_chaine(char *chaine);

void upper_chaine(char *chaine) {
        while(*chaine != '\0') {
            /* exclude non-alphabetic characters */
                if ((*chaine >= 'a' && *chaine <= 'z') || (*chaine >= 'A' && *chaine <= 'Z')) {
                        *chaine = TOUPPER(*chaine);
                }
                ++chaine;
        }
}

void upper_chaine_const(const char *chaine);

void upper_chaine_const(const char *chaine) {
    /* Copy the string to a buffer */
        char *buffer = malloc(strlen(chaine) + 1);
        strcpy(buffer, chaine);
        upper_chaine(buffer);

        printf("%s", buffer);

        free(buffer);

}

int ex3 (void) {
	char car = 'b';

	affCar(car);
	majCar(car); affCar(car);
	affCar(majCarF(car)); affCar(car);
	majCarP(&car); affCar(car);
	majCarPbis(&car); affCar(car);

        char chaine[] = "Bonjour tout le monde!";
        upper_chaine(chaine);
        ecrire_chaine( chaine);
        printf("\n");
        upper_chaine_const("Vive les pâtes");

	return 0;
}


