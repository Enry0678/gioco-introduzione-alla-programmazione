#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"

struct Node{
    int index;
    struct Partita salvataggio; 
    struct Node* next;
};

typedef struct Node list_t;

int n_partita=1;

list_t* l_create_node(struct Partita val);
void l_stampa(list_t* n);
list_t* l_push_back(list_t* l, struct Partita val);

#endif