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
#include <assert.h>
#include "ex2.h"

#define IS_GREATER(a, b) ((a > b) ? (TRUE) : (FALSE))
#define IS_LOWER(a, b)   (!IS_GREATER(a, b))

static void test_value();
static void test_next();
static void test_first();
static void test_last();
static void test_add_first();
static void test_add_last();
static void test_add_after();
static void test_remove_first();
static void test_remove_last();
static void test_remove_after();
static void test_remove_all();
static void test_size();
static void test_is_empty();
static void test_merge();

void
ex2() {
    printf(ANSI_COLOR_YELLOW "➡️ testing linked list........." ANSI_COLOR_RESET);

    test_value();
    test_next();
    test_first();
    test_last();
    test_add_first();
    test_add_last();
    test_add_after();
    test_remove_first();
    test_remove_last();
    test_remove_after();
    test_remove_all();
    test_size();
    test_is_empty();
    test_merge();

    printf(ANSI_COLOR_GREEN "OK \n" ANSI_COLOR_RESET);
}

/******************************************************************************/

static void
test_merge() {
    LinkedList l1 = {NULL, NULL};
    LinkedList l2 = {NULL, NULL};

    add_last(&l1, 1);
    add_last(&l1, 2);
    add_last(&l1, 3);
    add_last(&l1, 4);
    add_last(&l1, 5);

    add_last(&l2, 6);
    add_last(&l2, 7);
    add_last(&l2, 8);
    add_last(&l2, 9);
    add_last(&l2, 10);

    LinkedList l3 = merge(&l1, &l2);

    assert(size(&l3) == 10);
    assert(value(first(&l3)) == 1);
    assert(value(next(first(&l3))) == 2);
    assert(value(next(next(first(&l3)))) == 3);
    assert(value(next(next(next(first(&l3))))) == 4);
    assert(value(next(next(next(next(first(&l3)))))) == 5);
    assert(value(next(next(next(next(next(first(&l3))))))) == 6);
    assert(value(next(next(next(next(next(next(first(&l3)))))))) == 7);
    assert(value(next(next(next(next(next(next(next(first(&l3))))))))) == 8);
    assert(value(next(next(next(next(next(next(next(next(first(&l3)))))))))) == 9);
    assert(value(last(&l3)) == 10);
    flush(&l3);
    flush(&l1);
    flush(&l2);
}

static void
test_value() {
    Node n = {NULL, 41};
    assert(value(&n) == 41);
}

static void
test_next() {
    Node n1 = {NULL, 41};
    Node n2 = {NULL, 41};
    n1.next = &n2;
    assert(next(&n1) == &n2);
}

static void
test_first() {
    LinkedList l = {NULL, NULL};
    assert(first(&l) == NULL);
    add_first(&l, 41);
    assert(first(&l) != NULL);
    assert(value(first(&l)) == 41);
    flush(&l);
}

static void
test_last() {
    LinkedList l = {NULL, NULL};
    assert(last(&l) == NULL);
    add_last(&l, 41);
    assert(last(&l) != NULL);
    assert(value(last(&l)) == 41);
    add_first(&l, 42);
    assert(value(last(&l)) == 41);
    add_last(&l, 43);
    assert(value(last(&l)) == 43);
    flush(&l);
}

static void
test_add_first() {
    LinkedList l = {NULL, NULL};
    add_first(&l, 41);
    assert(first(&l) != NULL);
    assert(value(first(&l)) == 41);
    assert(last(&l) != NULL);
    assert(value(last(&l)) == 41);
    add_first(&l, 42);
    assert(value(first(&l)) == 42);
    assert(value(last(&l)) == 41);
    flush(&l);
}

static void
test_add_last() {
    LinkedList l = {NULL, NULL};
    add_last(&l, 41);
    assert(first(&l) != NULL);
    assert(value(first(&l)) == 41);
    assert(last(&l) != NULL);
    assert(value(last(&l)) == 41);
    add_last(&l, 42);
    assert(value(first(&l)) == 41);
    assert(value(last(&l)) == 42);
    flush(&l);
}

