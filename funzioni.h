
/**
    @file funzioni.h
    @brief File contenente tutte le funzioni di gioco.

    Questo file contiene le dichiarazioni di tutte le funzioni necessarie per la gestione delle meccaniche di gioco.

    @author Enrico Ghezzo (911190) | Samuele Ferro (911268) | Matteo Lombardi (912616) 

*/

#ifndef _FUNZIONI_H_
#define _FUNZIONI_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** @typedef list_t
 * @brief Alias per la struttura dati Node per semplificare il codice.
 * 
 */
typedef struct Node list_t;

/**
    @brief Rappresenta il giocatore

    Contiene tutti i parametri che riguardano il giocatore

 */
struct Player
{

    int vita;   ///< Vita del giocatore.
    int monete; ///< Monete in possesso.

    /**
     * @brief Inventario degli oggetti.

     * Gli oggetti sono mappati secondo i seguenti indici:
     * - **[0]** Pozione curativa (quantità).
     * - **[1]** Arma (0: Nessuna, 1: Spada, 2: Spada dell'Eroe).
     * - **[2]** Armatura (0: Nessuna, 1: Presente).
     * - **[3]** Chiave del castello (0: Mancante, 1: Posseduta).
     */
    int oggetti[4];
};

/**
    @brief Rappresenta una missione

    Contiene tutte le specifiche riguardo alla missione (generica)

 */
struct Missione
{
    bool completata; ///< Indica se la missione è stata completata

    /**
     * @brief Segna il tipo della missione

     * Il tipo della missione è mappato come segue:
     * - **0** = palude putrescente
     * - **1** = magione infestata
     * - **2** = grotta di cristallo
     */
    int tipo;
    int boss_sconfitti; ///< Numero di boss sconfitti nella missione
    int stanze[10];     ///< Stanze della missione (generate proceduralmente)
};

/**
    @brief Rappresenta la patita

    Contiene tutte le specifiche riguardo alla partita

 */
struct Partita
{
    struct tm tempo;                     ///< Data e orario del salvataggio
    struct Player giocatore;             ///< Giocatore della partita
    struct Missione palude_putrescente;  ///< Prima missione
    struct Missione magione_infestata;   ///< Seconda missione
    struct Missione grotta_di_cristallo; ///< Terza missione
};

/**
    @brief Rappresenta un nodo della lista dei salvataggi

    Contiene tutte le specifiche riguardo al nodo della lista dei salvataggi

 */
struct Node
{
    int index;                  ///< Indice univoco che rappresenta il salvataggio
    struct Partita salvataggio; ///< %Partita salvata
    struct Node *next;          ///< Salvataggio successivo
};

/**
 *    @brief Visualizza e gestisce il menu principale
 *
 *    Stampa e gestisce il menu principale.
 *
 *    @param sblocco Attiva i trucchi se true
 *    @retval 1 Nuova partita, @retval 2 Carica partita, @retval 3 Menu trucchi (se sono attivati).
 *
 */
char menuPrincipale(bool sblocco);

/**
 *    @brief Visualizza e gestisce il menu del villaggio
 *
 *    Stampa e gestisce il menu del villaggio.
 *
 *
 *    @retval 1 Intraprendi missione, @retval 2 Riposati, @retval 3 Inventario, @retval 4 Salva la partita, @retval 5 esci
 *
 */
short int menuVillaggio();

/**
 *    @brief Visualizza e gestice l'inventario
 *
 *    Stampa l'inventario del giocatore e gestisce le interazioni con esso.
 *
 *    @param *partita parametro che contiene le informazioni sulla partita
 *
 */
void visualizzaInventario(struct Partita *partita);

/**
 *    @brief Crea una nuova partita
 *
 *    Crea una nuova partita inizializzando tutte le variabili della struct Partita ai valori di default
 *
 *
 *    @return La funzione ritorna una struct Partita con tutti i paramentri inizializzati per una nuova partita
 *
 */
struct Partita nuovaPartita();

/**
 *    @brief Menu per selezionare la missione a cui giocare
 *
 *    Menu che permette al giocatore di selezionare una delle missioni non completate
 *
 *    @param *partita partita corrente
 *    @retval 1 Palude putrescente, @retval 2 Magione Infestata, @retval 3 Grotta di Cristallo, @retval 4 %Missione finale
 *
 */
