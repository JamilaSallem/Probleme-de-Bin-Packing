#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "LSTPRIM.h"
#include "ELTPRIM.h"
#include "Var_Globales.h"
/*************************************************/
/*Fonction First_Fit*/
void First_Fit(LISTE L,int Tab[150],int Taille)
{int i,j;
NOEUD n;
ELEMENT e1;

for(i=0;i<Taille;i++)
{
n=L->tete;
while(n!=NULL&&(n->info->Cbin)<Tab[i])//avancer tant que il existe un bin dont la capacité restante est inférieure à la taille de l'objet à insérer
{n=n->suivant;}
if(n==NULL)//si on n'a pas trouvé d'objet de capacité suffisante et qu'on est arrivé à un noeud vide de la liste Lbins, on crée un nouvel element, on lui attribut l'objet d'indice i et on l'isère à la fin de la liste
{e1=elementCreer();
 e1->Tbin[0]=Tab[i];
(e1->Nbobj)++;//on incrémente la valeur du champ correspondant au nombre des objets contenus dans le bin
(e1->Cbin)-=Tab[i];//on diminue la valeur du champ correspondant à la capacité du bin par la taille de l'objet inséré
inserer(L,e1,L->lg+1);
}

else//si on a trouvé un bin dont la capacité restante est supérieure ou égale à la taille de l'objet à insérer on commence à parcourir les cases du tableau Tbin sur lequel pointe le bin jusqu'à la première case contenant un zéro et on y insère l'objet Lobj[i] (les cases du tableau étant intialement intialisées toutes à zéro et la taille des objets toujours strictement positive, on considère une case contenant un zéro comme une case vide)
{j=0;
while(n->info->Tbin[j]!=0)
{j++;}
n->info->Tbin[j]=Tab[i];
(n->info->Nbobj)++;
(n->info->Cbin)-=Tab[i];
}
}
}
/*************************************************/
/*Fonction First_Fit_Decreasing*/
void First_Fit_Decreasing(LISTE L,int Tab[150],int Taille)
{int Lobj1[150];
 int i;
 for(i=0;i<Taille;i++)
  Lobj1[i]=Tab[i];

 Trier_Objets(Lobj1,Taille);
 First_Fit(L,Lobj1,Taille);
}
/*************************************************/
/*Fonction Best_Fit_Decreasing*/
void Best_Fit_Decreasing(LISTE L,int Tab[150],int Taille)
{int i,j,C_min;
NOEUD n,p_max;
ELEMENT e1;
int Lobj1[150]; //On a crée une copie du tableau Lobj pour pouvoir le conserver non trié dans le cas où on veut le réutiliser avec un autre algorithme de rangement

for(i=0;i<Taille;i++)
  Lobj1[i]=Tab[i];

Trier_Objets(Lobj1,Taille);

for(i=0;i<Taille;i++)
{n=L->tete;
while(n!=NULL&&(n->info->Cbin)<Tab[i])
{n=n->suivant;}

if(n==NULL)
{e1=elementCreer();
 e1->Tbin[0]=Tab[i];
(e1->Nbobj)++;
(e1->Cbin)-=Tab[i];
inserer(L,e1,L->lg+1);
}

else//dès qu'on trouve un bin de capacité suffisante, on initialise C_min avec la valeur de son champ Cbin et on pointe p_max sur cet élément de la liste Lbins puis on commence à parcourir le reste de la liste en comparant C_min avec la capacité de chaque Bin où on peut placer l'objet jusqu'à s'assurer qu'on a récupérer celui le mieux rempli
{p_max=n;
 C_min=n->info->Cbin;
while(n!=NULL)
{if((n->info->Cbin)<C_min&&(n->info->Cbin)>=Tab[i])
{C_min=n->info->Cbin;
p_max=n;
}
n=n->suivant;
}

j=0;
while(p_max->info->Tbin[j]!=0)
{j++;}
p_max->info->Tbin[j]=Tab[i];
(p_max->info->Nbobj)++;
(p_max->info->Cbin)-=Tab[i];
}
}
}
/*************************************************/
/*Fonction qui trie les objets//TRI à bulles optimisé*/
void Trier_Objets(int Tab[150],int Taille)
{int i,j,trie,aux,stop=0;
i=0;
while(i<Taille&&!stop)
    {trie=1;
     for(j=i;j<Taille;j++)
      {if (Tab[j]>Tab[i])
        {aux=Tab[i];
         Tab[i]=Tab[j];
         Tab[j]=aux;
         trie=0;
        }
      }
if(trie)
stop=1;//on arrete le tri dès qu'il y ait une itération sans échange

i++;
    }
}
/*************************************************/
/*Saisie de la capacité maximale d'un bin, du nombre d'objets à ranger et remplissage du tableau Lobj*/
void Saisir()
{int i;
Color(13,15);
printf("\n\n**********************===================SAISIE DES PARAM%cTRES===================**********************\n\n",212);
do{Color(0,15);
printf("\nDonner la capacit%c maximale d'un bin:\n",130);
scanf("%i",&C);
}while(C<=0||C>=100||(int)C!=C);

do{Color(0,15);
printf("\nDonner le nombre des objets %c r%cpartir:\n",133,130);
scanf("%i",&T);
}while(T<=0||T>150||(int)T!=T);

for(i=0;i<T;i++)
do
{Color(0,15);
 printf("\nDonner la taille de l'objet N%c %i:\n",248,i+1);
 scanf("%i",&Lobj[i]);}
while(Lobj[i]>C||Lobj[i]<1||(int)Lobj[i]!=Lobj[i]);
Color(13,15);
printf("\n\n**********************==========================================================**********************\n\n");
}
/*************************************************/
void Menu_Principal()
{int choix;
Color(12,15);
printf("\n\n**********************===================MENU PRINCIPAL===================**********************\n\n");
do
{Color(0,15);
printf("\n%ctes-vous int%cress%cs par le probl%cme du Bin Packing?!\nSi oui, vous pouvez d%ccouvrir quelques algorithmes d'application en cliquant sur 1\nSi vous voulez quitter, appuyez sur 2:\n",210,130,130,138,130);
scanf("%i",&choix);
}while((int)choix!=choix);//si le cast (int)de choix est différent de choix alors l'utilisateur n'a pas saisi un entier
Color(12,15);
printf("\n\n**********************====================================================**********************\n\n");
if(choix==1)
{Saisir();
 Menu_2();
}
else if(choix==2)
{system("start merci.gif");exit(0);}
else
{Color(4,15);
printf("\nVeuillez v%crifier votre choix!\n",130);
Menu_Principal();
}
}
/*************************************************/
void Menu_1()
{int choix;
Color(5,15);
printf("\n\n**********************===================VOUS VOULEZ CONTINUER?!===================**********************\n\n");
do
{Color(0,15);
printf("Si vous voulez recommencer avec de nouveaux objets, cliquez sur 1\nSi vous voulez maintenir les objets existants et essayer un nouvel algorithme de rangement, cliquez sur 2\nSinon, si vous voulez quitter, cliquez sur 3:\n");
scanf("%i",&choix);
}while((int)choix!=choix);
Color(5,15);
printf("\n\n**********************=============================================================**********************\n\n");
if(choix==1)
{system("cls");//effacer l'écran
 Saisir();
 Menu_2();
}
else if(choix==2)
{Menu_2();}
else if(choix==3)
{system("start merci.gif");exit(0);}
else
{Color(4,15);
 printf("Choix invalide! Veuillez r%cessayer",130);
 Menu_1();
}
}
/*************************************************/
void Menu_2()
{int choix;
 LISTE Lbins=listeCreer();
 Color(3,15);
 printf("\n\n**********************===================MENU DE CHOIX D'ALGORITHME===================**********************\n\n");
 do
{Color(0,15);
printf("Si vous voulez choisir l'Algorithme First_Fit, appuyez sur 1\nSi vous voulez choisir l'Algorithme First_Fit_Decreasing, appuyez sur 2\nSi vous voulez choisir l'Algorithme Best_Fit_Decreasing cliquez sur 3\nSinon, si vous voulez quitter cliquez sur 4:\n");
scanf("%i",&choix);
}while((int)choix!=choix);
Color(3,15);
 printf("\n\n**********************===============================================================**********************\n\n");
if(choix==1)
{First_Fit(Lbins,Lobj,T);
 listeAfficher(Lbins);
 Menu_1();}
else if(choix ==2)
{First_Fit_Decreasing(Lbins,Lobj,T);
 listeAfficher(Lbins);
 Menu_1();}
else if(choix==3)
{Best_Fit_Decreasing(Lbins,Lobj,T);
 listeAfficher(Lbins);
 Menu_1();}
else if(choix==4)
{listeDetruire(Lbins);
 system("start merci.gif");exit(0);}
else
{Color(4,15);
 printf("Veuillez v%crifier votre choix :\n",130);
 Menu_2();
}
}
/*************************************************/
void Color(int couleurDuTexte,int couleurDeFond) //Une fonction de la bibliothèque <windows.h> qui affiche un texte colorié
{HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/*************************************************/



//******************************************MAIN***************************************//
int main()
{system("color F0");//colorier le fond de la fenetre d'éxecution en blanc brillant
Color(11,3);

printf("\n  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  ");
printf("\n  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  ");
printf("\n  °°                                                                                                °°  ");
printf("\n  °°                                    Probl%cme De Bin Packing                                     °°  ",138);
printf("\n  °°                                                                                                °°  ");
printf("\n  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  ");
printf("\n  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  ");

Menu_Principal();

return 0;
}
//*************************************************************************************//