static void
test_add_after() {
    LinkedList l = {NULL, NULL};
    add_last(&l, 41);
    add_last(&l, 42);
    add_last(&l, 43);
    add_after(&l, first(&l), 44);
    assert(value(first(&l)) == 41);
    assert(value(next(first(&l))) == 44);
    assert(value(next(next(first(&l)))) == 42);
    flush(&l);
}

static void
test_remove_first() {
    LinkedList l = {NULL, NULL};
    add_first(&l, 41);
    assert(first(&l) != NULL);
    assert(value(first(&l)) == 41);
    assert(last(&l) != NULL);
    assert(value(last(&l)) == 41);
    delete_first(&l);
    assert(first(&l) == NULL);
    assert(last(&l) == NULL);
    add_first(&l, 42);
    assert(value(first(&l)) == 42);
    assert(value(last(&l)) == 42);
    delete_first(&l);
    assert(first(&l) == NULL);
    assert(last(&l) == NULL);
    flush(&l);
}

static void
test_remove_last() {
    LinkedList l = {NULL, NULL};
    add_last(&l, 41);
    assert(first(&l) != NULL);
    assert(value(first(&l)) == 41);
    assert(last(&l) != NULL);
    assert(value(last(&l)) == 41);
    delete_last(&l);
    assert(first(&l) == NULL);
    assert(last(&l) == NULL);
    add_last(&l, 42);
    assert(value(first(&l)) == 42);
    assert(value(last(&l)) == 42);
    delete_last(&l);
    assert(first(&l) == NULL);
    assert(last(&l) == NULL);
    flush(&l);
}

static void
test_remove_after() {
    LinkedList l = {NULL, NULL};
    add_last(&l, 41);
    add_last(&l, 42);
    add_last(&l, 43);
    assert(value(first(&l)) == 41);
    assert(value(last(&l)) == 43);
    delete_after(&l, first(&l));
    assert(value(first(&l)) == 41);
    assert(value(next(first(&l))) == 43);
    assert(value(last(&l)) == 43);
    delete_after(&l, first(&l));
    assert(value(first(&l)) == 41);
    assert(value(last(&l)) == 41);
    flush(&l);
}

static void
test_remove_all() {
    LinkedList l = {NULL, NULL};
    add_last(&l, 41);
    add_last(&l, 42);
    add_last(&l, 43);
    assert(value(first(&l)) == 41);
    assert(value(last(&l)) == 43);
    flush(&l);
    assert(first(&l) == NULL);
    assert(last(&l) == NULL);
    assert(is_empty(&l));
    flush(&l);
}

static void
test_is_empty() {
    LinkedList l = {NULL, NULL};
    assert(is_empty(&l));
    add_last(&l, 41);
    assert(!is_empty(&l));
    delete_first(&l);
    assert(is_empty(&l));
    flush(&l);
}

static void
test_size() {
    LinkedList l = {NULL, NULL};
    assert(size(&l) == 0);
    add_last(&l, 41);
    assert(size(&l) == 1);
    add_last(&l, 42);
    assert(size(&l) == 2);
    add_last(&l, 43);
    assert(size(&l) == 3);
    delete_first(&l);
    assert(size(&l) == 2);
    delete_first(&l);
    assert(size(&l) == 1);
    delete_first(&l);
    assert(size(&l) == 0);
    flush(&l);
}

/******************************************************************************/

int
value(Node* n) {
    return n->value;
}

Node*
next(Node* n) {
    if (NULL == n) {
        return NULL;
    }
    if (NULL == n->next) {
        return NULL;
    }
    return n->next;
}

Node*
first(LinkedList* l) {
    if (NULL == l->first) {
        return NULL;
    }
    return l->first;
}

Node*
last(LinkedList* l) {
    if (NULL == l->last) {
        return NULL;
    }
    return l->last;
}

int
is_empty(LinkedList* l) {
    if (NULL == l->first) {
        return TRUE;
    }
    return FALSE;
}

