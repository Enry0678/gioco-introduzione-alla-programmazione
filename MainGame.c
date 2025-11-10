//*****************************************LIBRERIE**********************************************
#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//**************************************SBLOCCO TRUCCHI******************************************
// codice Konami: w w s s a d a d b a [Spazio]
bool sbloccoTrucchi()
{
    // definizione del codice supponendo che la prima lettera sia già inserita
    char lettere[10] = {'w', 's', 's', 'a', 'd', 'a', 'd', 'b', 'a', ' '};
    char input[10];
    // controllo per ogni lettera inserita se appartiene alla sequenza ed è nel posto giusto

    for (short int i = 0; i < 10; i++)
    {
        // prendo la lettera controllando che non sia un \n
        printf("Seleziona una delle opzioni del menu [1-2]:");
        do
        {
            fgets(input, sizeof(input), stdin); // funzione che prende in input una stringa (diversa da scanf)
        } while (input[0] == '\n');

        // controllo se la lettera corrisponde alla sequenza
        if (input[0] != lettere[i])
        {
            return false;
        }
    }
    return true;
}

//*************************************MENU PRINCIPALE*******************************************

// funzione che crea il menu principale e gestisce l'input della selezione -> funzione ricorsiva :)
char menuPrincipale(bool sblocco) // sblocco = se vero viene visualizzata l'opzione trucchi altrimenti no
{
    system("cls || clear"); // cancella tutta la console per poi stampare tutto il menu
    char scelta[10];
    bool sbloccoLocale = false; // utilizzato per determinare se sbloccare i trucchi o no
    printf("Menu Principale:\n\n");
    printf("\t1. Nuova Partita\n");

    if (sblocco == true)
    {
        printf("\t2. Carica Salvataggio\n");
        printf("\t3. Trucchi\n\n");
        printf("Seleziona una delle opzioni del menu [1-3]:");
    }
    else
    {
        printf("\t2. Carica Salvataggio\n\n");
        printf("Seleziona una delle opzioni del menu [1-2]:");
    }
    // prende l'input da tastiera per la scelta
    do
    {
        fgets(scelta, sizeof(scelta), stdin); // funzione che prende in input una stringa (diversa da scanf)
    } while (scelta[0] == '\n');

    // controllo che l'utente abbia inserito un'opzione valida
    while ((strlen(scelta) != 2) || (scelta[0] != '1' && scelta[0] != '2'))
    {

        // controllo se i trucchi sono attivi e abilita il 3 come carattere valido
        if (scelta[0] == '3' && sblocco)
        {
            return scelta[0];
        }

        // controlla se il carattere corrisponde alla prima lettera della sequenza Konami
        if (scelta[0] == 'w' && strlen(scelta) == 2 && !sblocco)
        {
            // determina se la sequenza inserita è giusta o meno
            sbloccoLocale = sbloccoTrucchi();
            if (sbloccoLocale)
            {
                // riavvia il menu principale con i trucchi se la sequenza inserita è giusta
                return menuPrincipale(sbloccoLocale);
            }
        }

        printf("OPZIONE SELEZIONATA NON VALIDA\n");
        if (sblocco)
        {
            printf("Seleziona una delle opzioni del menu [1-3]:");
        }
        else
        {
            printf("Seleziona una delle opzioni del menu [1-2]:");
        }
        do
        {
            fgets(scelta, sizeof(scelta), stdin); // funzione che prende in input una stringa (diversa da scanf)
        } while (scelta[0] == '\n');
    }

    return scelta[0];
}

//************************************** MAIN *********************************************
int main(void)
{
    // crea menu principale e fa selezionare l'azione da compiere
    char scelta = menuPrincipale(false); // false: non ha sbloccato i trucchi di default
    printf("scelta: %c\n", scelta);

    // compie l'azione selezionata
    switch (scelta)
    {
    case '1':
        printf("1\n");
        break;

    case '2':
        printf("2\n");
        break;

    case '3':
        printf("3\n");
        break;
    }
}