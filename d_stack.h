#ifndef D_STACK_H
#define D_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
typedef struct DLIST {
    int data;
    struct DLIST *prev;
    struct DLIST *next;
} dlist;

// Function Prototypes
status validate(char *argv[], dlist **head1, dlist **tail1, dlist **head2, dlist **tail2);

status add(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3);
status sub(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3);
status mul(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3);
status my_division(dlist **head1, dlist **tail1, dlist **head2, dlist **tail2, dlist **head3, dlist **tail3);

void print_result(dlist **head3,dlist **tail3);

#endif