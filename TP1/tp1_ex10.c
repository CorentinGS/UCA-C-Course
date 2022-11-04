#include <stdio.h>
#include "tp1_ex10.h"

#define TRUE 1
#define FALSE 0

int is_prime(int n);

int is_perfect(int n);

void find_k_first_prime(int k);

void find_k_first_perfect(int min, int max);

int is_doublon(int k);

void find_k_first_doublon(int min, int max);

int
is_prime(int n) {
    int i;
    if (n < 2) {
        return FALSE;
    }
    for (i = 2; i < n; ++i) {
        if (n % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void
find_k_first_prime(int k) {
    int i, n;
    n = 0;
    i = 0;
    while (n < k) {
        if (is_prime(i)) {
            printf("%d ", i);
            ++n;
        }
        ++i;
    }
}

int
is_perfect(int n) {
    int i, sum;
    sum = 0;
    for (i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void
find_k_first_perfect(int min, int max) {
    while (min <= max) {
        if (is_perfect(min)) {
            printf("%d ", min);
            ++min;
        }
    }
}

int
is_doublon(int k) {
    /* Un nombre est doublon si le produit de ses diviseurs est multiple de la somme de ses diviseurs */
    int i, sum, prod;
    sum = 0;
    prod = 1;
    for (i = 1; i < k; ++i) {
        if (0 == k % i) {
            sum += i;
            prod *= i;
        }
    }
    if (0 == prod % sum) {
        return TRUE;
    }
    return FALSE;
}

void
find_k_first_doublon(int min, int max) {
    while (min < max) {
        if (is_doublon(min) == TRUE) {
            printf("%d", min);
        }
        ++min;
    }

}

void
ex10(void) {
    int choice;
    choice = 10;
    while (choice != 0) {
        printf("1. Premier nombre premier\n");
        printf("2. Premier nombre parfait\n");
        printf("3. Premier nombre doublon\n");
        printf("0. Quitter\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                find_k_first_prime(10);
                break;
            case 2:
                find_k_first_perfect(1, 10);
                break;
            case 3:
                find_k_first_doublon(1, 10);
                break;
            case 0:
                break;
            default:
                printf("Choix invalide\n");
                break;
        }
    }
}