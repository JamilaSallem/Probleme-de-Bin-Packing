#ifndef _ELTPRIM_H
#define _ELTPRIM_H
#include "ELTSDD.h"

ELEMENT elementCreer (void);
void elementDetruire(ELEMENT);
void elementLire (ELEMENT *);
void elementAfficher (ELEMENT,int);//On a ajouté un autre paramètre à la primitive elementAfficher pour controler les couleurs des objets lors de l'affichage
void elementCopier(ELEMENT*, ELEMENT);
void elementAffecter (ELEMENT*,ELEMENT);
int elementComparer (ELEMENT,ELEMENT);

#endif
