// ********************************************************************************************************************************************************************
// SEZIONE LIBRERIE
// ********************************************************************************************************************************************************************
#include "funzioni.h"
#include "lista.h"
// ********************************************************************************************************************************************************************
// DEFINIZIONE COSTANTI ANSI (Colori per il Terminale)
// Questi codici sono sequenze di escape che comunicano direttamente con il terminale.
// ********************************************************************************************************************************************************************
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define RED "\x1b[31m"
#define GREEN "\x1b[38;5;82m"
// ********************************************************************************************************************************************************************
// VARIABILI GLOBALI (Note di sviluppo)
// 0. Nome Entità | 1. Tipo (0=Fight, 1=Trap) | 2. Danno Letale | 3. Danno | 4. Loot
// ********************************************************************************************************************************************************************
// Struttura delle colonne [6 righe][5 colonne]:
// 0: Nome dell'entità
// 1: Tipologia (0 = Combattimento/Fight, 1 = Trappola, 2 = Stanza vuota)
// 2: Danno "One-Shot" (Danno necessario per sconfiggerlo subito)
// 3: Forza d'attacco (Danno inflitto al giocatore. 'd' indica danno variabile)
// 4: Ricompensa (Monete ottenute o perse alla fine dell'incontro)
// ********************************************************************************************************************************************************************

// ---- MIISSIONE 1: Palude Putrescente ----
const char const *entita_missione_1[6][5] = {
    {"Cane Selvaggio", "0", "2", "1", "0"},
    {"Goblin", "0", "3", "2", "2"},
    {"Scheletro", "0", "4", "2", "4"},
    {"Orco", "0", "3", "4", "6"},
    {"Acquitrino Velenoso", "1", "0", "d", "0"},
    {"Generale Orco", "0", "6", "3", "12"},
};

// ---- MIISSIONE 2: Magione Infestata ----
const char const *entita_missione_2[6][5] = {{"Botola Buia", "1", "0", "3", "0"}, {"Pipistrello", "0", "2", "2", "1"}, {"Zombie", "0", "3", "2", "2"}, {"Fantasma", "0", "5", "2", "4"}, {"Vampiro Superiore", "0", "4", "4", "7"}, {"Demone Custode", "0", "4", "6", "10"}};

// ---- MIISSIONE 3: Grotta di Cristallo ----
const char const *entita_missione_3[6][5] = {{"Stanza Vuota", "2", "0", "0", "0"}, {"Cristalli Cadenti", "1", "0", "2", "0"}, {"Ponte Pericolante", "1", "0", "0", "-3"}, {"Forziere Misterioso", "1", "0", "2", "10"}, {"Rupe Scoscesa", "1", "0", "d", "0"}, {"Drago Antico", "0", "5", "10", "12"}};

// ********************************************************************************************************************************************************************
// TIRA DADO
// ********************************************************************************************************************************************************************
short int tiraDado() // funzione che serve per tirare un dado a 6 faccie
{
    return (rand() % 6) + 1;
}

//*****************************************PADOVAN********************************************** */

int padovan(int x)
{
    if (x == 0 || x == 1 || x == 2)
    {
        return 1;
    }
    return padovan(x - 2) + padovan(x - 3);
}

//*****************************************IS IN PADOVAN****************************************** */
bool isInPadovan(int x)
{
    int i = 0;
    int n = 0;
    while (true)
    {
        n = padovan(i);
        if (n == x)
        {
            return true;
        }
        else if (n > x)
        {
            return false;
        }
        i++;
    }
}

//************************************VICTORY************************************* */
void victory()
{
    system("cls || clear");
    printf("\n\n" GREEN BOLD);

    // Scritta VICTORY
    printf(" /$$    /$$ /$$$$$$  /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$     /$$\n");
    printf("| $$   | $$|_  $$_/ /$$__  $$|__  $$__//$$__  $$| $$__  $$|  $$   /$$/\n");
    printf("| $$   | $$  | $$  | $$  \\__/   | $$  | $$  \\ $$| $$  \\ $$ \\  $$ /$$/ \n");
    printf("|  $$ / $$/  | $$  | $$         | $$  | $$  | $$| $$$$$$$/  \\  $$$$/  \n");
    printf(" \\  $$ $$/   | $$  | $$         | $$  | $$  | $$| $$__  $$   \\  $$/   \n");
    printf("  \\  $$$/    | $$  | $$    $$   | $$  | $$  | $$| $$  \\ $$    | $$    \n");
    printf("   \\  $/    /$$$$$$|  $$$$$$/   | $$  |  $$$$$$/| $$  | $$    | $$    \n");
    printf("    \\_/    |______/ \\______/    |__/   \\______/ |__/  |__/    |__/    \n");
    printf("\n" RESET);
}

//**********************************************GAME OVER**************************************************** */
void game_over()
{
    system("cls || clear");
    printf("\n\n" RED BOLD);

    // Scritta GAME OVER
    printf(" @@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@   \n");
    printf("@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@  \n");
    printf("!@@        @@!  @@@  @@! @@! @@!  @@!          @@!  @@@  @@!  @@@  @@!       @@!  @@@  \n");
    printf("!@!        !@!  @!@  !@! !@! !@!  !@!          !@!  @!@  !@!  @!@  !@!       !@!  @!@  \n");
    printf("!@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!       @!@  !@!  @!@  !@!  @!!!:!    @!@!!@!   \n");
    printf("!!! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:       !@!  !!!  !@!  !!!  !!!!!:    !!@!@!    \n");
    printf(":!!   !!:  !!:  !!!  !!:     !!:  !!:          !!:  !!!  :!:  !!:  !!:       !!: :!!   \n");
    printf(":!:   !::  :!:  !:!  :!:     :!:  :!:          :!:  !:!   ::!!:!   :!:       :!:  !:!  \n");
    printf(" ::: ::::  ::   :::  :::     ::    :: ::::     ::::: ::    ::::     :: ::::  ::   :::  \n");
    printf(" :: :: :    :   : :   :      :    : :: ::       : :  :      :      : :: ::    :   : :  \n");
    printf("\n" RESET);
}

