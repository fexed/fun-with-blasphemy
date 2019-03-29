#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <spandsp.h>
#include <unistd.h>

#define NUMBER_OF_COMPLEMENTS   7
#define NUMBER_OF_VERBS         7
#define CONST 100
void printRandmWordFromFile(char **vettoreStringhe, int numeroElementiNelFile, int *vettoreOccupazionale);

/**
 * S santo
 * I insulto
 * X quello che uso per produrre
 * V verbo
 * C complemento (poi si diversificherà nei vari complementi, con verbi transitivi e intransitivi)
 *
 * PROVO A DEFINIRE UNA GRAMMATICA CHE E' MOLTO PIU' FACILMENTE DA ME CAPIBILE E IMPLEMENTABILE:
 *
 * S -> s
 * S -> sX
 * X -> IX
 * X -> vcX
 * C -> cX
 *
 * Con questa grammatica base posso generare bestemmie quantomeno carine, decidendo prima a priori una lunghezza massima
 * che esse devono raggiungere.
 */

int main(int argc, char* argv[]) {
    FILE* saintsM = NULL;
    FILE* saintsF = NULL;
    FILE* insultsM = NULL;
    FILE* insultsF = NULL;
    FILE* verbsCoggetto = NULL;
    FILE* verbsCMezzo = NULL;
    FILE* complementsOggetto = NULL;
    FILE* complementsMezzo = NULL;

    //SANTI
    char *santoM = "Sm";
    char *santoF = "Sf";
    //INSULTI
    char *insultoM = "Im";
    char *insultoF = "If";
    //VERBI
    char *verboCOggetto = "Voggetto";
    char *verboCSpecificazione = "Vspecificazione";
    char *verboCDenominazione = "Vdenominazione";
    char *verboCPartitivo = "Vpartitivo";
    char *verboCParagone = "Vparagone";
    char *verboCTermine = "Vtermine";
    char *verboCMezzo = "Vmezzo";
    //COMPLEMENTI
    char *complementoOggetto = "Coggetto";
    char *complementoSpecificazione = "Cspecificaizone";
    char *complementoDenominazione = "Cdenominazione";
    char *complementoPartitivo = "Cpartitivo";
    char *complementoParagone = "CParagone";
    char *complementoTermine = "Ctermine";
    char *complementoMezzo = "Cmezzo";
    //NONTERMINALI PER INSERIMENTO
    char *inserimentoInsultoMaschile = "Xim";
    char *inserimentoInsultoFemminile = "Xif";
    char *inserimento = "X";

    srand((unsigned)time(NULL));
    int randomic = rand()%10+1;

    char gender;

    char *current;

    if(argc < 3) {
    	printf("usage: %s <n produzioni> <lunghezza>\n", argv[0]);
    	return -1;
    }

    if(randomic %2 == 0){
        current = santoM;
        gender = 'M';
    }
    else{
        current = santoF;
        gender = 'F';
    }

    int numeroProduzioni = 0;
    char *input = malloc(sizeof(int));
    //printf("Quante: ");
    //scanf("%s",input);
    numeroProduzioni = atoi(argv[1]);

    int lunghezza = 0;
   	//input = malloc(sizeof(int));
    //printf("Lunghezza: ");
    //scanf("%s",input);
    lunghezza = atoi(argv[2]);


    char *risultati[numeroProduzioni][lunghezza];
    char *risultato[lunghezza];
    for (int l = 0; l < lunghezza; ++l)
        //risultato[l] = malloc(CONST);

    for (int m = 0; m < numeroProduzioni; ++m) {
        for (int i = 0; i < lunghezza; ++i) {
            //risultati[m][i] = malloc(CONST);
        }
    }

    risultato[0] = strdup(current);
    risultato[1] = strdup(inserimento);
    int scorrimento = 1;
    int produzioni = 0;

    bool condition = true;

    for (int i = 0; i < numeroProduzioni; ++i) {
        //sleep(1);
        while (condition){
            srand((unsigned)time(NULL)+rand());
            randomic = rand()%100+1;
            if(strcmp(risultato[scorrimento],inserimento) == 0){
                if(randomic%2 == 0){
                    if(gender == 'M')
                        risultato[scorrimento] = strdup(insultoM);
                    else
                        risultato[scorrimento] = strdup(insultoF);
                    risultato[scorrimento+1] = strdup(inserimento);
                    scorrimento++;
                } else{
                    if(randomic % NUMBER_OF_VERBS == 0){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoOggetto);
                    }else if(randomic % NUMBER_OF_VERBS == 1){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoOggetto);
                    }else if(randomic % NUMBER_OF_VERBS == 2){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoMezzo);
                    }else if(randomic % NUMBER_OF_VERBS == 3){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoOggetto);
                    }else if(randomic % NUMBER_OF_VERBS == 4){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoOggetto);
                    }else if(randomic % NUMBER_OF_VERBS == 5){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoOggetto);
                    }else if(randomic % NUMBER_OF_VERBS == 6){
                        risultato[scorrimento] = strdup(verboCOggetto);
                        risultato[scorrimento+1] = strdup(complementoOggetto);
                    }
                    risultato[scorrimento+2] = strdup(inserimento);
                    scorrimento+=2;
                }
            }
            if (scorrimento+2 >= lunghezza)
                condition = false;
        }
        //stampo cosa ha generato la grammatica
        //printf("\nLa grammatica ha generato: ");
        //for (int k = 0; k < lunghezza; ++k)
            //printf("%s",risultato[k]);
        //salvo cioò che la grammatica ha generato
        for (int k = 0; k < lunghezza; ++k)
            risultati[produzioni][k] = strdup(risultato[k]);
        produzioni++;
        if(randomic %2 == 0){
            current = santoM;
            gender = 'M';
        }
        else{
            current = santoF;
            gender = 'F';
        }
        risultato[0] = strdup(current);
        risultato[1] = strdup(inserimento);
        scorrimento = 1;
        for (int j = scorrimento+1; j < lunghezza; ++j) {
            risultato[j] = strdup("");
        }
        //printf("\nLa grammatica ha generato: %s",risultato);
        condition = true;
    }

    //traduzione
    saintsM = fopen("../santi/santiM.txt","r");
    saintsF = fopen("../santi/santiF.txt","r");
    insultsM = fopen("../insulti/insultiM.txt","r");
    insultsF = fopen("../insulti/insultiF.txt","r");
    verbsCoggetto = fopen("../verbi/verbi_C_oggetto.txt","r");
    verbsCMezzo = fopen("../verbi/verbi_C_mezzo.txt","r");
    complementsOggetto = fopen("../complementi/C_oggetto.txt","r");
    complementsMezzo = fopen("../complementi/C_mezzo.txt","r");

    char *trash = malloc(50);

    //prendo direttamente subito tutto il contenuto dei file e lo salvo in vettori
    //santiM
    //free(input);
    input = malloc(50);
    fscanf(saintsM,"%s",input);
    int numeroSantiFaschi = atoi(input);
    //printf("\nNumero santi maschi %d",numeroSantiFaschi);
    char *santiM[numeroSantiFaschi];
    fgets(trash,50,saintsM);
    for (int n = 0; n < numeroSantiFaschi; ++n) {
        santiM[n] = malloc(50);
        fgets(santiM[n],50,saintsM);
        for (int j = 0; j < 50; ++j) {
            if(santiM[n][j] == '\n' || santiM[n][j] == '\r')
                santiM[n][j]='\0';
        }
    }
    int vOccSM[numeroSantiFaschi];
    for (int i1 = 0; i1 < numeroSantiFaschi; ++i1) {
        vOccSM[i1] = 0;
        //printf("-%s, ",santiM[i1]);
    }
    //printf("\n");
    //santiF
    free(input);
    input = malloc(50);
    fscanf(saintsF,"%s",input);
    int numeroSantiFemmine = atoi(input);
    //printf("\nNumero santi maschi %d",numeroSantiFaschi);
    fgets(trash,50,saintsF);
    char *santiF[numeroSantiFemmine];
    for (int n = 0; n < numeroSantiFemmine; ++n) {
        santiF[n] = malloc(50);
        fgets(santiF[n],50,saintsF);
        for (int j = 0; j < 50; ++j) {
            if(santiF[n][j] == '\n' || santiF[n][j] == '\r')
                santiF[n][j]='\0';
        }
    }
    int vOccSF[numeroSantiFemmine];
    for (int i1 = 0; i1 < numeroSantiFemmine; ++i1) {
        vOccSF[i1] = 0;
        //printf("-%s, ",santiF[i1]);
    }
    //InsultiM
    free(input);
    input = malloc(50);
    fscanf(insultsM,"%s",input);
    int numeroInsultiM = atoi(input);
    fgets(trash,50,insultsM);
    char *insultiM[numeroInsultiM];
    for (int n = 0; n < numeroInsultiM; ++n) {
        insultiM[n] = malloc(50);
        fgets(insultiM[n],50,insultsM);
        for (int j = 0; j < 50; ++j) {
            if(insultiM[n][j] == '\n' || insultiM[n][j] == '\r')
                insultiM[n][j]='\0';
        }
    }
    int vOccIM[numeroInsultiM];
    for (int i1 = 0; i1 < numeroInsultiM; ++i1) {
        vOccIM[i1] = 0;
    }
    //InsultiF
    free(input);
    input = malloc(50);
    fscanf(insultsF,"%s",input);
    int numeroInsultiF = atoi(input);
    fgets(trash,50,insultsF);
    char *insultiF[numeroInsultiF];
    for (int n = 0; n < numeroInsultiF; ++n) {
        insultiF[n] = malloc(50);
        fgets(insultiF[n],50,insultsF);
        for (int j = 0; j < 50; ++j) {
            if(insultiF[n][j] == '\n' || insultiF[n][j] == '\r')
                insultiF[n][j]='\0';
        }
    }
    int vOccIF[numeroInsultiF];
    for (int i1 = 0; i1 < numeroInsultiF; ++i1) {
        vOccIF[i1] = 0;
    }
    //Verbi Complemento Oggetto
    free(input);
    input = malloc(50);
    fscanf(verbsCoggetto,"%s",input);
    int numeroVerbiCOggetto = atoi(input);
    fgets(trash,50,verbsCoggetto);
    char *verbiCOggetto[numeroVerbiCOggetto];
    for (int n = 0; n < numeroVerbiCOggetto; ++n) {
        verbiCOggetto[n] = malloc(50);
        fgets(verbiCOggetto[n],50,verbsCoggetto);
        for (int j = 0; j < 50; ++j) {
            if(verbiCOggetto[n][j] == '\n' || verbiCOggetto[n][j] == '\r')
                verbiCOggetto[n][j]='\0';
        }
    }
    int vOccVCO[numeroVerbiCOggetto];
    for (int i1 = 0; i1 < numeroVerbiCOggetto; ++i1) {
        vOccVCO[i1] = 0;
    }
    //Verbi Complemento Mezzo
    free(input);
    input = malloc(50);
    fscanf(verbsCMezzo,"%s",input);
    int numeroVerbiCMezzo = atoi(input);
    fgets(trash,50,verbsCMezzo);
    char *verbiCMezzo[numeroVerbiCMezzo];
    for (int n = 0; n < numeroVerbiCMezzo; ++n) {
        verbiCMezzo[n] = malloc(50);
        fgets(verbiCMezzo[n],50,verbsCMezzo);
        for (int j = 0; j < 50; ++j) {
            if(verbiCMezzo[n][j] == '\n' || verbiCMezzo[n][j] == '\r')
                verbiCMezzo[n][j]='\0';
        }
    }
    int vOccVCM[numeroVerbiCMezzo];
    for (int i1 = 0; i1 < numeroVerbiCMezzo; ++i1) {
        vOccVCM[i1] = 0;
    }
    //Complementi Oggetto
    free(input);
    input = malloc(50);
    fscanf(complementsOggetto,"%s",input);
    int numeroComplementiOggetto = atoi(input);
    fgets(trash,50,complementsOggetto);
    char *complementiOggetto[numeroComplementiOggetto];
    for (int n = 0; n < numeroComplementiOggetto; ++n) {
        complementiOggetto[n] = malloc(50);
        fgets(complementiOggetto[n],50,complementsOggetto);
        for (int j = 0; j < 50; ++j) {
            if(complementiOggetto[n][j] == '\n' || complementiOggetto[n][j] == '\r')
                complementiOggetto[n][j]='\0';
        }
    }
    int vOccCO[numeroComplementiOggetto];
    for (int i1 = 0; i1 < numeroComplementiOggetto; ++i1) {
        vOccCO[i1] = 0;
    }
    //Complementi Mezzo
    fscanf(complementsMezzo,"%s",input);
    int numeroComplementiMezzo = atoi(input);
    fgets(trash,50,complementsMezzo);
    char *complementiMezzo[numeroComplementiMezzo];
    for (int n = 0; n < numeroComplementiMezzo; ++n) {
        complementiMezzo[n] = malloc(50);
        fgets(complementiMezzo[n],50,complementsMezzo);
        for (int j = 0; j < 50; ++j) {
            if(complementiMezzo[n][j] == '\n' || complementiMezzo[n][j] == '\r')
                complementiMezzo[n][j]='\0';
        }
    }
    int vOccCM[numeroComplementiMezzo];
    for (int i1 = 0; i1 < numeroComplementiMezzo; ++i1) {
        vOccCM[i1] = 0;
    }
    char *extracted = malloc(20);

    //printf("\n");

    for (int k = 0; k < produzioni; ++k) {
        fflush(stdout);
        //printf("\nECCONE UNA: ");
        for (int i = 0; i < lunghezza; ++i) {
            if(strcmp(risultati[k][i], santoM) == 0 ){
                printRandmWordFromFile(santiM,numeroSantiFaschi,vOccSM);
            }else if (strcmp(risultati[k][i], santoF) == 0 ){
                printRandmWordFromFile(santiF,numeroSantiFemmine,vOccSF);
            }
            else if(strcmp(risultati[k][i], insultoM) == 0 ){
                printRandmWordFromFile(insultiM,numeroInsultiM,vOccIM);
            }else if(strcmp(risultati[k][i], insultoF) == 0 ){
                printRandmWordFromFile(insultiF,numeroInsultiF,vOccIF);
            }
            else if(strcmp(risultati[k][i], verboCOggetto) == 0 ){
                printRandmWordFromFile(verbiCOggetto,numeroVerbiCOggetto,vOccVCO);
            }else if(strcmp(risultati[k][i], verboCMezzo) == 0 ){
                printRandmWordFromFile(verbiCMezzo,numeroVerbiCMezzo,vOccVCM);
            }
            else if(strcmp(risultati[k][i], complementoOggetto) == 0 ){
                printRandmWordFromFile(complementiOggetto,numeroComplementiOggetto,vOccCO);
            }else if(strcmp(risultati[k][i], complementoMezzo) == 0 ){
                printRandmWordFromFile(complementiMezzo,numeroComplementiMezzo,vOccCM);
            }
            else if(risultati[k][i] == inserimento){
                //non fare un bel cazzo di niente
                //fexed: LOL
            } else{
                //printf("\n");
                break;
            }
        }
        //resetto i vettori occupazionali
        for (int i1 = 0; i1 < numeroSantiFaschi; ++i1)
            vOccSM[i1] = 0;
        for (int i1 = 0; i1 < numeroSantiFemmine; ++i1)
            vOccSF[i1] = 0;
        for (int i1 = 0; i1 < numeroInsultiM; ++i1)
            vOccIM[i1] = 0;
        for (int i1 = 0; i1 < numeroInsultiM; ++i1)
            vOccIF[i1] = 0;
        for (int i1 = 0; i1 < numeroVerbiCOggetto; ++i1)
            vOccVCO[i1] = 0;
        for (int i1 = 0; i1 < numeroVerbiCMezzo; ++i1)
            vOccVCM[i1] = 0;
        for (int i1 = 0; i1 < numeroComplementiOggetto; ++i1)
            vOccCO[i1] = 0;
        for (int i1 = 0; i1 < numeroComplementiMezzo; ++i1)
            vOccCM[i1] = 0;
    }

    fclose(saintsM);
    fclose(saintsF);
    fclose(insultsM);
    fclose(insultsF);
    fclose(verbsCoggetto);
    fclose(verbsCMezzo);
    fclose(complementsOggetto);
    fclose(complementsMezzo);
    return 0;
}

void printRandmWordFromFile(char **vettoreStringhe, int numeroElementiNelFile, int *vettoreOccupazionale){

    srand((unsigned)time(NULL)+rand()+rand()+rand()+rand());
    int randomic = rand()%numeroElementiNelFile;

    while(vettoreOccupazionale[randomic] == 1){
        randomic++;
        if(randomic == numeroElementiNelFile)
            randomic = 1;
    }
    printf("%s ",vettoreStringhe[randomic]);
    vettoreOccupazionale[randomic] = 1;
//    fseek(file,0,0);
//    for (int i = 0; i < randomic; ++i) {
//        //fscanf(file,"%[^\n]s",extracted);
//        //fscanf(file,"%[^\n]s",extracted);
//        //fscanf(file,"%[^\n]",extracted);
//        fgets(extracted,50,file);
//        for (int j = 0; j < 50; ++j) {
//            if(extracted[j] == '\n' || extracted[j] == '\r')
//                extracted[j]='\0';
//        }
//        //printf("extracted: %s ",extracted);
//    }
//    printf("%s ",extracted);
}