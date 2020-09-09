#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sed_replace(char* searched,char* replaced) {
    char * command = ("sed -i -e 's/"+searched+"/"+replaced+"/g' debut_jeu.c");


}

int main(int argc,char *argv[]){
    /* Lecture de la génération et récupération */

    FILE * fichier = fopen("generation.txt","r");
    char * ligne = NULL;
    size_t taille = 0;
    ssize_t lecture;
    char rdms[20][13];

    if(fichier==NULL){
        printf("Fichier introuvable");
    }
    int i=0;
    int verif=0;
    while((lecture=getline(&ligne,&taille,fichier)) !=-1) {
        strcpy(rdms[i],ligne);
        if(strcmp(rdms[i],ligne)==0){
            verif++;
        }
        i++;
        printf("Ligne n°%d: %s\n",i,ligne);
    }
    if(verif==20){
        printf("Toutes les lignes ont bien été récupérées\n");
    }
    else{
        printf("Erreur de lecture");
    }
    fclose(fichier);
    if(ligne){
        free(ligne);
        printf("Fin de la lecture\n");
    }

    /* Lecture des mots les plus communs et récupération */

    FILE * fichier2 = fopen("words.txt","r");
    char * ligne2 = NULL;
    size_t taille2 = 0;
    ssize_t lecture2;
    char commons[20][atoi(argv[1])];

    if(fichier2==NULL){
        printf("Fichier introuvable");
    }
    int j=0;
    int verif2=0;
    while((lecture2=getline(&ligne2,&taille2,fichier2)) !=-1) {
        strcpy(commons[i],ligne2);
        if(strcmp(commons[i],ligne2)==0){
            verif2++;
        }
        j++;
        printf("Ligne n°%d: %s\n",j,ligne2);
    }
    if(verif2==20){
        printf("Toutes les lignes ont bien été récupérées\n");
    }
    else{
        printf("Erreur de lecture");
    }
    fclose(fichier2);
    if(ligne2){
        //free(ligne2);
        printf("Fin de la lecture\n");
    }
}