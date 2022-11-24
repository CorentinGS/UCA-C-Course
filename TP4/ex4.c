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

#include <stddef.h>
#include <malloc.h>
#include "ex4.h"

static int value(DoubleNode* node);
static DoubleNode* next(DoubleNode* node);
static DoubleNode* prev(DoubleNode* node);
static void add_after(CircularLinkedList* l, DoubleNode* node, DoubleNode* new_node);
static void delete(CircularLinkedList* l, DoubleNode* node);
static void flush(CircularLinkedList* list);
static DoubleNode* head(CircularLinkedList* list);
static DoubleNode* tail(CircularLinkedList* list);

static void list_cat(CircularLinkedList* l1, CircularLinkedList* l2);
static void print(CircularLinkedList* list);

void
ex4(void) {
    CircularLinkedList* list = malloc(sizeof(*list));
    list->sentinel = malloc(sizeof(*list->sentinel));
    list->sentinel->head = NULL;
    list->size = 0;

    DoubleNode* node = malloc(sizeof(*node));
    node->value = 1;
    node->next = NULL;
    node->prev = NULL;

    add_after(list, NULL, node);

    DoubleNode* node2 = malloc(sizeof(*node2));
    node2->value = 2;
    node2->next = NULL;
    node2->prev = NULL;

    add_after(list, node, node2);

    DoubleNode* node3 = malloc(sizeof(*node3));
    node3->value = 3;
    node3->next = NULL;
    node3->prev = NULL;

    add_after(list, node2, node3);

    DoubleNode* node4 = malloc(sizeof(*node4));
    node4->value = 4;
    node4->next = NULL;
    node4->prev = NULL;

    add_after(list, node3, node4);

    DoubleNode* node5 = malloc(sizeof(*node5));
    node5->value = 5;
    node5->next = NULL;
    node5->prev = NULL;

    add_after(list, node4, node5);

    print(list);

    delete (list, node3);

    print(list);

    flush(list);

    /* 2 list to concatenate */
    CircularLinkedList* list2 = malloc(sizeof(*list2));
    list2->sentinel = malloc(sizeof(*list2->sentinel));
    list2->sentinel->head = NULL;
    list2->size = 0;

    DoubleNode* node6 = malloc(sizeof(*node6));
    node6->value = 6;
    node6->next = NULL;
    node6->prev = NULL;

    add_after(list2, NULL, node6);

    DoubleNode* node7 = malloc(sizeof(*node7));
    node7->value = 7;
    node7->next = NULL;
    node7->prev = NULL;

    add_after(list2, node6, node7);

    CircularLinkedList* list3 = malloc(sizeof(*list3));
    list3->sentinel = malloc(sizeof(*list3->sentinel));
    list3->sentinel->head = NULL;
    list3->size = 0;

    DoubleNode* node8 = malloc(sizeof(*node8));
    node8->value = 8;
    node8->next = NULL;
    node8->prev = NULL;

    add_after(list3, NULL, node8);

    list_cat(list2, list3);
    print(list2);
}

static int
value(DoubleNode* node) {
    if (NULL == node) {
        return 0;
    }
    return node->value;
}

static DoubleNode*
next(DoubleNode* node) {
    if (NULL == node) {
        return NULL;
    }
    return node->next;
}

static DoubleNode*
prev(DoubleNode* node) {
    if (NULL == node) {
        return NULL;
    }
    return node->prev;
}

static DoubleNode*
head(CircularLinkedList* l) {
    if (NULL == l) {
        return NULL;
    }

    if (NULL == l->sentinel) {
        return NULL;
    }

    return l->sentinel->head;
}

static DoubleNode*
tail(CircularLinkedList* l) {
    if (NULL == l) {
        return NULL;
    }

    if (NULL == l->sentinel) {
        return NULL;
    }

    DoubleNode* node = l->sentinel->head;
    if (NULL == node) {
        return NULL;
    }

    if (NULL == node->prev) {
        return node;
    }

    return node->prev;
}

static void
add_after(CircularLinkedList* l, DoubleNode* node, DoubleNode* new_node) {
    if (NULL == l) {
        return;
    }

    if (NULL == l->sentinel) {
        return;
    }

    if (NULL == new_node) {
        return;
    }

    if (NULL == node) {
        if (NULL == l->sentinel->head) {
            l->sentinel->head = new_node;
            new_node->next = new_node;
            new_node->prev = new_node;
            l->size++;
            return;
        }

        DoubleNode* head = l->sentinel->head;
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        l->sentinel->head = new_node;
        l->size++;
        return;
    }

    new_node->next = node->next;
    new_node->prev = node;
    node->next->prev = new_node;
    node->next = new_node;
    l->size++;
}

static void delete(CircularLinkedList* l, DoubleNode* node) {
    if (NULL == l) {
        return;
    }

    if (NULL == l->sentinel) {
        return;
    }

    if (NULL == node) {
        return;
    }

    if (NULL == l->sentinel->head) {
        return;
    }

    if (l->sentinel->head == node) {
        if (node->next == node) {
            l->sentinel->head = NULL;
            l->size--;
            return;
        }

        l->sentinel->head = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    l->size--;

    if (NULL != node) {
        free(node);
    }
}

static void
flush(CircularLinkedList* l) {
    if (NULL == l) {
        return;
    }

    if (NULL == l->sentinel) {
        return;
    }

    if (NULL == l->sentinel->head) {
        return;
    }

    DoubleNode* node = l->sentinel->head;
    DoubleNode* next = node->next;
    while (node != next) {
        DoubleNode* tmp = next;
        next = next->next;
        free(tmp);
    }

    free(node);
    l->sentinel->head = NULL;
    l->size = 0;
}

static void
list_cat(CircularLinkedList* l1, CircularLinkedList* l2) {
    if (NULL == l1) {
        return;
    }

    if (NULL == l2) {
        return;
    }

    if (NULL == l1->sentinel) {
        return;
    }

    if (NULL == l2->sentinel) {
        return;
    }

    if (NULL == l1->sentinel->head) {
        l1->sentinel->head = l2->sentinel->head;
        l1->size = l2->size;
        l2->sentinel->head = NULL;
        l2->size = 0;
        return;
    }

    if (NULL == l2->sentinel->head) {
        return;
    }

    DoubleNode* head1 = l1->sentinel->head;
    DoubleNode* head2 = l2->sentinel->head;
    head1->prev->next = head2;
    head2->prev->next = head1;
    DoubleNode* tmp = head1->prev;
    head1->prev = head2->prev;
    head2->prev = tmp;
    l1->size += l2->size;
    l2->sentinel->head = NULL;
    l2->size = 0;
}

static void
print(CircularLinkedList* l) {
    if (NULL == l) {
        return;
    }

    if (NULL == l->sentinel) {
        return;
    }

    if (NULL == l->sentinel->head) {
        return;
    }

    DoubleNode* node = l->sentinel->head;
    DoubleNode* next = node->next;
    printf("%d ", node->value);
    while (node != next) {
        printf("%d ", next->value);
        next = next->next;
    }

    printf("\n");
}
