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

#include "utils.h"

struct double_node_t {
    int value;
    struct double_node_t* next;
    struct double_node_t* prev;
};

typedef struct double_node_t DoubleNode;

struct sentinel_t {
    DoubleNode* head;
};

typedef struct sentinel_t Sentinel;

typedef struct {
    Sentinel* sentinel;
    int size;
} CircularLinkedList;

extern void ex4(void);
