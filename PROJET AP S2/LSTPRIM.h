#ifndef _LSTRPIM_H
#define _LSTRPIM_H
#include "LSTSDD.h"
#include "ELTPRIM.h"

NOEUD noeudCreer(ELEMENT);
void noeudDetruire(NOEUD);

LISTE listeCreer();
void listeDetruire(LISTE);
int estSaturee(LISTE);
int estVide(LISTE);
int listeTaille(LISTE);
int inserer(LISTE,ELEMENT,int);
int supprimer(LISTE,int);
ELEMENT recuperer(LISTE,int);
void listeAfficher(LISTE);
LISTE listeCopier(LISTE);
int listeComparer(LISTE,LISTE);


#endif
