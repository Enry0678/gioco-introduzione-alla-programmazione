#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"

extern int n_partita;

list_t *l_create_node(struct Partita val);
bool l_stampa(list_t *n);
void n_free(list_t **l1, int ind);
list_t *l_push_back(list_t *l, struct Partita val);
struct Partita *pull(list_t *l, int ind);

#endif