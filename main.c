#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    Pile P=NULL;
    Pile P1=NULL,P2=NULL,P3=NULL,P4=NULL;
    liste L=NULL;
    carte C;
    int choix;
    do
    {
        printf("--------MENU--------\n");
        printf("1-Ajouter carte avec type de retour \n");
        printf("2-Ajouter carte sans type de retour \n");
        printf("3-Retirer une carte de la pile \n");
        printf("4-Obtenir 4 Piles selon les enseignes \n");
        printf("5-Ajouter elements pile a une liste chainee \n");
        printf("6-Afficher liste carte \n");
        printf("7-Empiler les cartes d'une liste dans une pile\n");
        printf("8-Obtenir une pile en ordre selon l'enseigne et la valeur \n");
        printf("0-Quitter \n");
        printf("Veuillez entrer votre choix \n");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 :
            P=ajout_retour(P,C);
            printf("\n");
            break;
        case 2 :
            ajout_sans(&P,C);
            printf("\n");
            break;
        case 3 :
            C=depiler(&P,C);
            printf("\n");
            break;
        case 4 :
            pile_to_pile(&P,&P1,&P2,&P3,&P4);
            printf("\n");
            break;
        case 5 :
            L=pile_to_liste(L,&P);
            printf("\n");
            break;
        case 6 :
            afficher_liste(L);
            printf("\n");
            break;
        case 7 :
            P=liste_to_pile(&L,P);
            printf("\n");
            break;
        }

    }while(choix!=0);

    return 0;
}
