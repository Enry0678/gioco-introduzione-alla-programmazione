#include <stdio.h>

int menuPrincipale()
{
    int scelta;
    printf("Menu Principale:\n\n");
    printf("\t1. Nuova Partita\n");
    printf("\t2. Carica Salvataggio\n\n");
    printf("Seleziona una delle opzioni del menu [1-2]:");
    scanf("%d", &scelta);
    return scelta;
}

int main(void){
    int scelta = menuPrincipale();
    printf("scelta: %d\n", scelta);
}