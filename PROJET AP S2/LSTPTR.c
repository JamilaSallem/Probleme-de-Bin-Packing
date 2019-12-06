#include <stdio.h>
#include <stdlib.h>
#include "LSTPRIM.h"
#include "ELTPRIM.h"
#include "Var_Globales.h"
/*************************************************/
NOEUD noeudCreer(ELEMENT e)
{NOEUD n=(NOEUD)malloc(sizeof(structNoeud));
if(!n)
printf("Pas d'espace m%cmoire!",130);
else
{elementAffecter(&n->info,e);
n->suivant=NULL;
}
return n;
}
/*************************************************/
void noeudDetruire(NOEUD n)
{elementDetruire(n->info);
free(n);
}
/*************************************************/
LISTE listeCreer()
{LISTE L;
L=(LISTE)malloc(sizeof(Lbins));
if(!L)
printf("Pas de m%cmoire!",130);
else
{L->lg=0;
 L->tete=NULL;
}
return L;
}
/*************************************************/
void listeDetruire(LISTE L)
{int i;
NOEUD p,q;
q=L->tete;
for(i=1;i<=L->lg;i++)
{p=q;
q=q->suivant;
noeudDetruire(p);
}
free(L);
}
/*************************************************/
int estSaturee(LISTE L)
{NOEUD temp;
int saturee=1;
temp=(NOEUD)malloc(sizeof(structNoeud));
if(temp!=NULL){
saturee=0;
free(temp);
}
return saturee;
}
/*************************************************/
int estVide(LISTE L)
{return (L->lg==0);
}
/*************************************************/
int listeTaille(LISTE L)
{return (L->lg);
}
/*************************************************/
int inserer(LISTE L,ELEMENT e,int pos)
{int succee=1;
int i;
NOEUD n,p,q;
if(estSaturee(L))//tester si la liste est saturée
{printf("\nLa liste est satur%ce.",130);
 succee=0;
}
else
{if(pos<1||pos>L->lg+1)//tester si la position d'insertion est invalide
{printf("\nLa position est invalide.");
succee=0;
}
 else//si il y a encore de l'espace mémoire et que la position est valide on procède à verifier l'emplacement de l'insertion par rapport à la structure LISTE
{n=noeudCreer(e);//on crée un noeud contenant l'élément e à insérer

//si l'insertion est en tete de liste
if(pos==1)
{n->suivant=L->tete;
L->tete=n;
}
else//si l'insertion dans la liste/pas dans la tete/ (cas général)
{q=L->tete;
for(i=1;i<pos;i++)
{p=q;//le noeud p conserve la position précédente de q
 q=q->suivant;
}
p->suivant=n;
n->suivant=q;
}
(L->lg)++;//on incrémente la taille de la liste
}
}
return succee;}
/*************************************************/
int supprimer(LISTE L,int pos)
{int i;
int succee=1;
NOEUD p,q;

if(estVide(L))
{printf("\nLa liste est vide.");//on vérifie que la liste n'est pas vide
succee=0;
}
else if(pos<1||pos>L->lg)//on vérifie que la position est valide
{printf("\nLa position est invalide.");
succee=0;
}
else
{q=L->tete;//suppression en tete de liste
if(pos==1)
    L->tete=L->tete->suivant;
else//suppression dans la liste (cas général)
    {for(i=1;i<pos;i++)
     {p=q;
      q=q->suivant;}
p->suivant=q->suivant;//le champ suivant du noeud p qui conserve la position précédente de q va pointer sur le noeud suivant de q pour conserver le chainage de la liste suite à la suppression de q
}
noeudDetruire(q);
(L->lg)--;//on décrémente la taille de la liste
}
return succee;
}
/*************************************************/
ELEMENT recuperer(LISTE L,int pos)
{NOEUD p;
ELEMENT e=elementCreer();
int i;
if(estVide(L))//pour pouvoir récupérer un élément il faut que la liste ne soit pas vide et que a position à partir de laquelle on va récupérer soit valide(comprise entre 1 et L->lg)
    printf("La liste est vide!");
else if(pos<1||pos>L->lg)
    printf("La position est invalide!");
else
{
p=L->tete;
for(i=1;i<=pos;i++)
p=p->suivant;
elementAffecter(&e,p->info);
}
return e;
}
/*************************************************/
void listeAfficher(LISTE L)
{int i,k=0;//On a déclaré k ici parcequ'il faut qu'lle soit incréménté en passant d'un Bin à un autre sinon ils seront tous de meme couleurs; c.à.d tous les bins auront par e.g le premier objet de couleur bleue, le deuxième rouge, .. et ainsi de suite
NOEUD p;
p=L->tete;
for(i=1;i<=listeTaille(L);i++)
{printf("\n\n");
elementAfficher(p->info,k);
Color(0,15);
printf("BIN %i\n", i);
p=p->suivant;

k+=4;
}
}
/*************************************************/
LISTE listeCopier(LISTE L)
{LISTE LR=listeCreer();
int i;
ELEMENT elt;
for(i=0;i<=L->lg;i++)
{elt=elementCreer();
elementCopier(&elt,recuperer(L,i));
inserer(L,elt,i);
}
return LR;
}
/*************************************************/
int listeComparer(LISTE L1,LISTE L2)
{int i=1,test=1;
if (listeTaille(L1)!=listeTaille(L2))//on compare d'abord les tailles des deux listes
    test=0;
else
    while(i<listeTaille(L1)&&test)//on arrete le parcours dès qu'on trouve deux éléménts différents à la meme position
{if(elementComparer(recuperer(L1,i),recuperer(L2,i))!=0)
test=0;
i++;
}
return test;
}
