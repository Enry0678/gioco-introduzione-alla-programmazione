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

    while (true)
    {
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

        while (true)
        {
            sceltaVillaggio = menuVillaggio();
            switch (sceltaVillaggio)
            {
            case 1: // intraprendi una missione
                printf("Intraprende una missione\n");
                break;

            case 2: // riposati
                printf("L'eroe si riposa\n");
                printf("I punti vita sono stati ripristinati\n");
                partita.giocatore.vita = 20;
                break;

            case 3: // inventario

                printf("Apre inventario\n");
                visualizzaInventario(partita);
                break;

            case 4: // Salva Partita
                printf("Salva la partita\n");
                break;

            case 5: // esci
                printf("Sei uscito\n");
                break;
            }
        }
    }
}