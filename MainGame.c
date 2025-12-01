//*****************************************LIBRERIE**********************************************
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// *****************************************STRUTTURE DATI*****************************************

struct Player
{
    int vita; // massimo 20
    int monete;
    /*
    gli oggetti sono:
     - [0] pozione curativa
     - [1] spada / spada dell'eroe (nello stesso slot)
     - [2] armatura
     - [3] chiave del castello del signore oscuro
    */
    int oggetti[4];
};

struct Missione
{
    bool completata; // segna se la missione è completata
    int tipo;        // segna il tipo della missione: 0 = palude putrescente, 1 = magione infestata, 2 = grotta di cristallo
    int stanze[10];  // stanze della missione (da generare proceduralmente)
};

struct Partita
{
    struct Player giocatore;
    struct Missione palude_putrescente;
    struct Missione magione_infestata;
    struct Missione grotta_di_cristallo;
    // la missione finale viene gestita in modo diverso (sasso, carta, forbice)
};

// *****************************************VARIABILI GLOBALI*****************************************
// variabili globali per i mob e trappole dove in ordine abbiamo : 1."nome entità " , 2."tipologia dell'entità" 0=fight 1=trap , 3."danno che one shotta l'entità", 4."danno dell'entità", 5."Monete ottenute alla sconfitta"

// mostri e trappole per la prima missione
const char *entita_missione_1[6][5] = {
    {"Cane Selvaggio", "0", "2", "1", "0"},
    {"Goblin", "0", "3", "2", "2"},
    {"Scheletro", "0", "4", "2", "4"},
    {"Orco", "0", "3", "4", "6"},
    {"Acquitrino Velenoso", "1", "0", "d", "0"},
    {"Generale Orco", "0", "6", "3", "12"},
};

// mostri e trappole per la seconda missione
const char *entita_missione_2[6][5] = {{"Botola Buia", "1", "0", "3", "0"}, {"Pipistrello", "0", "3", "1"}, {"Zombie", "0", "3", "2", "2"}, {"Fantasma", "5", "2", "4", "4"}, {"Vampiro Superiore", "0", "4", "4", "7"}, {"Demone Custode", "0", "4", "6", "10"}};

// mostri e trappole per la terza missione
const char *entita_missione_3[6][5] = {{"Stanza Vuota", "2", "0", "0", "0"}, {"Cristalli Cadenti", "1", "0", "2", "0"}, {"Ponte Pericolante", "1", "0", "0", "-3"}, {"Forziere Misterioso", "1", "0", "2", "10"}, {"Rupe Scoscesa", "1", "0", "d", "0"}, {"Drago Antico", "0", "5", "10", "12"}};
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
int menuVillaggio()
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
    } while (valido);

    return opzione;
}

//*************************************CREA STANZE*******************************************

void creaStanze(int tipo)
{

    // genera il contenuto stanze in base al tipo
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
            .palude_putrescente = {.completata = false, .tipo = 0, .stanze = {-1}},

            // inizializzazione della seconda missione
            .magione_infestata = {.completata = false, .tipo = 1, .stanze = {-1}},

            // inizializzazione della terza missione
            .grotta_di_cristallo = {.completata = false, .tipo = 2, .stanze = {-1}}};
}

//************************************** MAIN *********************************************
int main(void)
{

    // VARIABILI

    while (true)
    {
        // crea menu principale e fa selezionare l'azione da compiere
        char scelta = menuPrincipale(false); // false: non ha sbloccato i trucchi di default
        printf("scelta: %c\n", scelta);

        // compie l'azione selezionata
        switch (scelta)
        {
        case '1': // nuova partita
            nuovaPartita();
            printf("1\n");
            break;

        case '2': // carica partita
            printf("2\n");
            break;

        case '3': // trucchi
            printf("3\n");
            break;
        }

        int sceltaVillaggio = menuVillaggio();
        
        switch (sceltaVillaggio)
        {
        case 1: // intraprendi una missione
            printf("Intraprende una missione\n");
            break;

        case 2: // riposati
            printf("Si riposa\n");
            break;

        case 3: // inventario
            printf("Apre inventario\n");
            break;

        case 4: // Salva Partita
            printf("Salva la partita\n");
        break;
        
        case 5: // esci
            printf("Sei uscito\n");
        break;
        }
        
        scanf("%d", &sceltaVillaggio);
    }
}