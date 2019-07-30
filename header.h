#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int type;
    char valeur[25];
    char enseigne[25];
}carte;

typedef struct cellule cellule;
struct cellule
{
    carte C;
    cellule *suivant;
};
typedef struct cellule* Pile;
typedef struct cellule* liste;

Pile ajout_retour(Pile P,carte C);

void ajout_sans(Pile *P,carte C);

carte depiler(Pile *P,carte C);

void pile_to_pile(Pile *P,Pile *P1,Pile *P2,Pile *P3,Pile *P4);

liste pile_to_liste(liste L,Pile *P);

void afficher_liste(liste L);

Pile liste_to_pile(liste *L,Pile P);


#endif // HEADER_H_INCLUDED
