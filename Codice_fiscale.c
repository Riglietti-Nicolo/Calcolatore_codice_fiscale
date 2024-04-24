// Riglietti Nicolò -- 3^ informatica -- codice fiscale -- 24/04/2024

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define L 20

void calcola_cognome(char cognome[], char codice_fiscale[]) {
    
    int consonanti = 0, vocali = 0;
    int lunghezza = strlen(cognome);
    char cons[20], voc[20], cognome2[lunghezza];

    for(int i = 0; i < lunghezza; i++)
    {
        cognome2[i] = toupper(cognome[i]);
        if(cognome2[i] == 'A' || cognome2[i] == 'E' || cognome2[i] == 'I' || cognome2[i] == 'O' || cognome2[i] == 'U'){
            voc[vocali] = cognome2[i];
            vocali++;            
        } else {
            cons[consonanti] = cognome2[i];
            consonanti++;            
        }
    }

    if(consonanti >= 3){
        codice_fiscale[0] = cons[0];
        codice_fiscale[1] = cons[1];
        codice_fiscale[2] = cons[2];
    }

    if(consonanti == 2){
        codice_fiscale[0] = cons[0];
        codice_fiscale[1] = cons[1];
        codice_fiscale[2] = voc[0];
    }

    if(consonanti == 1 && vocali == 2){
        codice_fiscale[0] = cons[0];
        codice_fiscale[1] = voc[0];
        codice_fiscale[2] = voc[1];
    }

    if(consonanti == 1 && vocali == 1){
        codice_fiscale[0] = cons[0];
        codice_fiscale[1] = voc[0];
        codice_fiscale[2] = 'X';       
    }

    if(consonanti == 0 && vocali == 2){
        codice_fiscale[0] = voc[0];
        codice_fiscale[1] = voc[1];
        codice_fiscale[2] = 'X';        
    }

}

void calcola_nome(char nome[], char codice_fiscale[]) {

    int consonanti = 0, vocali = 0;
    int lunghezza = strlen(nome);
    char cons[20], voc[20], nome2[lunghezza];

    for(int i = 0; i < lunghezza; i++)
    {
        nome2[i] = toupper(nome[i]);
        if(nome2[i] == 'A' || nome2[i] == 'E' || nome2[i] == 'I' || nome2[i] == 'O' || nome2[i] == 'U'){
            voc[vocali] = nome2[i];
            vocali++;            
        }else{
            cons[consonanti] = nome2[i];
            consonanti++;            
        }
    }

    if(consonanti >= 4){
        codice_fiscale[3] = cons[0];
        codice_fiscale[4] = cons[2];
        codice_fiscale[5] = cons[3];
    }

    if(consonanti == 3){
        codice_fiscale[3] = cons[0];
        codice_fiscale[4] = cons[1];
        codice_fiscale[5] = cons[2];
    }

    if(consonanti == 2){
        codice_fiscale[3] = cons[0];
        codice_fiscale[4] = cons[1];
        codice_fiscale[5] = voc[0];
    }
    
    if(consonanti == 1 && vocali == 2){
        codice_fiscale[3] = cons[0];
        codice_fiscale[4] = voc[0];
        codice_fiscale[5] = voc[1];
    }

    if(consonanti == 1 && vocali == 1){
        codice_fiscale[3] = cons[0];
        codice_fiscale[4] = voc[0];
        codice_fiscale[5] = 'X';
    }

    if(consonanti == 0 && vocali == 2){
        codice_fiscale[3] = voc[0];
        codice_fiscale[4] = voc[1];
        codice_fiscale[5] = 'X';
    }

}

void anno_nascita(char anno[],char codice_fiscale[]) {

    int temp2=anno[2];
    int temp3=anno[3];
    
    codice_fiscale[6] = temp2;       
    codice_fiscale[7] = temp3;
}

void mese_nascita(int mese, char codice_fiscale[]) {
    switch (mese)
    {
        case 1:
            codice_fiscale[8] = 'A';
            break;

        case 2:
            codice_fiscale[8] = 'B';
            break;
        
        case 3:
            codice_fiscale[8] = 'C';
            break;

        case 4:
            codice_fiscale[8] = 'D';
            break;

        case 5:
            codice_fiscale[8] = 'E';
            break;

        case 6:
            codice_fiscale[8] = 'H';
            break;
        
        case 7:
            codice_fiscale[8] = 'L';
            break;

        case 8:
            codice_fiscale[8] = 'M';
            break; 

        case 9:
            codice_fiscale[8] = 'P';
            break;

        case 10:
            codice_fiscale[8] = 'R';
            break;
        
        case 11:
            codice_fiscale[8] = 'S';
            break;

        case 12:
            codice_fiscale[8] = 'T';
            break; 
    default:
        break;
    }     
}

void giorno_nascita(char giorno[], char codice_fiscale[], char sesso) {
    
    if(sesso == 'M'){
        codice_fiscale[9] = giorno[0];
        codice_fiscale[10] = giorno[1];}
    else if (sesso == 'F'){
        int giorno_f = atoi(giorno) + 40;
        sprintf(codice_fiscale + 9, "%02d", giorno_f);
    }
}

