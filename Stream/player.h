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

#ifndef TP_C_PLAYER_H
#define TP_C_PLAYER_H

enum Couleur { NONE, ROUGE, BLEU, VERT, JAUNE, NOIR, BLANC };

typedef enum Couleur Couleur;

struct Player {
    int pv;
    char* nom;
    int score;
    Couleur couleur;
};

typedef struct Player Player;

extern void init_game(void);

#endif