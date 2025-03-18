//esercitazione_0
//BMI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAMPIONE 10
#define MIN_ETA 18
#define MAX_ETA 90
#define MIN_ALT 140
#define MAX_ALT 200
#define MIN_PESO 35
#define MAX_PESO 110

int main(void){
    srand(time(NULL));
    
    int max_alt39 = 0;
    int max_alt40 = 0;
    int max_peso39 = 0;
    int max_peso40 = 0;
    float sum_bmi39 = 0;
    float sum_bmi40 = 0;
    int n39 = 0; //contatore numero under 40
    int n40 = 0; //contatore numero over 40

    puts("---------------------");
    
    printf(" N | ETA | ALT | PESO\n - | --- | --- | ----\n"); //stampo intestazione tabella
    
    for (size_t i = 0; i < CAMPIONE; i++){

        int eta = rand() % (MAX_ETA - MIN_ETA + 1) + MIN_ETA; //eta
        _Bool over40 = 0; //
        if (eta < 40) n39++;
        else {
            n40++;
            over40 = 1;
        }
        
        int altezza = rand() % (MAX_ALT - MIN_ALT + 1) + MIN_ALT; //altezza
        if (!over40) { //aggiornamento altezza massima
            if (altezza>max_alt39) max_alt39 = altezza;
        } else {
            if (altezza>max_alt40) max_alt40 = altezza;
        }
        
        int peso = rand() % (MAX_PESO - MIN_PESO + 1) + MIN_PESO; //peso
        if (!over40) { //aggiornamento peso massimo
            if (peso>max_peso39) max_peso39 = peso;
        } else {
            if (peso>max_peso40) max_peso40 = peso;
        }
        
        float bmi = peso / ( (((float)altezza)/100)*(((float)altezza)/100) );
        if (!over40) sum_bmi39 += bmi;
        else sum_bmi40 += bmi;
        
        printf("%2zu | %3d | %3d |  %3d\n", i+1, eta, altezza, peso);
    }
    
    puts("---------------------");
    
    if (n39 > 0){ //controllo esistenza under 40, evitare /0
        printf("UNDER 40 (%d nel campione)\n", n39); //dati under 40
        float medium_bmi39 = sum_bmi39 / n39;
        printf("MED BMI = %.2f\nMAX ALTEZZA = %d\nMAX PESO = %d\n", medium_bmi39, max_alt39, max_peso39);
        if (medium_bmi39 < 18.5) puts("Insieme mediamente SOTTOPESO"); //categoria under 40
        else if (medium_bmi39 < 25.0) puts("Insieme mediamente NORMOPESO");
        else puts("Insieme mediamente SOVRAPPESO");
    } else puts ("NO UNDER 40 NEL CAMPIONE");

    puts("---");
    

    if (n40 > 0) { //controllo esistenza over 40
        printf("OVER 40 (%d nel campione)\n", n40); //dati over 40
        float medium_bmi40 = sum_bmi40 / n40;
        printf("MED BMI = %.2f\nMAX ALTEZZA = %d\nMAX PESO = %d\n", medium_bmi40, max_alt40, max_peso40);
        if (medium_bmi40 < 18.5) puts("Insieme mediamente SOTTOPESO"); //categoria over 40
        else if (medium_bmi40 < 25.0) puts("Insieme mediamente NORMOPESO");
        else puts("Insieme mediamente SOVRAPPESO");
    }

    puts("---");
    
    return 0;
}