/***************************************INVIO PER CONTIUARE ******************************************/
void invioPerContinuare()
{ // funzione che serve per fermare il gioco e premere invio per continuare
    printf("Premi invio per continuare...");
    ungetc('A', stdin); // inserisce nel buffer il valore "A" per permettere """l'invio istantaneo"""
    getchar();          // aspetta l'invio
    char c;
    while ((c = getchar()) != '\n')
    {
    } // svuota il buffer per evitare dati indesiderati
    printf("\n");
    return;
}

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
//*************************************MENU DEL VILLAGGIO*******************************************
short int menuVillaggio()
{
    system("cls || clear"); // cancella tutta la console per poi stampare tutto il menu

    printf("Menu del villaggio:\n\n"); // print del menu del villaggio
    printf("\t1. Intraprendi una missione\n");
    printf("\t2. Riposati\n");
    printf("\t3. Inventario\n");
    printf("\t4. Salva la partita\n");
    printf("\t5. Esci\n\n");
    int opzione;
    bool valido = false;
    do
    {
        valido = false;
        printf("Seleziona una delle opzioni del menu [1-5]: ");
        scanf("%d", &opzione);
        if (opzione < 1 || opzione > 5)
        {
            printf("OPZIONE NON VALIDA\n");
            valido = true;
        }

        // svuota il buffer
        int c;
        while ((c = getchar()) != '\n')
        {
        }
    } while (valido);

    return opzione;
}
//*************************************INVENTARIO*******************************************
void visualizzaInventario(struct Partita *partita)
{
    system("cls || clear"); // cancella tutta la console per poi stampare tutto il menu
    printf("Inventario: \n");
    printf("\t- vita:%d \n", partita->giocatore.vita);
    printf("\t- monete: %d\n", partita->giocatore.monete);
    printf("\t- pozioni curative: %d\n", partita->giocatore.oggetti[0]);
    if (partita->giocatore.oggetti[1] == 1)
    {
        printf("\t- arma: spada\n");
    }
    else if (partita->giocatore.oggetti[1] == 2)
    {
        printf("\t- arma: spada dell'eroe\n");
    }

    if (partita->giocatore.oggetti[2] == 1)
    {
        printf("\t- armatura\n");
    }

    if (partita->giocatore.oggetti[3] == 1)
    {
        printf("\t- chiave del castello del signore oscuro\n");
    }

    printf("\nAzioni disponibili:\n");
    printf("\t1. Usa una pozione di cura\n");
    printf("\t2. Esci dall'invetario\n");

    int scelta;
    do
    {

        printf("\nSeleziona una delle opzioni[1,2]: ");
        scanf("%d", &scelta);

        if (scelta == 1 && partita->giocatore.oggetti[0] > 0 && partita->giocatore.vita < 20)
        {
            partita->giocatore.vita += tiraDado();
            if (partita->giocatore.vita > 20)
            {
                partita->giocatore.vita = 20;
            }
            partita->giocatore.oggetti[0]--;
            printf("Hai usato una pozione curativa, la tua vita ora è: %d\n", partita->giocatore.vita);
            printf("Adesso hai %d pozioni curative\n", partita->giocatore.oggetti[0]);
        }
        else if (scelta == 1 && partita->giocatore.vita >= 20)
        {
            printf("Hai già il massimo della vita\n");
        }
        else if (scelta == 1 && partita->giocatore.oggetti[0] <= 0)
        {
            printf("Non hai pozioni curative\n");
        }

        if (scelta != 1 && scelta != 2)
        {
            printf("L'opzione selezionata non è valida\n");
            char c;
            while ((c = getchar()) != '\n')
            {
            }
        }

    } while (scelta != 2);
}

//*************************************CREA STANZE*******************************************

