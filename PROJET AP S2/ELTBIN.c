#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ELTPRIM.h"
#include "Var_Globales.h"
/*************************************************/
ELEMENT elementCreer ()
{ELEMENT e;
 int i;
e=(ELEMENT)malloc(sizeof(BIN));
for(i=0;i<T;i++)//initialiser toutes les cases du tableau � 0
e->Tbin[i]=0;

e->Cbin=C;//La capacit� de chaque �l�ment cr�e est initialis� avec la valeur saisie par l'utilsateur dans le programme principal
e->Nbobj=0;//le nombre d'objets contenus dans  le Bin est initialement nul

return e;
}
/*************************************************/
void elementDetruire(ELEMENT e)
{free (e);}
/*************************************************/
void elementLire (ELEMENT *e)
{
//La saisie de l'�l�ment se fait dans le programme principal
}
/*************************************************/
void elementAfficher (ELEMENT e,int k)
{int i,test=0;
 i=0;
while(i<e->Nbobj&&!test)
    {if(e->Tbin[i]/10>=1)
      test=1;
      i++;}
for(i=e->Nbobj-1;i>=0;i--)
{
{k++;
if(k>=15)
k=1;}//incr�menter k pour que chaque case du Bin soit affich�e avec une couleur diff�rente//k doit s'arreter � 15 parceque il y a en totalit� 16 couleurs dont les codes varient de 0 � 15

if(!test)//tester si la taille de l'objet est d'un seul chiffre ou de deux pour pouvoir perfectionner l'affichage du Bin
{Color(0,k);
 printf("| %i |\n",e->Tbin[i]);
 printf("|___|\n");
}
else
{if(e->Tbin[i]>=10)
{Color(0,k);
printf("| %i |\n",e->Tbin[i]);
}
else
{Color(0,k);
 printf("|  %i |\n",e->Tbin[i]);
}
Color(0,k);
printf("|____|\n");
}
}
}
/*************************************************/
void elementCopier(ELEMENT* e1, ELEMENT e2)
{int i;//�tant donn� que tous les Bins admettent la meme taille maximale du tableau Tbin ainsi que la meme capacite Cbin, pour copier un �l�ment on n'aura qu'� copier le nombre des objets Nbobj et les cases du tableau Tbin
(*e1)->Nbobj=e2->Nbobj;
for(i=0;i<e2->Nbobj;i++)
(*e1)->Tbin[i]=e2->Tbin[i];
}
/*************************************************/
void elementAffecter (ELEMENT *e1,ELEMENT e2)
{*e1=e2;
}
/*************************************************/
int elementComparer (ELEMENT e1,ELEMENT e2)
{int i=0,test=1;
if(e1->Nbobj!=e2->Nbobj)//on compare d'abord les tailles, si elles sont �gales on passe � la comparaison objet par objet
    test=0;
else
{while(i<e1->Nbobj&&test)
    {if(e1->Tbin[i]!=e2->Tbin[i])
      test=0;}
}

return test;
}

