//esercitazione 2
//classe_libretti

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOLTE 2
#define WORD_L 20
#define MAX_MATRICOLA 10000

typedef struct{
    unsigned short int giorno;
    unsigned short int mese;
    unsigned short int anno;
} data;

typedef struct {
    char nome [WORD_L];
    char cognome[WORD_L];
    data nascita;
    unsigned short int matricola;
    unsigned short int libretto [20];
    float media;
} studente;

int main (void){
    int seed = time(NULL);
    srand(seed);

    printf("-- ES. 2\n-- CLASSE LIBRETTO\n-- Giulio Mareschi\n\n"); //intestazione

    studente classe[VOLTE] = {"", "", {0, 0, 0}, 0, {0}, 0.0}; //init classe

    unsigned short int frequenza_voti[14] = {0};

    //ciclo studenti
    for (int i = 0; i < VOLTE; i++){

        //input dati utente
        printf("STUDENTE %d/%d\n", i+1, VOLTE);

        //input nome completo
        printf("Inserire nome e cognome: ");
        scanf("%s%s", classe[i].nome, classe[i].cognome);

        //input data
        while(classe[i].nascita.giorno <= 0 || classe[i].nascita.mese <= 0 || classe[i].nascita.anno <= 0){
            printf("Inserire data di nascita (formato gg-mm-aaaa): ");
            char input_data [11] = {""};
            scanf("%10s", input_data);

            if (strtol(input_data + 6, NULL, 10) >= 1900 && strtol(input_data + 6, NULL, 10) <= 2025){ //controllo anno
                classe[i].nascita.anno = strtol(input_data + 6, NULL, 10);
                if (strtol(input_data + 3, NULL, 10) >= 1 && strtol(input_data + 3, NULL, 10) <= 12){ //controllo mese
                    classe[i].nascita.mese = strtol(input_data + 3, NULL, 10);

                    int giorni_mese[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //array giorni per mese
                    if (strtol(input_data, NULL, 10) >= 1 && strtol(input_data, NULL, 10) <= giorni_mese[classe[i].nascita.mese - 1]){ //controllo giorno
                        classe[i].nascita.giorno = strtol(input_data, NULL, 10);
                    } else puts ("[!] DATA NON VALIDA");
                } else puts ("[!] DATA NON VALIDA");
            } else puts ("[!] DATA NON VALIDA");
        }

        while (classe[i].matricola <= 0){
        printf("Inserire matricola, 0 per random: ");
        scanf("%hu", &classe[i].matricola);
        if (classe[i].matricola == 0) {
            classe[i].matricola = 1 + rand() % MAX_MATRICOLA;
        } else if (classe[i].matricola < 0) puts("[!] MATRICOLA NON VALIDA");
        }
        
        //generazione del libretto
        unsigned short int somma_voti = 0;
        for (int j = 0; j < 20; j++){
            classe[i].libretto[j] = 18 + rand() % 14;
            frequenza_voti[classe[i].libretto[j]-18]++; 
            classe[i].media += classe[i].libretto[j]; 
        }

        classe[i].media /= 20.0;
        printf("\nMEDIA DELLO STUDENTE %d = %.2f\n\n", i+1, classe[i].media);
    }

    //studente con la media più alta
    float max_media = 0;
    unsigned short int indice = 0;
    
    for (int i = 0; i < VOLTE; i++){
        if (classe[i].media > max_media){
            max_media = classe[i].media;
            indice = i;
        }
    }
    printf("BEST STUDENT: %s %s (%.2f)\n", classe[indice].nome, classe[indice].cognome, max_media);
    
    puts("");
    
    //contatore_voti
    printf("VOTO | VOLTE\n");

    for (int i = 0; i < 14; i++){
        printf("%3d  |   %-3d\n", i+18, frequenza_voti[i]);
    }
    puts("");
    
    return 0;
}