//*****************************************LIBRERIE**********************************************
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

//************************************** MAIN *********************************************
int main(void)
{

    // VARIABILI
    srand(time(0));
    bool uscitaMenuVillaggio = false;

    // while per far girare il gioco
    while (true)
    {
        //*******************************MENU PRINCIPALE*********************************** */
        // crea menu principale e fa selezionare l'azione da compiere
        char scelta = menuPrincipale(false); // false: non ha sbloccato i trucchi di default
        printf("scelta: %c\n", scelta);

        // struttura che contiene la partita
        struct Partita partita;
        // compie l'azione selezionata
        switch (scelta)
        {
        case '1': // nuova partita
            partita = nuovaPartita();
            printf("1\n");
            break;

        case '2': // carica partita
            printf("2\n");
            break;

        case '3': // trucchi
            printf("3\n");
            break;
        }

        int sceltaVillaggio;
        //******************************MENU VILLAGGIO*************************************************** */
        uscitaMenuVillaggio = false;
        while (!uscitaMenuVillaggio)
        {
            sceltaVillaggio = menuVillaggio();
            switch (sceltaVillaggio)
            {
            case 1: // intraprendi una missione
                printf("Intraprende una missione\n");
                short int selezioneMissione = menuSelezioneMissione(&partita);
                if (selezioneMissione == 4)
                {
                    // TODO
                    // missioneFinale();
                }
                //**********************INIZIO MENU MISSIONE************************************* */
                short int selezioneMenuMissione = 0;
                while (selezioneMissione != 4)
                {
                    selezioneMenuMissione = menuMissione(selezioneMissione, &partita);
                    switch (selezioneMenuMissione)
                    {
                    case 1:

                        break;
                    case 2:
                        menuNegozio(&partita);
                        break;
                    case 3:
                        visualizzaInventario(&partita);
                        break;
                    case 4:
                        printf("torna al villaggio");
                        selezioneMissione = 4; //uscita dal menu missione
                        break;
                    }
                }
                break;
                //********************************FINE MENU MISSIONE************************************************ */
            case 2: // riposati
                printf("L'eroe si riposa\n");
                printf("I punti vita sono stati ripristinati\n");
                partita.giocatore.vita = 20;
                break;

            case 3: // inventario

                printf("Apre inventario\n");
                visualizzaInventario(&partita);
                break;

            case 4: // Salva Partita
                printf("Salva la partita\n");
                break;

            case 5: // esci con controllo si o no
                printf("Stai uscendo dal gioco\n");
                printf("Ricordati di salvare la partita per non perdere i tuoi progressi\n");
                printf("Sei sicuro di voler procedere? [Y/N]: ");
                char tmp = ' ';
                do
                {
                    while ((tmp = getchar()) != '\n')
                    {
                    } // pulisci il buffer
                    scanf("%c", &tmp);
                    printf("tmp: %c\n", tmp);
                } while (tmp != 'Y' && tmp != 'N' && tmp != 'y' && tmp != 'n'); // il si e no vengono visti come Y e N anche come y e n
                if (tmp == 'y' || tmp == 'Y')
                {
                    while ((tmp = getchar()) != '\n')
                    {
                    } // pulisci il buffer prima di uscire
                    printf("Uscita dal gioco...\n");
                    uscitaMenuVillaggio = true;
                }
                else
                {
                    printf("Ritorno al menu del villaggio\n");
                }
                break;
            }
        }
    }
}