void creaStanze(struct Partita *partita, int tipo)
{
    int i = 0;
    switch (tipo)
    {
    // palude putrescente
    case 1:
        int contatoreOrco = 0;
        int j;
        for (j = 0; j < 7; j++) // ciclo for per generare le prime 7 stanze
        {
            partita->palude_putrescente.stanze[j] = tiraDado() - 1; // genera un numero pseudo-casuale tra 0 e 5
            if (partita->palude_putrescente.stanze[j] == 5)         // controllo se è stato generato un orco
            {
                contatoreOrco++;
            }
            if (contatoreOrco == 3) // se sono stati generati 3 orchi esce dal ciclo
            {
                break;
            }
        }
        // forzatura dei requisiti
        for (int k = contatoreOrco; k < 3; k++) // ciclo for per forzare la generazione degli orchi mancanti
        {
            partita->palude_putrescente.stanze[j++] = 5; // genera un orco in una delle stanze rimanenti
        }
        return;
        break; // segna la fine del case

    // magione infestata
    case 2:
        i = 0;
        int contatoreVampiro = 0;                                       // conta quanti vampiri sono stati generati
        int contatoreDemone = 0;                                        // conta quanti demoni sono stati generati
        for (i; i < 10 - (2 - contatoreVampiro - contatoreDemone); i++) // riserva gli spazi per la forzatura
        {
            partita->magione_infestata.stanze[i] = tiraDado() - 1;

            // controllo dei requisiti
            // controllo del vampiro superiore
            if (partita->magione_infestata.stanze[i] == 4)
            {
                // rigenera la stanza in caso ci sia già un vampiro superiore
                if (partita->magione_infestata.stanze[i] == 4 && contatoreVampiro >= 1)
                {
                    partita->magione_infestata.stanze[i] = tiraDado() % 4;
                }
                // conta quanti vampiri ci sono (PER FORZA 1 solo)
                if (contatoreVampiro == 0)
                {
                    contatoreVampiro++;
                }
            }

            // controllo del demone custode
            if (partita->magione_infestata.stanze[i] == 5)
            {
                // rigenera la stanza in caso ci sia già un demone custode
                if (partita->magione_infestata.stanze[i] == 5 && contatoreDemone >= 1)
                {
                    partita->magione_infestata.stanze[i] = tiraDado() % 4;
                }
                // conta quanti demoni custodi ci sono (PER FORZA 1 solo)
                if (contatoreDemone == 0)
                {
                    contatoreDemone++;
                }
            }

            if (contatoreVampiro == 1 && contatoreDemone == 1)
            {
                return;
            }
        }

        // forzatura dei requisiti
        if (contatoreVampiro != 1 && contatoreDemone != 1)
        {
            partita->magione_infestata.stanze[i++] = 4;
            partita->magione_infestata.stanze[i] = 5;
            return;
        }

        if (contatoreDemone == 0)
        {
            partita->magione_infestata.stanze[i] = 5;
            return;
        }

        if (contatoreVampiro == 0)
        {
            partita->magione_infestata.stanze[i] = 4;
            return;
        }
        break; // segna la fine del case

    // grotta di cristallo
    case 3:

        int contatoreDrago = 0;
        for (i = 0; i < 9; i++)
        {
            partita->grotta_di_cristallo.stanze[i] = tiraDado() - 1;
            if (partita->grotta_di_cristallo.stanze[i] == 5)
            {
                contatoreDrago++;
            }
            if (contatoreDrago == 1)
            {
                break;
            }
        }
        for (int k = contatoreDrago; k < 1; k++)
        {
            partita->grotta_di_cristallo.stanze[i++] = 5;
        }
        break; // segna la fine del case
    }
}

//*************************************NUOVA PARTITA*******************************************
struct Partita nuovaPartita()
{
    // inizializzazione della partita
    struct Partita partita =
        {
            // inizializzazione del giocatore
            .giocatore = {
                .vita = 20,
                .monete = 0,
                .oggetti = {0}},

            // inizializzazione della prima missione
            .palude_putrescente = {.completata = false, .boss_sconfitti = 0, .tipo = 0, .stanze = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}},

            // inizializzazione della seconda missione
            .magione_infestata = {.completata = false, .boss_sconfitti = 0, .tipo = 1, .stanze = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}},

            // inizializzazione della terza missione
            .grotta_di_cristallo = {.completata = false, .boss_sconfitti = 0, .tipo = 2, .stanze = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}};

    return partita;
}

//*********************************MENU SELEZIONE MISSIONE*********************************************
short int menuSelezioneMissione(struct Partita *partita)
{                           // menu per selezionare la missione
    system("cls || clear"); // cancella tutta la console per poi stampare tutto il menu

    printf("Menu di Selezione Missione:\n\n");
    if (!(partita->palude_putrescente.completata) || !(partita->grotta_di_cristallo.completata) || !(partita->magione_infestata.completata))
    {
        if (!partita->palude_putrescente.completata)
        {
            printf("\t1. Palude Putrescente\n");
        }
        if (!partita->magione_infestata.completata)
        {
            printf("\t2. Magione Infestata\n");
        }
        if (!partita->grotta_di_cristallo.completata)
        {
            printf("\t3. Grotta di Cristallo\n");
        }
        printf("\n");
        int scelta = 0;
        do
        {
            printf("Seleziona una delle opzioni del menu [");
            int primo = 1; // Flag per gestire le virgole

            if (!partita->palude_putrescente.completata)
            {
                printf("1");
                primo = 0;
            }
            if (!partita->magione_infestata.completata)
            {
                if (!primo)
                {
                    printf(",");
                }
                printf("2");
                primo = 0;
            }
            if (!partita->grotta_di_cristallo.completata)
            {
                if (!primo)
                {
                    printf(",");
                }
                printf("3");
            }

            printf("]: ");
            scanf("%d", &scelta); // sceglie la stanza

            if ((scelta != 1 || partita->palude_putrescente.completata) && (scelta != 2 || partita->magione_infestata.completata) && (scelta != 3 || partita->grotta_di_cristallo.completata))
            {
                printf("L'opzione selezionata non è valida\n\n");
                char c;
                while ((c = getchar()) != '\n')
                {
                }
            }
        } while ((scelta != 1 || partita->palude_putrescente.completata) && (scelta != 2 || partita->magione_infestata.completata) && (scelta != 3 || partita->grotta_di_cristallo.completata));

        creaStanze(partita, scelta);
        return scelta;
    }
    else
    {
        printf("\t4. Castello del Signore Oscuro\n\n");
        printf("Premi invio per continuare...");

        ungetc('A', stdin); // inserisce nel buffer il valore "A" per permettere """l'invio istantaneo"""
        getchar();          // aspetta l'invio
        char c;
        while ((c = getchar()) != '\n')
        {
        } // svuota il buffer per evitare dati indesiderati
        return 4;
    }
}

//*********************************MENU MISSIONE******************************************/

