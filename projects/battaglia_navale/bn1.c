//esercitazione_1
//battaglia_navale

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_COL 26 //26 = lettere dell'alfabeto
#define MAX_RIG 99 //99 = decimali con 2 cifre

/*nella matrice:
0 = no nave;
1 = nave;
2 = mancato;
3 = affondato.
*/

void nome (void){ //intestazione visiva del programma
    printf("\n+==========================+\n");
      printf("|   BATTAGLIA NAVALE 1.0   |\n");
      printf("|      Giulio Mareschi     |\n");
      printf("+==========================+\n\n");
    printf("Questo gioco simula la battaglia navale con navi di dimensione |1|.\n");
}

void user_config(int *col_mare, int *rig_mare, int *navi, int *turni) {
    // Input dimensioni mare
    puts("");
    *col_mare = 0;
    while (*col_mare < 2 || *col_mare > MAX_COL) {
        printf("[?] Inserire il numero di colonne (min 2 | max %d): ", MAX_COL);
        scanf("%d", col_mare);
        if (*col_mare < 2 || *col_mare > MAX_COL) {
            printf("[!] NUMERO NON VALIDO\n");
        }
    }
    puts("");
    *rig_mare = 0;
    while (*rig_mare < 2 || *rig_mare > MAX_RIG) {
        printf("[?] Inserire il numero di righe (min 2 | max %d): ", MAX_RIG);
        scanf("%d", rig_mare);
        if (*rig_mare < 2 || *rig_mare > MAX_RIG) {
            printf("[!] NUMERO NON VALIDO\n");
        }
    }

    // Input numero navi
    puts("");
    *navi = 0;
    while (*navi < 1 || *navi > (*col_mare * *rig_mare)) {
        printf("[?] Inserire il numero di navi (min 1 | max %d | 0 per random): ", (*col_mare * *rig_mare));
        scanf("%d", navi);
        if (*navi == 0) {
            *navi = 1 + rand() % (*col_mare * *rig_mare);
            printf("[i] Numero navi generato: %d\n", *navi);
        }
        if (*navi < 1 || *navi > (*col_mare * *rig_mare)) {
            printf("[!] NUMERO NON VALIDO\n");
        }
    }

    // Input mosse massime
    puts("");
    *turni = 0;
    while (*turni < *navi || *turni > (*col_mare * *rig_mare)) {
        printf("[?] Inserire il numero di turni (min %d | max %d | 0 per random): ", *navi, (*col_mare * *rig_mare));
        scanf("%d", turni);
        if (*turni == 0) {
            *turni = *navi + rand() % ((*col_mare * *rig_mare) - *navi + 1); //min + rand % (max-min+1)
            printf("[i] Numero turni generato: %d\n", *turni);
        }
        if (*turni < *navi || *turni > (*col_mare * *rig_mare)) {
            printf("[!] NUMERO NON VALIDO\n");
        }
    }
}

void print_mare(int col_mare, int rig_mare, int mare[][col_mare]){
    printf("\n   ");
    for (int i = 0; i<col_mare; i++){ //stampa la lettera di colonna
        printf("%c ", i+65);
    }
    puts("");

    for(int i = 0; i<rig_mare; i++){ //stampa le righe
        printf("%2d|", 1+i);
        for (int j = 0; j<col_mare; j++){
            if (mare[i][j] == 2) printf("O"); //mancato
            else if (mare[i][j] == 3) printf("X"); //affondato
            else if (mare[i][j] == 1) printf(".");
            else printf(" ");
            printf("|");
        }
        puts("");
    }
    puts("");
}

void init_navi(int col_mare, int rig_mare, int navi, int mare[][col_mare]){
    for(int i = 0; i < navi;){
        int x = rand()%col_mare;
        int y = rand()%rig_mare;
        if (mare[y][x]== 0){
            mare[y][x] = 1;
            i++;
        }
    }
}

void input_game(int *g_rig, int *g_col, int col_mare, int rig_mare, int mare[][rig_mare]){
    *g_rig = -1; 
    *g_col = -1;
    int temp_col, temp_rig;
    
    while (*g_rig < 0 || *g_col < 0){
        printf("Inserire coordinate: ");
        char input [4] = {0};
        scanf("%3s", input);

        //formato a10 o A10
        if(isalpha(input[0])){
            if(toupper(input[0]) - 65 < col_mare){
                temp_col = toupper(input[0]) - 65;
            
                if (isdigit(input[1])){
                    if (strtol(input+1, NULL, 0) - 1 < rig_mare) {
                        temp_rig = strtol(input+1, NULL, 0) - 1; //l'array parte da 0, il mare da 1
                        if (mare[temp_rig][temp_col] <= 1){ //il giocatore non può scegliere una casella già giocata
                            *g_col = temp_col;
                            *g_rig = temp_rig;
                        } else puts("[!] SCEGLIERE UN'ALTRA CASELLA");
                    } else puts("[!] INPUT NON VALIDO");
                } else puts("[!] INPUT NON VALIDO");
            } else puts("[!] INPUT NON VALIDO");
        }
        //formato 10a o 10A
 }
}

void game(int col_mare, int rig_mare, int mare[][col_mare], int turni, int *affondate){
    print_mare(col_mare, rig_mare, mare);
        
    int g_rig, g_col;
    input_game(&g_rig, &g_col, col_mare, rig_mare, mare);
    //questa funzione "restituisce" solo una casella che contiene 0 o 1
    mare[g_rig][g_col] += 2;
        
    switch (mare[g_rig][g_col]){
        case 2:
        puts("[!] NAVE MANCATA");
        break;

        case 3:
        puts("[!] NAVE AFFONDATA!");
        (*affondate)++;
        break;
    }
}

int main(void){
    srand(time(NULL)); //seme per la generazione casuale
    //mostra nome gioco
    nome();
    
    //init settaggi e input utente
    int col_mare, rig_mare, navi, turni;
    user_config(&col_mare, &rig_mare, &navi, &turni);
    
    //init mare vuoto e riempimento
    int mare[MAX_RIG][MAX_COL] = {{0}, {0}};
    init_navi(col_mare, rig_mare, navi, mare);

    //gioco
    int affondate = 0;
    int turni_effettivi = 0;
    for (int i = 0; i < turni; i++){ //ciclo per numero turni
        printf("\n-- TURNO %d/%d --\n", i+1, turni);
        game(col_mare, rig_mare, mare, turni, &affondate);
        turni_effettivi++;
        if (affondate>=navi){
            break;
        }
    }

    //fine
    printf("\n-- FINE --\n");
    print_mare(col_mare, rig_mare, mare);
    printf(" %.1f%% di navi affondate in %d turni su %d.\n\n", ((float)affondate/(float)navi)*100, turni_effettivi, turni);

    return 0;
}