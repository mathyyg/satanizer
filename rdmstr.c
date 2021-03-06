#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv)
{
    srand((unsigned int)(time(NULL)));
    int i;
    char pass[12];
    int j;

    FILE *ft;
    ft = fopen("generation.txt","w+");

    for (j = 0; j < 20 ; j++) {
        for (i = 0; i < 4; i++) {
            pass[i] = rand() % 9;
            char capLetter = 'A' + (rand() % 26);
            pass[i + 2] = capLetter;
            char letter = 'a' + (rand() % 26);
            pass[i + 3] = letter;
            fprintf(ft,"%d%c%c", pass[i], pass[i + 2], pass[i + 3]);
        }
	fprintf(ft,"\n");
    }
    printf("Random strings generated\n");
}