short int menuMissione(short int selezioneMissione, struct Partita *partita)
{
    system("cls || clear"); // cancella tutta la console per poi stampare tutto il menu
    struct Missione *missione;
    switch (selezioneMissione)
    {
    case 1:
        missione = &(partita->palude_putrescente);
        printf("OBIETTIVO:  Sconfiggi 3 Generale Orco del Signore Oscuro\n");
        printf("STATO DI AVANZAMENTO: Eliminati %d su 3 Generale Orco\n", partita->palude_putrescente.boss_sconfitti);
        break;

    case 2:
        missione = &(partita->magione_infestata);
        printf("OBIETTIVO: Recuperare la chiave del Castello del Signore Oscuro, e sconfiggere un Vampiro Superiore.\n");

        // creazione della stringa per lo stato di avanzamento
        char tmp[200] = "STATO DI AVANZAMENTO: ";
        if (partita->giocatore.oggetti[3] != 0)
        {
            strcat(tmp, " -Chiave recuperata- "); // funzione per concatenare due stringhe (presente in string.h)
        }
        else
        {
            strcat(tmp, " -Chiave non recuperata- ");
        }

        if (missione->boss_sconfitti >= 1)
        {
            strcat(tmp, "-Vampiro superiore sconfitto-\n ");
        }
        else
        {
            strcat(tmp, "-Vampiro superiore non sconfitto-\n ");
        }
        printf("%s\n", tmp);
        break;
    case 3:
        missione = &(partita->grotta_di_cristallo);
        printf("OBIETTIVO: Recuperare la spada dell'Eroe\n");

        char tmp1[200] = "STATO DI AVANZAMENTO: ";
        if (partita->giocatore.oggetti[1] == 2)
        {
            strcat(tmp1, "-Spada dell'Eroe recuperata- \n");
        }
        else
        {
            strcat(tmp1, "-Spada dell'Eroe non recuperata- \n");
        }
        printf("%s\n", tmp1);
        break;
    }

    printf("\nMenu Missione:\n\n");

    printf("\t1. Esplora stanza del Dungeon\n");
    printf("\t2. Negozio\n");
    printf("\t3. Inventario\n");
    if (missione->completata)
    {
        printf("\t4. Torna al villaggio\n\n");
    }
    else
    {
        printf("\t4. Torna al villaggio (Paga 50 monete)\n\n");
    }

    short int selezione = 0;
    bool hasCoins; // determina se il giocatore ha le monete necessarie per tornare al villaggio
    do
    {
        hasCoins = false;
        printf("Seleziona un opzione del menu [1-4]: ");
        scanf("%hd", &selezione);

        // controlla che il giocatore abbia le monete necessarie per uscire in caso non abbia completato la missione
        if (selezione == 4 && partita->giocatore.monete < 50 && !missione->completata)
        {
            printf("\nNon hai abbastanza monete per ritirarti dalla missione, seleziona un'altra opzione\n");
            hasCoins = false;
        }
        else if (selezione == 4 && partita->giocatore.monete >= 50 && !missione->completata)
        {
            partita->giocatore.monete -= 50;
            missione->completata = true;
            return 4;
        }
        else if (selezione == 4 && missione->completata)
        {
            return 4;
        }
        else
        {
            hasCoins = true; // in caso che venga scelta un opzione diversa da 4
        }

        if (selezione < 1 || selezione > 4)
        {
            printf("Scelta non valida\n\n");
        }
        char c;
        while ((c = getchar()) != '\n')
        {
        }

    } while ((selezione < 1 || selezione > 4) || !hasCoins);

    return selezione;
}

/****************************************************MENU NEGOZIO*****************************************************************/

// funzione per visualizzare il negozio
void menuNegozio(struct Partita *partita)
{
    system("cls || clear"); // cancella tutta la console per poi stampare tutto il menu

    printf("Negozio\n"); // visualizza tutto il negozio
    printf("Monete: %d\n", partita->giocatore.monete);
    printf("Seleziona un item da acquistare:\n\n");
    printf("\t_______________________________________________________________________________________________\n");
    printf("\t|  OGGETTO     |                       DESCRIZIONE                                   |  COSTO  |\n");
    printf("\t| 1. Pozione:  |  Curativa Ripristina fino a 6 Punti Vita (lancia un dado a 6 facce) |   4     |\n ");
    printf("\t| 2. Spada:    |  +1 all'attacco dell'eroe (acquistabile una volta sola)             |   5     |\n");
    printf("\t| 3. Armatura: |  -1 al danno del nemico/trappola (acquistabile una volta sola)      |   10    |\n");
    printf("\t|______________|_____________________________________________________________________|_________|\n\n");

    int scelta;
    do
    {
        printf("Scegli cosa comprare [1-3] oppure digita 4 per uscire: ");
        scanf("%d", &scelta);

        // acquisto di una pozione curativa
        if (scelta == 1)
        {
            if (partita->giocatore.monete < 4)
            {
                printf("Non hai abbastanza monete per acquistare la pozione\n\n");
            }
            else
            {
                printf("Hai acquistato la pozione\n");
                partita->giocatore.oggetti[0]++;
                partita->giocatore.monete -= 4;
                printf("Ti rimangono %d monete\n\n", partita->giocatore.monete);
            }
        }
        // acquisto della spada
        if (scelta == 2)
        {
            if (partita->giocatore.monete < 5)
            {
                printf("Non hai abbastanza monete per acquistare la spada\n\n");
            }
            else if (partita->giocatore.oggetti[1] != 0)
            {
                printf("Hai già la spada\n\n");
            }
            else
            {
                partita->giocatore.oggetti[1]++;
                partita->giocatore.monete -= 5;
                printf("Hai acquistato la spada\n");
                printf("Ti rimangono %d monete\n\n", partita->giocatore.monete);
            }
        }

        if (scelta == 3)
        {
            if (partita->giocatore.monete < 10)
            {
                printf("Non hai abbastanza monete per acquistare l'armatura\n\n");
            }
            else if (partita->giocatore.oggetti[2] != 0)
            {
                printf("Hai già l'armatura\n\n");
            }
            else
            {
                partita->giocatore.oggetti[2] = 1;
                partita->giocatore.monete -= 10;
                printf("Hai acquistato la l'armatura\n");
                printf("Ti rimangono %d monete\n\n", partita->giocatore.monete);
            }
        }
        // caso di uscita
        if (scelta == 4)
        {
            return;
        }

        if (scelta != 1 && scelta != 2 && scelta != 3)
        {
            printf("La scelta non è valida, scegliere un altra opzione\n\n");
            char c;
            while ((c = getchar()) != '\n')
            {
            }
        }

    } while (true);
}

