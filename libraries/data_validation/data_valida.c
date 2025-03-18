//data_valida

#include <stdio.h>

_Bool prendiData (int *);

int main (void){
    puts("Questo programma controlla se una data è valida.");
    int data[3];
    while(!prendiData(data)){
        puts("DATA NON VALIDA! RIPROVARE");
        puts("");
    }
    printf("DATA %2d/%2d/%4d VALIDA\n", data[0],data[1],data[2]);
    return 0;
}

_Bool prendiData (int array[3]){ //restituisce 1 se prende la data correttamente, 0 se non la prende
    int giorno = 0;
    int mese = 0;
    int anno = 0;
    int giorni_mese[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while (1){ //ciclo per il giorno
        printf("%s", "Inserire giorno (formato gg): ");
        scanf("%d", &giorno);
        if (giorno < 1 || giorno > 31) {
            puts("Inserito giorno non valido!");
            continue;
        }
        break;
    }
    
    while (1){ //ciclo per il mese
        printf("%s", "Inserire mese (formato mm): ");
        scanf("%d", &mese);
        if (mese < 1 || mese > 12) {
            puts("Inserito mese non valido!");
            continue;
        } else if (giorno > giorni_mese[mese - 1]) {
                puts("Giorno inesistente nel mese inserito!");
                return 0;
        }
        break;
    }
    
    while (1){ //ciclo per l'anno
        printf("%s", "Inserire anno (formato aaaa): ");
        scanf("%d", &anno);
        if (anno < 0 || anno > 9999) {
            puts("Inserito anno non valido!");
            continue;
        } else if
            ( !( anno%400==0 || (anno%4==0 && !(anno%100==0)) ) )
        {
            if (mese == 2 && giorno == 29){
                printf("29/02 non esiste nell'anno %d!\n", anno);
                return 0;
            }
        }
        break;
    }
    
    array[0] = giorno;
    array [1] = mese;
    array [2] = anno;
    return 1;
}