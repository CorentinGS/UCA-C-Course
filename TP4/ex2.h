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

struct node_t {
    struct node_t* next;
    int value;
};

typedef struct node_t Node;

typedef struct {
    Node* first;
    Node* last;
} LinkedList;

extern void ex2(void);
int value(Node* n);
Node* next(Node* n);
Node* first(LinkedList* l);
Node* last(LinkedList* l);
int is_empty(LinkedList* l);
void add_first(LinkedList* l, int value);
void add_last(LinkedList* l, int value);
void add_after(LinkedList* l, Node* n, int value);
void delete_first(LinkedList* l);
void delete_last(LinkedList* l);
void delete_after(LinkedList* l, Node* n);
void flush(LinkedList* l);
int size(LinkedList* l);
void print(LinkedList* l);
LinkedList merge(LinkedList* l1, LinkedList* l2);
LinkedList merge_destruct(const LinkedList* l1, LinkedList* l2);
