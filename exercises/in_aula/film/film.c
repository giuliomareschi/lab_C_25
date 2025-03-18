//ho aggiunto i controlli sugli input

#include <stdio.h>
#define NUM_FILMS 5
#define MAX_LUNGHEZZA_TITOLO 10
#define MAX_LUNGHEZZA_GENERE 10

#define MIN_ANNO 1800
#define MAX_ANNO 2025

typedef struct
{
    unsigned int mese;
    unsigned int anno;
} data;

typedef struct
{
    char titolo[MAX_LUNGHEZZA_TITOLO];
    char genere[MAX_LUNGHEZZA_GENERE];
    data uscita;
    unsigned int durata;
} film;

int main()
{
    film archivio[NUM_FILMS] = {"", "", {0, 0}, 0}; // variabile archivio ​
    // Acquisizione input​
    for (unsigned int i = 0; i < NUM_FILMS; i++)
    {
        printf("Film n.%d Inserisci titolo: ", i + 1);
        scanf("%15s", archivio[i].titolo); // NOTA: non accetta spazi
        printf("Film n.%d Inserisci genere: ", i + 1);
        scanf("%10s", archivio[i].genere); // NOTA: non accetta spazi

        //input mese (difensivo)
        while(archivio[i].uscita.mese < 1 || archivio[i].uscita.mese > 12){
            printf("Film n.%d Inserisci mese di pubblicazione (min. 1 | max. 12): ", i + 1);
            scanf("%u", &archivio[i].uscita.mese);
            if(archivio[i].uscita.mese < 1 || archivio[i].uscita.mese > 12) puts("[!] VALORE NON VALIDO (min. 1 | max. 12)");
        }

        //input anno (difensivo)
        while(archivio[i].uscita.anno < MIN_ANNO || archivio[i].uscita.anno > MAX_ANNO){
            printf("Film n.%d Inserisci anno di pubblicazione (min. %u | max. %u): ", i + 1, MIN_ANNO, MAX_ANNO);
            scanf("%u", &archivio[i].uscita.anno);
            if(archivio[i].uscita.anno < MIN_ANNO || archivio[i].uscita.mese > MAX_ANNO) printf("[!] VALORE NON VALIDO (min. %u | max. %u)\n", MIN_ANNO, MAX_ANNO);
        }
        
        while (archivio[i].durata < 1){
            printf("Film n.%d Inserisci durata (min. 1): ", i + 1);
            scanf("%u", &archivio[i].durata);
            if (archivio[i].durata < 1) puts("[!] VALORE NON VALIDO (min. 1)");
        }
        puts("");
    }
    // Ciclo di Stampa  ​
    for (unsigned int j = 0; j < NUM_FILMS; j++)
    {
        printf("\n%s\t%s\t%u/%u\t%u\n", archivio[j].titolo, archivio[j].genere, archivio[j].uscita.mese, archivio[j].uscita.anno, archivio[j].durata);
    }
}