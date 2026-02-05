#ifndef _FUNZIONI_H_
#define _FUNZIONI_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node;
typedef struct Node list_t;

// *****************************************STRUTTURE DATI*****************************************

struct Player
{
    int vita; // massimo 20
    int monete;
    /*
    gli oggetti sono:
     - [0] pozione curativa
     - [1] spada / spada dell'eroe (nello stesso slot: spada = 1, spada dell'eroe = 2)
     - [2] armatura
     - [3] chiave del castello del signore oscuro
    */
    int oggetti[4];
};

struct Missione
{
    bool completata; // segna se la missione è completata
    int tipo;        // segna il tipo della missione: 0 = palude putrescente, 1 = magione infestata, 2 = grotta di cristallo
    int boss_sconfitti;
    int stanze[10]; // stanze della missione (da generare proceduralmente)
};

struct Partita
{
    struct tm tempo; // salva il tempo (quando si salva)
    struct Player giocatore;
    struct Missione palude_putrescente;
    struct Missione magione_infestata;
    struct Missione grotta_di_cristallo;
    // la missione finale viene gestita in modo diverso (sasso, carta, forbice)
};

struct Node
{
    int index;
    struct Partita salvataggio;
    struct Node *next;
};

//******************************************FUNZIONI************************************************
char menuPrincipale(bool sblocco);
short int menuVillaggio();
void visualizzaInventario(struct Partita *partita);
// void creaStanze(int tipo);
struct Partita nuovaPartita();
short int menuSelezioneMissione(struct Partita *partita);
short int menuMissione(short int selezioneMissione, struct Partita *partita);
void menuNegozio(struct Partita *partita);
void salvaPartita(struct Partita p, list_t *salvataggi);
bool caricaPartita(struct Partita *p, list_t *salvataggi, int index);
bool menuSalvataggi(list_t **salvataggi, struct Partita *partita);
bool menuStanza(struct Partita *partita, short int selezioneMissione);
void invioPerContinuare();
void victory();
void game_over();
bool missione_finale();
void menuTrucchi(list_t *salvataggi);

// variabili globali
extern const char *entita_missione_1[6][5];
extern const char *entita_missione_2[6][5];
extern const char *entita_missione_3[6][5];
#endif