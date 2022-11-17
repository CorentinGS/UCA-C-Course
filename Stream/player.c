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
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "player.h"

#define TAILLE_NOM 20

static void create_player(Player* player);
static void display_player(Player* player);
static char* get_couleur(Couleur couleur);
void logic(Player* player);
static int input_color(Couleur* couleur);
void chess_guesser(Player* player);

static void
create_player(Player* player) {
    player->pv = 3;
    player->score = 0;

    player->nom = malloc(sizeof(char) * TAILLE_NOM);

    printf("Entrez votre nom: ");

    fgets(player->nom, TAILLE_NOM, stdin);

    printf("%s\n", player->nom);

    printf("Entrez votre couleur: ");
    printf("1. Rouge\n");
    printf("2. Bleu\n");
    printf("3. Vert\n");
    printf("4. Jaune\n");
    printf("5. Noir\n");
    printf("6. Blanc\n");

    Couleur couleur;
    int err;
    do {
        err = input_color(&couleur);
    } while (err);

    player->couleur = couleur;
}

static int
input_color(Couleur* couleur) {
    if (scanf("%d", couleur) != 1) {
        while ((*couleur = getchar()) != '\n' && *couleur != EOF) {}
        printf("Erreur de saisie\n");
        return 1;
    }
    return 0;
}

static char*
get_couleur(Couleur couleur) {
    switch (couleur) {
        case ROUGE:
            return "Rouge";
        case BLEU:
            return "Bleu";
        case VERT:
            return "Vert";
        case JAUNE:
            return "Jaune";
        case NOIR:
            return "Noir";
        case BLANC:
            return "Blanc";
        default:
            return "Inconnu";
    }
}

static void
display_player(Player* player) {
    printf("\n");
    printf("Nom: %s\n", player->nom);
    printf("Couleur: %s\n", get_couleur(player->couleur));
    printf("Score: %d\n", player->score);
    printf("PV: %d\n", player->pv);
}

void
init_game(void) {
    Player* player = malloc(sizeof(Player));

    create_player(player);
    display_player(player);

    while (player->pv > 0 && player->score < 4) {
        chess_guesser(player);
    }
}

void
chess_guesser(Player* player) {
    /* array of string */
    char* french[4] = {"e4", "e6", "d4", "d5"};

    const int size = 3;

    printf("La défense française !\n");
    printf("1. ");
    char* input = malloc(sizeof(char) * size);
    while ((*input = getchar()) != '\n' && *input != EOF) {}

    fgets(input, size, stdin);
    strcmp(input, french[0]) == 0 ? player->score++ : exit(1);
    printf("1. ...  ");
    while ((*input = getchar()) != '\n' && *input != EOF) {}

    fgets(input, size, stdin);
    strcmp(input, french[1]) == 0 ? player->score++ : exit(1);
    printf("2. ");
    while ((*input = getchar()) != '\n' && *input != EOF) {}

    fgets(input, size, stdin);
    strcmp(input, french[2]) == 0 ? player->score++ : exit(1);
    printf("2. ...  ");
    while ((*input = getchar()) != '\n' && *input != EOF) {}

    fgets(input, size, stdin);
    strcmp(input, french[3]) == 0 ? player->score++ : exit(1);

    free(input);
    printf("Bravo !\n");
}

void
logic(Player* player) {
    int choix;

    srand(time(NULL));

    /* Choix random entre 0 et 1 */
    choix = rand() % 2;

    printf("Choix entre 0 et 1 ?");

    int choix_joueur;
    if (scanf("%d", &choix_joueur) != 1) {
        while ((choix_joueur = getchar()) != '\n' && choix_joueur != EOF) {}
        printf("Erreur de saisie\n");
        return;
    }

    if (choix_joueur == choix) {
        player->score += 1;
        printf("Bravo, vous avez gagné ! (◠﹏◠)\n");
    } else {
        player->pv -= 1;
        printf("Dommage, vous avez perdu ! ( ͡° ͜ʖ ͡°)\n");
    }
}