void codice_catastale(char comune[], char codice_fiscale[]) {

    char riga[L];
    FILE *fp;

    fp = fopen("codici_catastali.txt", "r");

    if(fp == NULL){
        printf("errore apertura del file");
        return;
    }    

    while (fgets(riga, L, fp) != NULL){

        if(strstr(riga, comune) != NULL){   
            strncpy(codice_fiscale + 11, riga, 4);
            fclose(fp);                      
        }
    }
    fclose(fp);
}

void codice_controllo(char codice_fiscale[]) {

    int r = 0, s = 0;
    char lettera_controllo;
    
    for (int i = 0; i < 15; i++) {
        if (i % 2 == 0) {
            switch (codice_fiscale[i]) {
                case 'A': case '0': r += 1; break;
                case 'B': case '1': r += 0; break;
                case 'C': case '2': r += 5; break;
                case 'D': case '3': r += 7; break;
                case 'E': case '4': r += 9; break;
                case 'F': case '5': r += 13; break;
                case 'G': case '6': r += 15; break;
                case 'H': case '7': r += 17; break;
                case 'I': case '8': r += 19; break;
                case 'J': case '9': r += 21; break;
                case 'K': r += 2; break;
                case 'L': r += 4; break;
                case 'M': r += 18; break;
                case 'N': r += 20; break;
                case 'O': r += 11; break;
                case 'P': r += 3; break;
                case 'Q': r += 6; break;
                case 'R': r += 8; break;
                case 'S': r += 12; break;
                case 'T': r += 14; break;
                case 'U': r += 16; break;
                case 'V': r += 10; break;
                case 'W': r += 22; break;
                case 'X': r += 25; break;
                case 'Y': r += 24; break;
                case 'Z': r += 23; break;
            }
        } else {
            switch (codice_fiscale[i]) {
                case 'A': case '0': r += 0; break;
                case 'B': case '1': r += 1; break;
                case 'C': case '2': r += 2; break;
                case 'D': case '3': r += 3; break;
                case 'E': case '4': r += 4; break;
                case 'F': case '5': r += 5; break;
                case 'G': case '6': r += 6; break;
                case 'H': case '7': r += 7; break;
                case 'I': case '8': r += 8; break;
                case 'J': case '9': r += 9; break;
                case 'K': r += 10; break;
                case 'L': r += 11; break;
                case 'M': r += 12; break;
                case 'N': r += 13; break;
                case 'O': r += 14; break;
                case 'P': r += 15; break;
                case 'Q': r += 16; break;
                case 'R': r += 17; break;
                case 'S': r += 18; break;
                case 'T': r += 19; break;
                case 'U': r += 20; break;
                case 'V': r += 21; break;
                case 'W': r += 22; break;
                case 'X': r += 23; break;
                case 'Y': r += 24; break;
                case 'Z': r += 25; break;
            }
        }
    }

    s = r % 26;

    switch (s) {
        case 0: lettera_controllo = 'A'; break;
        case 1: lettera_controllo = 'B'; break;
        case 2: lettera_controllo = 'C'; break;
        case 3: lettera_controllo = 'D'; break;
        case 4: lettera_controllo = 'E'; break;
        case 5: lettera_controllo = 'F'; break;
        case 6: lettera_controllo = 'G'; break;
        case 7: lettera_controllo = 'H'; break;
        case 8: lettera_controllo = 'I'; break;
        case 9: lettera_controllo = 'J'; break;
        case 10: lettera_controllo = 'K'; break;
        case 11: lettera_controllo = 'L'; break;
        case 12: lettera_controllo = 'M'; break;
        case 13: lettera_controllo = 'N'; break;
        case 14: lettera_controllo = 'O'; break;
        case 15: lettera_controllo = 'P'; break;
        case 16: lettera_controllo = 'Q'; break;
        case 17: lettera_controllo = 'R'; break;
        case 18: lettera_controllo = 'S'; break;
        case 19: lettera_controllo = 'T'; break;
        case 20: lettera_controllo = 'U'; break;
        case 21: lettera_controllo = 'V'; break;
        case 22: lettera_controllo = 'W'; break;
        case 23: lettera_controllo = 'X'; break;
        case 24: lettera_controllo = 'Y'; break;
        case 25: lettera_controllo = 'Z'; break;
    }

    codice_fiscale[15] = lettera_controllo;
    printf("codice fiscale: %s \n", codice_fiscale);
}

void nome_cognome_inverso(char codice_fiscale_inverso[]){

    char Cognome_inverso[4], Nome_inverso[4];

    Cognome_inverso[3] = '\0';
    Nome_inverso[3] = '\0';
    
    for(int i = 0; i< 3; i++)
        Cognome_inverso[i] = codice_fiscale_inverso[i];
    
    for(int i = 3; i< 6; i++)
        Nome_inverso[i - 3] = codice_fiscale_inverso[i];

    printf("cognome: %s \n nome: %s \n ", Cognome_inverso, Nome_inverso);
}

