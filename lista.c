#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"
#include "lista.h"

int n_partita = 1;

//************************************CREA NODO**************************************** */
list_t *l_create_node(struct Partita val)
{
    list_t *n = (list_t *)malloc(sizeof(list_t));
    if (n == NULL)
    {
        exit(EXIT_FAILURE);
    }
    time_t adesso = time(NULL);
    struct tm t = *localtime(&adesso);
    val.tempo = t;
    n->index = n_partita++;
    n->salvataggio = val;
    n->next = NULL;
    return n;
}

//**********************************STAMPA LISTA**************************************** */
bool l_stampa(list_t *n)
{
    list_t *temp = n;
    if (n == NULL)
    {
        printf("Non ci sono salvataggi\n");
        return false;
    }
    while (temp != NULL)
    {
        printf("\t%d. ", temp->index);

        // stampo la data
        printf("%d-", temp->salvataggio.tempo.tm_mday);
        printf("%d-", temp->salvataggio.tempo.tm_mon + 1);
        printf("%d  ", temp->salvataggio.tempo.tm_year + 1900);

        // stampo l'ora
        printf("%02d:", temp->salvataggio.tempo.tm_hour);
        printf("%02d:", temp->salvataggio.tempo.tm_min);
        printf("%02d,  ", temp->salvataggio.tempo.tm_sec);

        // stampo info partita
        printf("%d P.VITA, ", temp->salvataggio.giocatore.vita);
        printf("%d MONETE, ", temp->salvataggio.giocatore.monete);

        // conto gli oggetti in possesso del giocatore
        int n_oggetti = 0;
        for (int i = 0; i < 4; i++)
        {
            if (i == 1 && temp->salvataggio.giocatore.oggetti[i] > 0)
            {
                n_oggetti++;
            }
            else
            {
                n_oggetti += temp->salvataggio.giocatore.oggetti[i];
            }
        }
        printf("%d OGGETTI, ", n_oggetti);

        // conto le missioni completate
        int n_missioni_completate = 0;
        if (temp->salvataggio.palude_putrescente.completata)
        {
            n_missioni_completate++;
        }

        if (temp->salvataggio.magione_infestata.completata)
        {
            n_missioni_completate++;
        }

        if (temp->salvataggio.grotta_di_cristallo.completata)
        {
            n_missioni_completate++;
        }
        printf("%d MISSIONI COMPLETATE\n", n_missioni_completate);

        temp = temp->next;
    }
    return true;
}

//**************************************CANCELLA UN NODO********************************* */
// elimina un nodo specifico dalla lista
void n_free(list_t **l1, int ind)
{

    // Controllo se la lista è vuota anche se non può essere vuota quando viene chiamata la funzione
    if (l1 == NULL || *l1 == NULL)
    {
        printf("\n\nNON CI SONO SALVATAGGI\n\n");
        return;
    }

    list_t *temp = *l1;

    // nel caso che sia il primo
    if (temp->index == ind)
    {
        *l1 = temp->next;
        free(temp);
        return;
    }

    // nel caso che sia in mezzo alla lista o l'ultimo
    while (temp->next != NULL)
    {

        if (temp->next->index == ind)
        {
            list_t *nodo = temp->next;
            temp->next = nodo->next;
            free(nodo);
            return;
        }

        temp = temp->next;
    }

    printf("\n\nSALVATAGGIO NON TROVATO\n\n");
    return;
}

//*********************************INSERISCI UN NODO******************************************** */
// inserimento alla fine della lista
list_t *l_push_back(list_t *l, struct Partita val)
{
    list_t *n = l_create_node(val);

    if (l == NULL)
    {
        return n;
    }

    list_t *temp = l;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    return l;
}

//********************************SELEZIONA UN NODO********************************** */
struct Partita *pull(list_t *l, int ind)
{
    list_t *temp = l;
    while (temp != NULL)
    {
        if (temp->index == ind)
        {
            return &(temp->salvataggio);
        }
        temp = temp->next;
    }

    return NULL;
}