/****************************************************SALVA PARTITA*****************************************************************/
void salvaPartita(struct Partita p, list_t *salvataggi)
{
    l_push_back(salvataggi, p); // salva (creando il nodo automaticamente) nella lista dei salvataggi
    return;
}

/****************************************************CARICA PARTITA**************************************************************** */
void caricaPartita(struct Partita *p, list_t *salvataggi, int index)
{
    *p = pull(salvataggi, index);
    return;
}

/*****************************************************MENU CARICA PARTITA************************************************************* */
int menuCaricaPartita(list_t *salvataggi, struct Partita *partita)
{
    system("cls || clear");
    printf("Salvataggi:\n");
    if (l_stampa(salvataggi))
    {
        int scelta = 0;
        do
        {
            printf("Seleziona un salvataggio da caricare: ");
            scanf("%d", &scelta);
            // casi problematici
            caricaPartita(partita, salvataggi, scelta);
            if (scelta < 1 || scelta > n_partita || partita->tempo.tm_mday == -1)
            {
                printf("Scelta non valida, inserire un salvataggio esistente\n");
            }
        } while (scelta < 1 || scelta > n_partita || partita->tempo.tm_mday == -1);
    }
    else
    {
        *partita = nuovaPartita();

        invioPerContinuare();
    }
}

