/*
 CONTENU      : TP 6 -  Evaluation des files
 AUTEUR       : Emmmanuel Morin
 CREATION     : 11/12/2018
 MODIFICATION : 11/12/2018
 */

// librairies
#include <stdio.h>
#include <stdlib.h>
#include "file_cartes.h"
#include <time.h>

// corps du programme principal
int main()
{
    //  vecteur inital pour stocker le jeu de cartes
    t_carte t[32];
    // initialisation du vecteur avec le jeu de cartes
    srand(time(NULL));
    int indice = 0;
    for (t_valeur i = SEPT; i <= AS; i++)
    {
        for (t_couleur j = coeur; j <= trefle; j++)
        {
            t_carte carte;
            carte.valeur = i;
            carte.couleur = j;
            t[indice] = carte;
            indice++;
        }
    }
    
    // petit mélange du jeu de cartes
    int indice1, indice2;
    t_carte tmp;
    for (int i = 0; i <= 20; i++)
    {
        indice1 = rand() % (NbrCartes);
        indice2 = rand() % (NbrCartes);
        tmp = t[indice1];
        t[indice1] = t[indice2];
        t[indice2] = tmp;
    }
    t_file fileJ1 = init_file();
    t_file fileJ2 = init_file();
    t_file bataille = init_file();
    for (int i = 0; i < 32; i += 2)
    {
        //printf("%d, %d\n", t[i].valeur, t[i + 1].valeur);
        ajouter(&fileJ1, t[i]);
        ajouter(&fileJ2, t[i + 1]);
    }
    while (!file_vide(fileJ1) && !file_vide(fileJ2))
    {
        t_carte carteJ1;
        t_carte carteJ2;
        //printf("%d, %d\n", fileJ1.nb_elements, fileJ2.nb_elements);
        retirer(&fileJ1, &carteJ1);
        retirer(&fileJ2, &carteJ2);
        printf("Le joueur 1 tire la carte: %d\nLe joueur 2 tire la carte: %d\n", carteJ1.valeur, carteJ2.valeur);
        if (carteJ1.valeur < carteJ2.valeur) // Le joueur 2 est gagnant
        {
            printf("Le joueur 2 l'emporte\n");
            ajouter(&fileJ2, carteJ2);
            ajouter(&fileJ2, carteJ1);
            if (!file_vide(bataille))
            {
                printf("J2 emporte la bataille\n");
                while (!file_vide(bataille))
                {
                    retirer(&bataille, &carteJ1);
                    ajouter(&fileJ2, carteJ1);
                }
            }
        }
        else if (carteJ1.valeur > carteJ2.valeur) // Le joueur 1 est gagnant
        {
            printf("Le joueur 1 l'emporte\n");
            ajouter(&fileJ1, carteJ1);
            ajouter(&fileJ1, carteJ2);
            if (!file_vide(bataille))
            {
                printf("J1 emporte la bataille\n");
                while (!file_vide(bataille))
                {
                    retirer(&bataille, &carteJ1);
                    ajouter(&fileJ1, carteJ1);
                }
            }
        }
        else // Bataille
        {
            if (file_vide(bataille))
                printf("Il y a bataille\n");
            else
                printf("Les cartes sont encore les même, on continue la bataille\n");
            if (rand() % 2)
            {
                ajouter(&bataille, carteJ1);
                ajouter(&bataille, carteJ2);
            }
            else
            {
                ajouter(&bataille, carteJ1);
                ajouter(&bataille, carteJ2);
            }
        }
    }
    if (fileJ1.nb_elements > fileJ2.nb_elements)
    {
        printf("Le joueur 1 est gagnant\n");
    }
    else if (fileJ1.nb_elements < fileJ2.nb_elements)
    {
        printf("Le joueur 2 est gagnant\n");
    }
    else
    {
        printf("Egalité\n");
    }
}