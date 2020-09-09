#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NB_STRINGS 20

void main () {
    
    int i = 0;
    int j = 0;
    char line1[13];
    char rdm[NB_STRINGS][13];

    const char * file1 = "generation.txt"; //fichier à ouvrir
    //const char * file2 = "verifgen"; //verif
    //const char * file3 = "verifgen2"; //verif

    FILE * stream1 = fopen(file1,"r");
    //FILE * verif1 = fopen(file2,"w"); // verif1
    //FILE * verif2 = fopen(file3,"w"); // verif2
    if (stream1 == NULL) { //vérification nom du fichier
        printf("Impossible d'ouvrir le fichier\n");
    }
    while(fgets(line1,13,stream1) != NULL) {
            i++;
        }
    
    rewind(stream1);

    for(j=0;j<i && j<NB_STRINGS;j++) {
        fgets(line1,13,stream1);
        strcpy(rdm[i], line1);
        printf("%s\n",line1);
        //fprintf(verif1,"%s\n",line1);
        //fprintf(verif2,"%s\n",rdm[i]);
    }

    fclose(stream1); // fermeture flux fichier 1
    

    /*const char * file2 = "common"; //fichier à ouvrir

    FILE * stream2 = fopen(file2,"r");
    if (stream2 == NULL) {
        printf("Impossible d'ouvrir le fichier");
    } */
}