/***********************************************MENU STANZA*************************************************** */
bool menuStanza(struct Partita *partita, short int selezioneMissione) // ritorna true se il giocatore muore
{
    system("cls || clear");
    int stanza = 0;
    switch (selezioneMissione)
    {
    // palude putrescente -----------------------------
    case 1:
        // trova la stanza in cui entrare
        for (int i = 0; i < 11; i++)
        {
            // in caso che siano finite le stanze del dungeon
            if (i == 10)
            {
                printf("Non ci sono altre stanze nel dungeon\n");
                invioPerContinuare();
                return true;
            }

            if (partita->palude_putrescente.stanze[i] != -1)
            {
                stanza = partita->palude_putrescente.stanze[i]; // salva il valore della stanza in una variabile
                partita->palude_putrescente.stanze[i] = -1;     // segna che la stanza è stata visitata
                i = 10;                                         // esce dal for
            }
        }

        // decide cosa fare in base al tipo di stanza
        if (atoi(entita_missione_1[stanza][1]) == 1)
        { // caso in cui trova una trappola
            printf("Il giocatore trova nella stanza %s\n", entita_missione_1[stanza][0]);
            invioPerContinuare();
            printf("Viene tirato un dado da 6 facce per determinare il danno inflitto al giocatore\n");
            short int risultato = tiraDado();
            printf("Il risultato: %hd\n", risultato);
            partita->giocatore.vita -= risultato - partita->giocatore.oggetti[2]; // si riduce il danno subito se il giocatore ha l'armatura
            // controlla se il giocatore muore
            if (partita->giocatore.vita <= 0)
            {
                return false; // il giocatore è morto
            }
            printf("Vengono inflitti %d danni, la vita del giocatore scende a %d\n", risultato - partita->giocatore.oggetti[2], partita->giocatore.vita); // visualizza la vita del giocatore dopo il danno
            invioPerContinuare();
        }
        else
        { // caso in cui ci sia un combattimento
            printf("Il giocatore incontra %s e inizia il combattimento.\n", entita_missione_1[stanza][0]);
            invioPerContinuare();
            short int risultato = 0;
            while (risultato < atoi(entita_missione_1[stanza][2]))
            {
                printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n");
                risultato = tiraDado(); // tira il dado per stabilire l'attacco dell'erore
                risultato += partita->giocatore.oggetti[1];
                if (partita->giocatore.oggetti[1] != 0)
                {
                    if (partita->giocatore.oggetti[1] == 1)
                    {
                        printf("Il risultato: %hd (potenziato da spada)\n", risultato);
                    }
                    else
                    {
                        printf("Il risultato: %hd (potenziato da spada dell'eroe)\n", risultato);
                    }
                }
                else
                {
                    printf("Il risultato: %hd\n", risultato);
                }

                // in caso che il giocatore uccida il nemico
                if (risultato >= atoi(entita_missione_1[stanza][2]))
                {
                    printf("%s viene sconfitto (%hd >= %d). L'eroe rimane con %d punti vita, e riceve %d monete\n", entita_missione_1[stanza][0], risultato, atoi(entita_missione_1[stanza][2]), partita->giocatore.vita, atoi(entita_missione_1[stanza][4]));
                    partita->giocatore.monete += atoi(entita_missione_1[stanza][4]);

                    // conta quanti generali orco vengono uccisi
                    if (entita_missione_1[stanza][0] == "Generale Orco")
                    {
                        partita->palude_putrescente.boss_sconfitti++;
                        if (partita->palude_putrescente.boss_sconfitti == 3)
                        {
                            partita->palude_putrescente.completata = true;
                        }
                    }
                    invioPerContinuare();
                }
                else
                { // in caso che il giocatore prenda danno
                    printf("Attacco non sufficiente per sconfiggere %s (%hd < Colpo Fatale = %d)\n", entita_missione_1[stanza][0], risultato, atoi(entita_missione_1[stanza][2]));
                    partita->giocatore.vita -= atoi(entita_missione_1[stanza][3]) - partita->giocatore.oggetti[2]; // atoi converte la stringa in decimale

                    if (partita->giocatore.vita <= 0)
                    {
                        return false; // il giocatore è morto
                    }

                    printf("%s infligge %d danni all' eroe. L' eroe rimane con %d punti vita\n", entita_missione_1[stanza][0], atoi(entita_missione_1[stanza][3]) - partita->giocatore.oggetti[2], partita->giocatore.vita);
                    invioPerContinuare();
                }
            }
        }

        // return true; // il giocatore è ancora in vita
        break;

    // magione infestata ------------------------------
    case 2:
        // trova la stanza in cui entrare
        for (int i = 0; i < 11; i++)
        {
            // in caso che siano finite le stanze del dungeon
            if (i == 10)
            {
                printf("Non ci sono altre stanze nel dungeon\n");
                invioPerContinuare();
                return true;
            }

            if (partita->magione_infestata.stanze[i] != -1)
            {
                stanza = partita->magione_infestata.stanze[i]; // salva il valore della stanza in una variabile
                partita->magione_infestata.stanze[i] = -1;     // segna che la stanza è stata visitata
                i = 10;                                        // esce dal for
            }
        }

        // decide cosa fare in base al tipo di stanza
        if (atoi(entita_missione_2[stanza][1]) == 1)
        { // caso in cui trova una trappola
            printf("Il giocatore è entrato in %s\n", entita_missione_2[stanza][0]);
            invioPerContinuare();
            printf("Viene inflitto %d di danno al giocatore(il danno di base è 3 ridotto se in possesso dell'armatura)\n", atoi(entita_missione_2[stanza][3]) - partita->giocatore.oggetti[2]);
            partita->giocatore.vita -= atoi(entita_missione_2[stanza][3]) - partita->giocatore.oggetti[2]; // si riduce il danno subito se il giocatore ha l'armatura
            // controlla se il giocatore muore
            if (partita->giocatore.vita <= 0)
            {
                return false; // il giocatore è morto
            }
            printf("la vita del giocatore scende a %d\n", partita->giocatore.vita); // visualizza la vita del giocatore dopo il danno
            invioPerContinuare();
        }
        else
        { // caso in cui ci sia un combattimento
            printf("Il giocatore incontra %s e inizia il combattimento.\n", entita_missione_2[stanza][0]);
            invioPerContinuare();
            short int risultato = 0;
            while (risultato < atoi(entita_missione_2[stanza][2]))
            {
                printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n");
                risultato = tiraDado(); // tira il dado per stabilire l'attacco dell'erore
                risultato += partita->giocatore.oggetti[1];
                if (partita->giocatore.oggetti[1] != 0)
                {
                    if (partita->giocatore.oggetti[1] == 1)
                    {
                        printf("Il risultato: %hd (potenziato da spada)\n", risultato);
                    }
                    else
                    {
                        printf("Il risultato: %hd (potenziato da spada dell'eroe)\n", risultato);
                    }
                }
                else
                {
                    printf("Il risultato: %hd\n", risultato);
                }

                // in caso che il giocatore uccida il nemico
                if (risultato >= atoi(entita_missione_2[stanza][2]))
                {
                    printf("%s viene sconfitto (%hd >= %d). L'eroe rimane con %d punti vita, e riceve %d monete\n", entita_missione_2[stanza][0], risultato, atoi(entita_missione_2[stanza][2]), partita->giocatore.vita, atoi(entita_missione_2[stanza][4]));
                    partita->giocatore.monete += atoi(entita_missione_2[stanza][4]);

                    //
                    if (entita_missione_2[stanza][0] == "Demone Custode")
                    {
                        printf("Il giocatore ha ottenuto la chiave del Castello del Signore Oscuro!\n");
                        partita->giocatore.oggetti[3] = 1;
                    }

                    if (entita_missione_2[stanza][0] == "Vampiro Superiore")
                    {
                        partita->magione_infestata.boss_sconfitti++;
                    }

                    if (partita->giocatore.oggetti[3] == 1 && partita->magione_infestata.boss_sconfitti > 0)
                    {
                        partita->magione_infestata.completata = true;
                    }
                    invioPerContinuare();
                }
                else
                { // in caso che il giocatore prenda danno
                    printf("Attacco non sufficiente per sconfiggere %s (%hd < Colpo Fatale = %d)\n", entita_missione_2[stanza][0], risultato, atoi(entita_missione_2[stanza][2]));
                    partita->giocatore.vita -= atoi(entita_missione_2[stanza][3]) - partita->giocatore.oggetti[2]; // atoi converte la stringa in decimale

                    if (partita->giocatore.vita <= 0)
                    {
                        return false; // il giocatore è morto
                    }

                    printf("%s infligge %d danni all' eroe. L' eroe rimane con %d punti vita\n", entita_missione_2[stanza][0], atoi(entita_missione_2[stanza][3]) - partita->giocatore.oggetti[2], partita->giocatore.vita);
                    invioPerContinuare();
                }
            }
        }

        // return true; // il giocatore è ancora in vita
        break;

    // grotta di cristallo ----------------------------
    case 3:
        // trova la stanza in cui entrare
        for (int i = 0; i < 11; i++)
        {
            // in caso che siano finite le stanze del dungeon
            if (i == 10)
            {
                printf("Non ci sono altre stanze nel dungeon\n");
                invioPerContinuare();
                return true;
            }

            if (partita->grotta_di_cristallo.stanze[i] != -1)
            {
                stanza = partita->grotta_di_cristallo.stanze[i]; // salva il valore della stanza in una variabile
                partita->grotta_di_cristallo.stanze[i] = -1;     // segna che la stanza è stata visitata
                i = 10;                                          // esce dal for
            }
        }

        // decido cosa fare in base al tipo della stanza
        if (atoi(entita_missione_3[stanza][1]) == 2)
        {
            printf("Il giocatore entra in una stanza vuota\n");
            printf("Il giocatore ritorna al menu missione\n");
            invioPerContinuare();
        }

        if (entita_missione_3[stanza][0] == "Cristalli Cadenti")
        {
            printf("Il giocatore trova %s\n", entita_missione_3[stanza][0]);
            partita->giocatore.vita -= atoi(entita_missione_3[stanza][3]) - partita->giocatore.oggetti[2];
            if (partita->giocatore.vita <= 0)
            {
                return false; // il giocatore è morto
            }
            printf("Il giocatore subisce %d di danno\n", atoi(entita_missione_3[stanza][3] - partita->giocatore.oggetti[2]));
            printf("La vita del giocatore scende a %d\n", partita->giocatore.vita);
            invioPerContinuare();
        }
        if (entita_missione_3[stanza][0] == "Ponte Pericolante")
        {
            printf("Il giocatore trova %s", entita_missione_3[stanza][0]);
            partita->giocatore.monete += atoi(entita_missione_3[stanza][4]);
            printf("Il giocatore perde %d monete, rimanendo con %d monete\n", abs(atoi(entita_missione_3[stanza][4])), partita->giocatore.monete); // voluto che le monete vanno in negativo
            invioPerContinuare();
        }
        if (entita_missione_3[stanza][0] == "Forziere Misterioso")
        {
            printf("Il giocatore trova %s\n", entita_missione_3[stanza][0]);
            printf("Viene lanciata una moneta per determinare il contenuto del forziere\n");
            int res = tiraDado() % 2; // stesse probabilità di lanciare una moneta
            invioPerContinuare();
            // 0 è la testa invec
            if (res == 0)
            { // testa

                partita->giocatore.vita -= atoi(entita_missione_3[stanza][3]) - partita->giocatore.oggetti[2];
                if (partita->giocatore.vita <= 0) // serve per controllare che il giocatore non sia morto
                {
                    return false; // il giocatore è morto
                }
                printf("È uscito testa: il giocatore subisce %d di danno, rimanendo con %d di vita\n", atoi(entita_missione_3[stanza][3]) - partita->giocatore.oggetti[2], partita->giocatore.vita);
                invioPerContinuare();
            }
            else
            { // croce
                partita->giocatore.monete += atoi(entita_missione_3[stanza][4]);
                printf("È uscito croce: il giocatore riceve %d monete, rimanendo con %d monete\n", atoi(entita_missione_3[stanza][4]), partita->giocatore.monete);
                invioPerContinuare();
            }
        }
        if (entita_missione_3[stanza][0] == "Rupe Scoscesa")
        {
            printf("Il giocatore trova %s\n", entita_missione_3[stanza][0]);
            printf("Si tira un dado per determinare il danno subito\n");
            invioPerContinuare();
            int res = tiraDado();
            printf("È uscito %d\n", res);
            partita->giocatore.vita -= res - partita->giocatore.oggetti[2];
            if (partita->giocatore.vita <= 0) // serve per controllare che il giocatore non sia morto
            {
                return false; // il giocatore è morto
            }
            printf("Il giocatore subisce %d di danno, rimanendo con %d di vita\n", res - partita->giocatore.oggetti[2], partita->giocatore.vita);
            invioPerContinuare();
        }

        if (atoi(entita_missione_3[stanza][1]) == 0)
        {
            printf("Il giocatore incontra %s e inizia il combattimento\n", entita_missione_3[stanza][0]);
            invioPerContinuare();

            int res = 0;
            while (res < atoi(entita_missione_3[stanza][2]))
            {
                printf("Viene lanciato un dado per stabilire il danno dell'eroe\n");
                res = tiraDado();
                res += partita->giocatore.oggetti[1];
                if (partita->giocatore.oggetti[1] != 0)
                {

                    printf("Il risultato: %hd (potenziato da spada)\n", res);
                }
                else
                {
                    printf("Il risultato: %hd\n", res);
                }
                if (res >= atoi(entita_missione_3[stanza][2]))
                {
                    printf("%s viene sconfitto (%hd >= %d). L'eroe rimane con %d punti vita, e riceve %d monete\n", entita_missione_3[stanza][0], res, atoi(entita_missione_3[stanza][2]), partita->giocatore.vita, atoi(entita_missione_3[stanza][4]));
                    partita->giocatore.monete += atoi(entita_missione_3[stanza][4]);

                    if (entita_missione_3[stanza][0] == "Drago Antico")
                    {
                        partita->grotta_di_cristallo.completata = true;
                        partita->giocatore.oggetti[1] = 2;
                    }
                    invioPerContinuare();
                }
                else
                { // qua si decide se il giocatore prende danno
                    printf("Attacco non sufficiente per sconfiggere %s (%hd < Colpo Fatale = %d)\n", entita_missione_3[stanza][0], res, atoi(entita_missione_3[stanza][2]));

                    int numero = (rand() % 500) + 1; // numero che il giocatore deve dire se fa parte della sequenza di Padovan

                    char tmp = ' ';
                    do
                    {
                        printf("Il drago chiede al giocatore se %d appartiene alla sequenza di Padovan [Y/N]:", numero);
                        scanf("%c", &tmp);
                        if (tmp != 'Y' && tmp != 'N' && tmp != 'y' && tmp != 'n')
                        {
                            printf("\nScelta non valida\n\n");
                            while ((tmp = getchar()) != '\n')
                            {
                            } // pulisci il buffer
                        }
                    } while (tmp != 'Y' && tmp != 'N' && tmp != 'y' && tmp != 'n'); // il si e no vengono visti come Y e N anche come y e n
                    if ((tmp == 'y' || tmp == 'Y') == isInPadovan(numero)) // giocatore indovina e non subisce il danno (si salva)
                    {
                        while ((tmp = getchar()) != '\n')
                        {
                        } // pulisci il buffer prima di uscire
                        printf("Il drago non infligge danno al giocatore\n");
                        invioPerContinuare();
                    }
                    else // giocatore subisce il danno (non indovina)
                    {
                        while ((tmp = getchar()) != '\n')
                        {
                        } // pulisci il buffer prima di uscire
                        printf("Il giocatore ha sbagliato risposta\n");
                        partita->giocatore.vita -= atoi(entita_missione_3[stanza][3]) - partita->giocatore.oggetti[2]; // atoi converte la stringa in decimale

                        if (partita->giocatore.vita <= 0)
                        {
                            return false; // il giocatore è morto
                        }

                        printf("%s infligge %d danni all' eroe, l'eroe rimane con %d punti vita\n", entita_missione_3[stanza][0], atoi(entita_missione_3[stanza][3]) - partita->giocatore.oggetti[2], partita->giocatore.vita);
                        invioPerContinuare();
                    }
                }
            }
        }
        // return true;
        break;
    }
    return true;
}

