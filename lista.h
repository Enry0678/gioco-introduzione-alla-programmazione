/**
    @file lista.h
    @brief File contenente tutte le funzione per la gestione dei nodi.

    Questo file contiene le dichiarazioni di tutte le funzioni necessarie per la gestione dei nodi.

    @author Enrico Ghezzo (911190) | Samuele Ferro (911268) | Matteo Lombardi (912616) 

*/


#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"

extern int n_partita;///< Indice da utilizzare per salvare la prossima partita

/**
 *    @brief Crea un nuovo nodo per salvare una partita
 *
 *    
 *
 *    @param *partita partita nella quale verrà copiato il salvataggio
 *
 *    @return puntatore al nodo appena creato
 */
list_t *l_create_node(struct Partita val);

/**
 *    @brief Stampa tutti i salvataggi
 *
 *
 *    @param *n lista contenente i salvataggi
 *
 *    @retval true se ci sono salvataggi  @retval false se non ci sono salvataggi
 */
bool l_stampa(list_t *n);

/**
 *    @brief Cancella il nodo con l'indice indicato
 *
 *
 *    @param **l1 puntatore all'inizio della lista
 *    @param ind indice del nodo da eliminare
 *
 */
void n_free(list_t **l1, int ind);

/**
 *    @brief Crea ed inserisce un nodo alla fine della lista
 *
 *    @param *l lista contenente i salvataggi
 *    @param val partita da inserire nella lista
 *
 *    @return puntatore al primo elemento della lista
 */
list_t *l_push_back(list_t *l, struct Partita val);

/**
 *    @brief Prende il valore del nodo con l'indice indicato
 *
 *    
 *
 *    @param *l lista contenente i salvataggi
 *    @param ind indice del nodo da cui prendere il valore
 *
 *    @retval puntatore alla partita , @retval NULL se non esiste la partia 
 */
struct Partita *pull(list_t *l, int ind);

#endif