short int menuSelezioneMissione(struct Partita *partita);

/**
 *    @brief Visualizza e gestisce il menu della missione
 *
 *    Visualizza e gestisce il menu della missione in base alla missione selezionata in precedenza
 *
 *    @param selezioneMissione parametro che indica la missione selezionata
 *    @param *partita dati della partita corrente
 *
 *    @retval 1 Esplora la stanza, @retval 2 Negozio, @retval 3 Inventario, @retval 4 Torna al villaggio
 *
 */
short int menuMissione(short int selezioneMissione, struct Partita *partita);

/**
 *    @brief Visualizza e gestisce il negozio
 *
 *    Visualizza e gestisce il negozio in base agli oggetti in possesso del giocatore
 *
 *
 *    @param *partita dati della partita corrente
 *
 *
 */
void menuNegozio(struct Partita *partita);

/**
 *    @brief Salva la partita
 *
 *    Salva la partita nella lista dei salvataggi dopo l'ultima presente
 *
 *
 *    @param p partita da salvare nella lista dei salvataggi
 *    @param *salvataggi lista delle partite salvate
 *
 *
 *
 */
void salvaPartita(struct Partita p, list_t *salvataggi);

/**
 *    @brief Carica la partita
 *
 *    Carica una copia della la partita dalla lista dei salvataggi
 *
 *
 *    @param *p partita da salvare nella lista dei salvataggi
 *    @param *salvataggi lista delle partite salvate
 *    @param index indice del salvataggio
 *
 *    @retval true trova la partita da caricare, @retval false non trova la partita da caricare,
 */
bool caricaPartita(struct Partita *p, list_t *salvataggi, int index);

/**
 *    @brief Gestisce il caricamento o l'eliminazione dei salvataggi
 *
 *    Carica una copia della la partita dalla lista dei salvataggi
 *
 *    @param *partita partita nella quale verrà copiato il salvataggio
 *    @param **salvataggi lista delle partite salvate
 *
 *    @retval true entra nel menu del villaggio, @retval false non entra nel menu del villaggio,
 */
bool menuSalvataggi(list_t **salvataggi, struct Partita *partita);

/**
 *    @brief Gestione del combattimento
 *
 *    Gestisce il combattimento quando si entra in una stanza di un dungeon
 *
 *    @param *partita dati della partita corrente
 *    @param selezioneMissione missione selezionata
 *
 *    @retval true il giocatore è vivo, @retval false il giocatore è morto,
 */
bool menuStanza(struct Partita *partita, short int selezioneMissione);

/**
 *    @brief Fermino
 *
 *    Ferma il gioco fino a che l'utente non preme invio
 *
 */
void invioPerContinuare();

/**
 *    @brief Mostra la schermata di vittoria
 *
 */
void victory();

/**
 *    @brief Mostra la schermata di game over
 *
 */
void game_over();

/**
 *    @brief Gestisce la missione finale
 *
 *    Gestisce la missione finale del gioco
 *
 *    @retval true se il giocatore ha vinto, @retval false se il giocatore ha perso
 *
 */
bool missione_finale();

/**
 *    @brief Gestisce il menu dei trucchi
 *
 *    Permette di modificare le monete, la vita del giocatore e sbloccare direttamente la missione finale
 *
 *    @param *salvataggi dati della partita corrente
 *
 *
 */
void menuTrucchi(list_t *salvataggi);

/** * @brief Matrice delle entità per la %Missione 1 (Palude Putrescente).
 * * La matrice è mappata come segue:
 * - Le **righe** rappresentano le entità.
 * - Le **colonne** rappresentano i parametri delle entità.
 */
extern const char *entita_missione_1[6][5];

/** * @brief Matrice delle entità per la %Missione 2 (Magione Infestata).
 * * La matrice è mappata come segue:
 * - Le **righe** rappresentano le entità.
 * - Le **colonne** rappresentano i parametri delle entità.
 */
extern const char *entita_missione_2[6][5];

/** * @brief Matrice delle entità per la %Missione 3 (Grotta di Cristallo).
 * * La matrice è mappata come segue:
 * - Le **righe** rappresentano le entità.
 * - Le **colonne** rappresentano i parametri delle entità.
 */
extern const char *entita_missione_3[6][5];
#endif