void anno_inverso(char codice_fiscale_inverso[]){

    char Anno_inverso[5];
    
    Anno_inverso[0] = codice_fiscale_inverso[6];
    Anno_inverso[1] = codice_fiscale_inverso[7];
        
    if(atoi(Anno_inverso) < 25){
        Anno_inverso[0] = '2';
        Anno_inverso[1] = '0';
        Anno_inverso[2] = codice_fiscale_inverso[6];
        Anno_inverso[3] = codice_fiscale_inverso[7];
        Anno_inverso[4] = '\0';
    } else {
        Anno_inverso[0] = '1';
        Anno_inverso[1] = '9';
        Anno_inverso[2] = codice_fiscale_inverso[6];
        Anno_inverso[3] = codice_fiscale_inverso[7];
        Anno_inverso[4] = '\0';        
    }
    printf("anno: %s \n", Anno_inverso);
}

void mese_inverso(char codice_fiscale_inverso[]) {

    switch (codice_fiscale_inverso[8]) 
    {
        case 'A':
            printf("mese: gennaio \n");
            break;

        case 'B':
            printf("mese: febbraio \n");
            break;
        
        case 'C':
            printf("mese: marzo \n");
            break;

        case 'D':
            printf("mese: aprile \n");
            break;

        case 'E':
            printf("mese: maggio \n");
            break;

        case 'H':
            printf("mese: giugno \n");
            break;
        
        case 'L':
            printf("mese: luglio \n");
            break;

        case 'M':
            printf("mese: agosto \n");
            break; 

        case 'P':
            printf("mese: settembre \n");
            break;

        case 'R':
            printf("mese: ottobre \n");
            break;
        
        case 'S':
            printf("mese: novembre \n");
            break;

        case 'T':
            printf("mese: dicembre \n");
            break; 
    default:
        break;
    }     
}

void giorno_inverso(char codice_fiscale_inverso[]) {

    int giorno = atoi(&codice_fiscale_inverso[9]);

    if (giorno >= 1 && giorno <= 31) {
        printf("giorno: %02d\n", giorno);
    } else if (giorno >= 41 && giorno <= 71) {
        giorno -= 40;
        printf("giorno: %02d\n", giorno);
    }
  
}

void codice_catastale_inverso(char codice_fiscale_inverso[]) { 

    char riga[L];
    FILE *fp;

    fp = fopen("codici_catastali.txt", "r");

    if (fp == NULL) {
        printf("Errore durante l'apertura del file \n");
        return;
    }

    char cod_catastale[5];
    strncpy(cod_catastale, codice_fiscale_inverso + 11, 4);
    cod_catastale[4] = '\0';

    while (fgets(riga, L, fp) != NULL) { 

        if (strncmp(riga, cod_catastale, 4) == 0) {
            printf("comune di nascita: %s\n", riga + 5);
            fclose(fp);
            return; 
        }
    }
    
    printf("nessun comune trovato \n");
    fclose(fp);
}

int main(void)
{   
    int scegli;

    printf("cosa vuoi fare? \n");
    printf("1. calcolo codice fiscale \n");
    printf("2. calcolo codice fiscale inverso \n");

    scanf("%d", &scegli);

    if (scegli == 1)
    {       
        char cognome[L], nome[L], anno[4], codice_fiscale[18];
        int mese;
        char giorno[3], sesso, comune[L];
        printf("inserisci il cognome:");
        scanf("%s", cognome);
        printf("inserisci il nome:");
        scanf("%s", nome);
        do
        {
            printf("inserisci l'anno di nascita:");
            scanf("%s", anno);
        } while (atoi(anno) > 2024);
        
        do
        {
            printf("inserisci il mese di nascita (in numero):");
            scanf("%d", &mese);
        } while (mese > 12 || mese < 1);    
        
        printf("inserisci il giorno di nascita:");
        scanf("%s", giorno);
        printf("sesso (M o F):");
        scanf(" %c", &sesso);
    
        printf("inserisci comune di nascita: ");
        scanf("%s", comune);

        printf("\n");

        calcola_cognome(cognome, codice_fiscale);
        calcola_nome(nome, codice_fiscale);  
    
        anno_nascita(anno, codice_fiscale);
        mese_nascita(mese, codice_fiscale);
    
        giorno_nascita(giorno, codice_fiscale, sesso);

        codice_catastale(comune, codice_fiscale);

        codice_controllo(codice_fiscale);

    } else {
        char codice_fiscale_inverso[16];

        printf("inserisci il codice fiscale: ");
        scanf(" %s", codice_fiscale_inverso);

        nome_cognome_inverso(codice_fiscale_inverso);
        anno_inverso(codice_fiscale_inverso);
        mese_inverso(codice_fiscale_inverso);
        giorno_inverso(codice_fiscale_inverso);
        codice_catastale_inverso(codice_fiscale_inverso);
    }    

    return 0;
}