void
add_first(LinkedList* l, int value) {
    Node* n;
    n = malloc(sizeof(*n));
    n->value = value;
    n->next = l->first;
    l->first = n;
    if (NULL == l->last) {
        l->last = n;
    }
}

void
add_last(LinkedList* l, int value) {
    Node* n;
    n = malloc(sizeof(*n));
    n->value = value;
    n->next = NULL;
    if (NULL == l->last) {
        l->first = n;
        l->last = n;
    } else {
        l->last->next = n;
        l->last = n;
    }
}

void
add_after(LinkedList* l, Node* n, int value) {
    Node* new = malloc(sizeof(*n));
    new->value = value;
    new->next = n->next;
    n->next = new;
    if (l->last == n) {
        l->last = new;
    }
}

void
delete_first(LinkedList* l) {
    Node* n;

    if (NULL == l->first) {
        return;
    }
    n = l->first;
    l->first = n->next;
    if (l->last == n) {
        l->last = NULL;
    }
    if (NULL != n) {
        free(n);
    }
}

void
delete_last(LinkedList* l) {
    Node* n;
    Node* tmp;

    if (NULL == l->last) {
        return;
    }
    n = l->first;
    if (l->first == l->last) {
        l->first = NULL;
        l->last = NULL;
    } else {
        while (n->next != l->last) {
            n = n->next;
        }
        l->last = n;
        tmp = n->next;
        n->next = NULL;
        n = tmp;
    }
    if (NULL != n) {
        free(n);
    }
}

void
delete_after(LinkedList* l, Node* n) {
    Node* tmp;

    if (NULL == n->next) {
        return;
    }
    tmp = n->next;
    n->next = tmp->next;
    if (l->last == tmp) {
        l->last = n;
    }
    if (NULL != tmp) {
        free(tmp);
    }
}

void
flush(LinkedList* l) {
    Node* n = l->first;
    while (NULL != n) {
        Node* tmp;
        tmp = n;
        n = n->next;
        if (NULL != tmp) {
            free(tmp);
        }
    }

    l->first = NULL;
    l->last = NULL;
}

int
size(LinkedList* l) {
    int size;
    Node* n;
    size = 0;
    n = l->first;
    while (NULL != n) {
        ++size;
        n = n->next;
    }

    return size;
}

LinkedList
merge(LinkedList* l1, LinkedList* l2) {
    LinkedList l3 = {NULL, NULL};
    Node* n1 = l1->first;
    Node* n2 = l2->first;
    while (NULL != n1 && NULL != n2) {
        if (IS_LOWER(n1, n2)) {
            add_last(&l3, n1->value);
            n1 = n1->next;
        } else {
            add_last(&l3, n2->value);
            n2 = n2->next;
        }
    }

    while (NULL != n1) {
        add_last(&l3, n1->value);
        n1 = n1->next;
    }

    while (NULL != n2) {
        add_last(&l3, n2->value);
        n2 = n2->next;
    }

    return l3;
}

LinkedList
merge_destruct(const LinkedList* l1, LinkedList* l2) {
    LinkedList l3 = {NULL, NULL};
    Node* n1 = l1->first;
    Node* n2 = l2->first;
    while (NULL != n1 && NULL != n2) {
        if (IS_LOWER(n1, n2)) {
            add_last(&l3, n1->value);
            n1 = n1->next;
        } else {
            add_last(&l3, n2->value);
            n2 = n2->next;
        }
    }

    while (NULL != n1) {
        add_last(&l3, n1->value);
        n1 = n1->next;
    }

    while (NULL != n2) {
        add_last(&l3, n2->value);
        n2 = n2->next;
    }

    flush(l2);

    return l3;
}

void
print(LinkedList* l) {
    Node* n = l->first;
    while (NULL != n) {
        printf("%d ", n->value);
        n = n->next;
    }
    printf(" (size: %d) ", size(l));
    printf(" (first: %d) ", l->first->value);
    printf(" (last: %d) ", l->last->value);
    printf("\n");
}