/**********************************************************MISSIONE FINALE***************************************************************** */

bool missione_finale()
{
    // scudo=sasso , magia=carta , spada=forbici
    int round = 1;                // round corrente
    int vinte_eroe = 0;           // round vinti dall'eroe
    int vinte_signore_oscuro = 0; // round vinti dal signore oscuro
    int scelta_eroe;
    int scelta_signore_oscuro;

    while (vinte_eroe < 3 && vinte_signore_oscuro < 3)
    {
        system("cls || clear");
        printf("Scontro finale | Round %d su 5 | Eroe %d - Signore Oscuro  %d\n\n", round, vinte_eroe, vinte_signore_oscuro);
        printf("Mosse disponibili\n");
        printf("\t1. scudo\n");
        printf("\t2. magia\n");
        printf("\t3. spada\n");
        do
        {
            printf("Seleziona una delle opzioni del menu [1-3]: ");
            scanf("%d", &scelta_eroe);

            if (scelta_eroe < 1 || scelta_eroe > 3)
            {
                printf("Opzione non valida, selezionare una delle opzioni\n\n");
            }

            char c;
            while ((c = getchar()) != '\n')
            {
            } // pulisci il buffer
        } while (scelta_eroe < 1 || scelta_eroe > 3);

        // genera la scelta del signore oscuro (diversa da quella dell'eroe)
        do
        {
            scelta_signore_oscuro = (rand() % 3) + 1;

        } while (scelta_signore_oscuro == scelta_eroe);
        printf("\n");
        switch (scelta_signore_oscuro) // per tradurre i numeri in cosa ha scelto il signore oscuro
        {
        case 1:
            printf("Il Signore Oscuro nel frattempo ha scelto Scudo.\n");
            break;

        case 2:
            printf("Il Signore Oscuro nel frattempo ha scelto Magia.\n");
            break;

        case 3:
            printf("Il Signore Oscuro nel frattempo ha scelto Spada.\n");
            break;
        }

        // caso: scudo <--> magia
        if ((scelta_eroe == 1 && scelta_signore_oscuro == 2) || (scelta_eroe == 2 && scelta_signore_oscuro == 1))
        {
            if (scelta_eroe == 1)
            { // caso eroe: scudo, signore: magia
                printf("L'incantesimo del Signore Oscuro infrange le difese dell'eroe.\nIl signore oscuro si aggiudica il round.\n");
                vinte_signore_oscuro++;
            }
            else
            { // caso eroe: magia, signore: scudo
                printf("L'eroe sprigiona un potere arcano che travolge le difese del nemico.\nL'eroe si aggiudica il round.\n");
                vinte_eroe++;
            }
        }
        else if ((scelta_eroe == 1 && scelta_signore_oscuro == 3) || (scelta_eroe == 3 && scelta_signore_oscuro == 1))
        { // caso scudo <--> spada
            if (scelta_eroe == 1)
            { // caso eroe: scudo, signore: spada
                printf("L'eroe solleva lo scudo con fermezza, deviando il fendente del nemico e contrattaccando con successo.\nL'eroe si aggiudica il round.\n");
                vinte_eroe++;
            }
            else
            { // caso eroe: spada, signore: scudo
                printf("Il Signore Oscuro intercetta il colpo dell'eroe con agilità.\nIl signore oscuro si aggiudica il round.\n");
                vinte_signore_oscuro++;
            }
        }
        else if ((scelta_eroe == 2 && scelta_signore_oscuro == 3) || (scelta_eroe == 3 && scelta_signore_oscuro == 2))
        { // caso magia <--> spada
            if (scelta_eroe == 2)
            { // caso eroe: magia, signore: spada
                printf("La lama del Signore Oscuro sibila nell'aria, interrompendo l'incantesimo dell'eroe.\nIl signore oscuro si aggiudica il round.\n");
                vinte_signore_oscuro++;
            }
            else
            { // caso eroe: spada, signore: magia
                printf("Con un colpo rapido e preciso, l'eroe trafigge le ombre del Signore Oscuro prima che possa lanciare la sua magia.\nL'eroe si aggiudica il round.\n");
                vinte_eroe++;
            }
        }
        invioPerContinuare();
    }

    if (vinte_eroe > vinte_signore_oscuro)
    {
        return true; // L'eroe ha sconfitto il signore oscuro
    }
    return false; // L'eroe perde
}
