//*****************************************LIBRERIE**********************************************
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"
#include "lista.h"

//************************************** MAIN *********************************************
int main(void)
{

    // VARIABILI
    srand(time(0));
    bool uscitaMenuVillaggio = false;
    list_t *salvataggi = NULL;

    // while per far girare il gioco
    while (true)
    {
        //*******************************MENU PRINCIPALE*********************************** */
        // crea menu principale e fa selezionare l'azione da compiere
        char scelta = menuPrincipale(false); // false: non ha sbloccato i trucchi di default

        // struttura che contiene la partita
        struct Partita partita;
        // variabile che indica se entrare nel menu villaggio o restare su quello principale
        bool entra = true;
        // compie l'azione selezionata
        switch (scelta)
        {
        case '1': // nuova partita
            partita = nuovaPartita();
            break;

        case '2': // carica partita
            entra = menuSalvataggi(&salvataggi, &partita);
            break;

        case '3': // trucchi
            menuTrucchi(salvataggi);
            entra = false; 
            break;
        }

        int sceltaVillaggio;
        //******************************MENU VILLAGGIO*************************************************** */
        uscitaMenuVillaggio = false;
        while (!uscitaMenuVillaggio && entra)
        {
            entra = true; // resetta la variabile in modo che si possa accedere al menu villaggio la prossima volta
            sceltaVillaggio = menuVillaggio();
            switch (sceltaVillaggio)
            {
            case 1: // intraprendi una missione
                short int selezioneMissione = menuSelezioneMissione(&partita);
                if (selezioneMissione == 4)
                {
                    if (missione_finale())
                    {              // parte la missione finale
                        victory(); // parte  la scritta della vittoria
                        invioPerContinuare();
                    }
                    else
                    {
                        game_over(); // parte il game over in caso di sconfitta dell'eroe dalla missione finale
                        invioPerContinuare();
                    }

                    // setta le condizioni per uscire al menu iniziale
                    selezioneMissione = 4;
                    uscitaMenuVillaggio = true;
                }
                //**********************INIZIO MENU MISSIONE************************************* */
                short int selezioneMenuMissione = 0;
                bool giocatoreInVita = true; // indica se il giocatore muore durante la missione
                while (selezioneMissione != 4)
                {
                    selezioneMenuMissione = menuMissione(selezioneMissione, &partita);
                    switch (selezioneMenuMissione)
                    {
                    case 1:
                        giocatoreInVita = menuStanza(&partita, selezioneMissione);

                        // controlla se il giocatore è morto
                        if (!giocatoreInVita)
                        {
                            selezioneMissione = 4;
                            uscitaMenuVillaggio = true;
                            game_over();
                            invioPerContinuare();
                        }

                        // menuStanza per combattimento
                        // se vita player<=0:
                        // 1. selezioneMenuMissione = 4 -> esce dal menu missione
                        // 2. uscitaMenuVillaggio = true -> esce dal menu villaggio senza salvare
                        break;
                    case 2:
                        menuNegozio(&partita);
                        break;
                    case 3:
                        visualizzaInventario(&partita);
                        break;
                    case 4:                    // torna al villaggio
                        selezioneMissione = 4; // uscita dal menu missione
                        break;
                    }
                }
                break;
                //********************************FINE MENU MISSIONE************************************************ */
            case 2: // riposati
                printf("L'eroe si riposa\n");
                printf("I punti vita sono stati ripristinati\n");
                partita.giocatore.vita = 20;
                invioPerContinuare();
                break;

            case 3: // inventario
                visualizzaInventario(&partita);
                break;

            case 4: // Salva Partita
                if (salvataggi == NULL)
                {
                    salvataggi = l_create_node(partita); // crea il nodo se primo
                }
                else
                {
                    salvataggi = l_push_back(salvataggi, partita);
                }
                printf("Partita salvata con successo!\n");
                invioPerContinuare();
                break;

            case 5: // esci con controllo si o no
                printf("Stai uscendo dal gioco\n");
                printf("Ricordati di salvare la partita per non perdere i tuoi progressi\n");

                char tmp = ' ';
                do
                {
                    printf("Sei sicuro di voler procedere? [Y/N]: ");
                    scanf("%c", &tmp);
                    if (tmp != 'Y' && tmp != 'N' && tmp != 'y' && tmp != 'n')
                    {
                        printf("\nScelta non valida\n\n");
                        while ((tmp = getchar()) != '\n')
                        {
                        } // pulisci il buffer
                    }
                } while (tmp != 'Y' && tmp != 'N' && tmp != 'y' && tmp != 'n'); // il si e no vengono visti come Y e N anche come y e n
                if (tmp == 'y' || tmp == 'Y')
                {

                    while ((tmp = getchar()) != '\n')
                    {
                    } // pulisci il buffer prima di uscire
                    uscitaMenuVillaggio = true;
                }
                break;
            }
        }
    }
}