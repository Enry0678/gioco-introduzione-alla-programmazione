//*****************************************LIBRERIE**********************************************
#include "funzioni.h"
#include "lista.h"

// *****************************************VARIABILI GLOBALI*****************************************
// variabili globali per i mob e trappole dove in ordine abbiamo : 1."nome entità " , 2."tipologia dell'entità" 0=fight 1=trap , 3."danno che one shotta l'entità", 4."danno dell'entità", 5."Monete ottenute alla sconfitta"

// mostri e trappole per la prima missione
const char const *entita_missione_1[6][5] = {
    {"Cane Selvaggio", "0", "2", "1", "0"},
    {"Goblin", "0", "3", "2", "2"},
    {"Scheletro", "0", "4", "2", "4"},
    {"Orco", "0", "3", "4", "6"},
    {"Acquitrino Velenoso", "1", "0", "d", "0"},
    {"Generale Orco", "0", "6", "3", "12"},
};

// mostri e trappole per la seconda missione
const char const *entita_missione_2[6][5] = {{"Botola Buia", "1", "0", "3", "0"}, {"Pipistrello", "0", "2", "2", "1"}, {"Zombie", "0", "3", "2", "2"}, {"Fantasma", "0", "5", "2", "4"}, {"Vampiro Superiore", "0", "4", "4", "7"}, {"Demone Custode", "0", "4", "6", "10"}};

// mostri e trappole per la terza missione
const char const *entita_missione_3[6][5] = {{"Stanza Vuota", "2", "0", "0", "0"}, {"Cristalli Cadenti", "1", "0", "2", "0"}, {"Ponte Pericolante", "1", "0", "0", "-3"}, {"Forziere Misterioso", "1", "0", "2", "10"}, {"Rupe Scoscesa", "1", "0", "d", "0"}, {"Drago Antico", "0", "5", "10", "12"}};

//**************************************TIRA DADO************************************************

short int tiraDado()
{
    return (rand() % 6) + 1;
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
    case 0:
        int contatoreOrco = 0;
        int j;
        for (j = 0; j < 7; j++) // ciclo for per generare le prime 7 stanze
        {
            partita->palude_putrescente.stanze[j] = tiraDado() - 1; // genera un numero pseudo-casuale tra 0 e 5
            if (partita->palude_putrescente.stanze[j] == 5) // controllo se è stato generato un orco
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
    case 1:
        i = 0;
        int contatoreVampiro = 0; // conta quanti vampiri sono stati generati
        int contatoreDemone = 0;  // conta quanti demoni sono stati generati
        for (i; i < 10 - (2 - contatoreVampiro - contatoreDemone); i++) // riserva gli spazi per la forzatura
        { 
            partita->magione_infestata.stanze[i] = tiraDado() - 1;

            // controllo dei requisiti
            //controllo del vampiro superiore
            if (partita->magione_infestata.stanze[i] == 4)
            {
                //rigenera la stanza in caso ci sia già un vampiro superiore
                if(partita->magione_infestata.stanze[i]==4 && contatoreVampiro>=1){
                    partita->magione_infestata.stanze[i] = tiraDado()%4;
                }
                // conta quanti vampiri ci sono (PER FORZA 1 solo)
                if (contatoreVampiro == 0)
                {
                    contatoreVampiro++;
                }
            }
            
            //controllo del demone custode
            if (partita->magione_infestata.stanze[i] == 5)
            {
                // rigenera la stanza in caso ci sia già un demone custode 
                if(partita->magione_infestata.stanze[i]==5 && contatoreDemone>=1){
                    partita->magione_infestata.stanze[i] = tiraDado()%4;
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
    case 2:

    int contatoreDrago = 0;
    for(i=0;i<9;i++){
        partita->grotta_di_cristallo.stanze[i]=tiraDado()-1;
        if(partita->grotta_di_cristallo.stanze[i]==5){
            contatoreDrago++;
        }
        if(contatoreDrago==1){
            break;
        }
    }
    for(int k=contatoreDrago;k<1;k++){
        partita->grotta_di_cristallo.stanze[i++]=5;
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

        creaStanze(partita, scelta - 1);
        return scelta;
    }
    else
    {
        printf("\t4. Castello del Signore Oscuro\n\n");
        printf("Hai completato tutte le missioni, digita INVIO per affrontare la missione finale\n");
        char c;
        // svuota il buffer per preparare il getchar()
        while ((c = getchar()) != '\n')
        {
        }
        printf("Premi invio per continuare...");

        ungetc('A', stdin); // inserisce nel buffer il valore "A" per permettere """l'invio istantaneo"""
        getchar();          // aspetta l'invio
        while ((c = getchar()) != '\n')
        {
        } // svuota il buffer per evitare dati indesiderati
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

        if(selezione < 1 || selezione > 4){
            printf("Scelta non valida\n\n");
            char c;
            while ((c = getchar()) != '\n')
            {
            }
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
    printf("Seleziona un item da acquistare:\n\n");
    printf("\t_______________________________________________________________________________________________\n");
    printf("\t|  OGGETTO     |                       DESCRIZIONE                                   |  COSTO  |\n");
    printf("\t| 1. Pozione:  |  Curativa Ripristina fino a 6 Punti Vita (lancia un dado a 6 facce) |   4     |\n ");
    printf("\t| 2. Spada:    |  +1 all’attacco dell’eroe (acquistabile una volta sola)             |   5     |\n");
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
                printf("Hai acquistato la pozione\n\n");
                partita->giocatore.oggetti[0]++;
                partita->giocatore.monete -= 4;
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
                printf("Hai acquistato la spada\n\n");
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
                printf("Hai acquistato la l'armatura\n\n");
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
/*
  struct tm *t = localtime(&now);

  printf("Year: %d\n", t->tm_year + 1900);
  printf("Month: %d\n", t->tm_mon + 1);
  printf("Day: %d\n", t->tm_mday);
  printf("Hour: %d\n", t->tm_hour + 1);
  printf("Minute: %d\n", t->tm_min);
  printf("Second: %d\n", t->tm_sec);
  */
void salvaPartita(struct Partita p, list_t* salvataggi){
    l_push_back(salvataggi, p); //salva (creando il nodo automaticamente) nella lista dei salvataggi
    return;
}

void caricaPartita(struct Partita* p, list_t* salvataggi, int index){
    *p = pull(salvataggi, index);
    return;
}

int menuCaricaPartita(list_t* salvataggi, struct Partita* partita){
    system("cls || clear");
    printf("Salvataggi:\n");
    if(l_stampa(salvataggi)){
        int scelta=0;
        do{
            printf("Seleziona un salvataggio da caricare: ");
            scanf("%d", &scelta);
            //casi problematici
            caricaPartita(partita, salvataggi, scelta);
            if(scelta<1 || scelta > n_partita || partita->tempo.tm_mday == -1){
                printf("Scelta non valida, inserire un salvataggio esistente\n");
            }
        }
        while(scelta<1 || scelta > n_partita || partita->tempo.tm_mday == -1);
    }
    else{
        *partita = nuovaPartita();

        printf("Premi invio per continuare...");
        ungetc('A', stdin); // inserisce nel buffer il valore "A" per permettere """l'invio istantaneo"""
        getchar();          // aspetta l'invio
        char c;
        while ((c = getchar()) != '\n')
        {
        } // svuota il buffer per evitare dati indesiderati
    }
    

    
    
    
}


