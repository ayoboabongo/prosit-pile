#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


carte saisir_carte(carte C)
{
    do
    {
        printf("Type \n");
        printf("1-valeur \n");
        printf("2-Enseigne \n");
        scanf("%d",&C.type);
    }while((C.type!=1)||(C.type!=2));
    switch(C.type)
    {
    case 1 :
        printf("Valeur :(1,2,3,4,5,6,7,8,9,10, Valet, Dame, Roi)\n");
        scanf("%s",C.valeur);
        break;
    case 2 :
        printf("Enseigne : (pique,coeur, carreau et trèfle)\n");
        scanf("%s",C.enseigne);
        break;
    }

    return C;
}

Pile ajout_retour(Pile P,carte C)
{
    Pile nouv;
    nouv=malloc(sizeof(struct cellule));
    if(nouv==NULL)
        printf("allocation de la memoire non effectuee \n");

    else
    {
        C=saisir_carte(C);
        nouv->C=C;
        nouv->suivant=P;

        P=nouv;
    }

    return P;
}

void ajout_sans(Pile *P,carte C)
{
    Pile nouv;
    nouv=malloc(sizeof(struct cellule));
    if(nouv==NULL)
        printf("allocation de la memoire non effectuee \n");

    else
    {
        C=saisir_carte(C);
        nouv->C=C;
        nouv->suivant=*P;

        *P=nouv;
    }

    return P;

}

carte depiler(Pile *P,carte C)
{
    Pile tmp=*P;
    if(P==NULL)
        printf("Rien a depiler pile vide \n");

    else
    {
        *P=(*P)->suivant;
        C=(*P)->C;
        free(tmp);
    }

    return C;
}

void pile_to_pile(Pile *P,Pile *P1,Pile *P2,Pile *P3,Pile *P4)
{
    carte C;
    while(*P!=NULL)
    {
        if((*P)->C.type==2)
        {
             C=depiler(P,C);

            if(strcmp(C.enseigne,"pique")==0)
                *P1=ajout_retour(P1,C);

            if(strcmp(C.enseigne,"coeur")==0)
                *P2=ajout_retour(P2,C);

            if(strcmp(C.enseigne,"carreau")==0)
                *P3=ajout_retour(P3,C);

            if(strcmp(C.enseigne,"trefle")==0)
                *P4=ajout_retour(P4,C);

        }
    }

}

liste pile_to_liste(liste L,Pile *P)
{
    carte C;
    while(*P!=NULL)
    {
        if((*P)->C.type==1)
        {
            C=depiler(P,C);
            L=ajout_retour(L,C);
        }
    }

    return L;
}

void afficher_liste(liste L)
{
    liste tmp=L;
    while(tmp!=NULL)
    {
        if(tmp->C.type==1)
            printf("Valeur : %s",tmp->C.valeur);
        printf("\n");

        if(tmp->C.type==2)
            printf("Enseigne : %s",tmp->C.enseigne);
        printf("\n");

        tmp=tmp->suivant;
    }
}

Pile liste_to_pile(liste *L,Pile P)
{
    liste tmp=*L;
    while(tmp!=NULL)
    {
        P=ajout_retour(P,tmp->C);
        tmp=tmp->suivant;
    }

    return P;
}
