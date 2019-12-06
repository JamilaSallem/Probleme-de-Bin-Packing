#ifndef _LSTPTR_H
#define _LSTPTR_H
#include "ELTPRIM.h"

typedef struct structNoeud{
struct structNoeud* suivant;
ELEMENT info;
}structNoeud,*NOEUD;

typedef struct{
NOEUD tete;
int lg;
}Lbins,*LISTE;


#endif
