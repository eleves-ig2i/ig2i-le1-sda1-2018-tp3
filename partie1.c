/***************************************************************************************/
/* NOM : partie1.c								       */
/* DESCRIPTION : Exécution de multiples sous programmes d'affichage, de saisie et de   */
/* 		 calcul (puissance et factorielle)				       */
/* AUTEUR : Nathan SALEZ							       */
/* DATE DE LA DERNIERE MODIFICATION :	15/01/18				       */
/* VERSION : 1.3								       */
/***************************************************************************************/

#include <stdio.h>



/*******************************Déclaration des fonctions*******************************/
int saisirunevaleurV1();		
void saisirunevaleurV2(int *);
void afficherunevaleur(int );
int puissance1(int , int );
void puissance2(int , int , int *); 
int fact(int );
void fact2(int , int *);
int menu();
/*************************************************************************************/
/*************************************************************************************/

/********************************Programme principal**********************************/	





int main()
{
int val1,val2,c,choix;

do	{
choix=menu();
switch (choix)	{

case 1 : val1=saisirunevaleurV1();
	 break;

case 2 : saisirunevaleurV2(&val2);
	 break;

case 3 : afficherunevaleur(val1);
	 afficherunevaleur(val2);
	 break;

case 4 : printf("\n\n\t\t\t val1 va etre affiché");
	 c=puissance1(val1,val2);
	 afficherunevaleur(c);
	 break;

case 5 : printf("\n\n val2 va etre affiché");
	 puissance2(val1,val2,&val2);
	 afficherunevaleur(val2); 
	 break;
	
case 6 : c=fact(val1);
	 afficherunevaleur(c);
	 break;
	
case 7 : fact2(val2,&val2);
	 afficherunevaleur(val2); 
	 break;

case 9 : break;
		
default : printf("\n\n OPTION NON PREVUE \n\n"); 
	}
}
while(choix!=9);
	 

return 0;
} 





// Exercice 1 - Sous programme 1
/***************************************************************************************/
/*Nom de la fonction : saisirunevaleurV1					       */
/*Description : permet de saisir un entier.					       */
/*Retourne : c (valeur saisie)							       */
/*Effets de bord : saisie au clavier						       */
/*Paramètres en entrée : rien							       */
/*Paramètres en sortie : c (qui devient val1 dans le programme principal)	       */
/***************************************************************************************/
int saisirunevaleurV1() 		
{
int c;
printf("\n\n\Entrez l'entier que vous voulez saisir.\n\n");
scanf("%d",&c);
return c;
}	



// Exercice 1 - Sous programme 2
/***************************************************************************************/
/*Nom de la fonction : saisirunevaleurV2					       */
/*Description : permet de saisir un entier.					       */
/*Retourne : rien								       */
/*Effets de bord : saisie au clavier						       */
/*Paramètres en entrée : pointeur de adV					       */
/*Paramètres en sortie : rien							       */
/***************************************************************************************/
void saisirunevaleurV2(int *adV) 	// adV devient une adresse !
{	
printf("\n\n\Entrez l'entier (ex2:puissance) que vous voulez saisir.\n\n");
scanf("%d",adV); 	// adV est une adresse !
}




//Réponse à la question 2 :
/*L'avantage du 1er programme est illustrée selon l'exemple suivant :
printf("%d",saisirunevaleurV1());  	<====>   c=saisirunevaleurV1();
						 printf("%d",c);  
A l'aide de cette version, on peut réduire le nombre de lignes utilisés mais l'appel à une fonction prend du temps.

Le 2e programme (qui fonctionne comme scanf) est utle si on doit utiliser la variable adV plusieurs fois, on gagne du temps mais ça prend plus de places.*/





// Exercice 1 - Sous programme 3
/***************************************************************************************/
/*Nom de la fonction : afficherunevaleur					       */
/*Description : permet d'afficher un entier.					       */
/*Retourne : rien								       */
/*Effets de bord : affichage à l'écran						       */
/*Paramètres en entrée : V							       */
/*Paramètres en sortie : rien							       */
/***************************************************************************************/
void afficherunevaleur(int V)
{
printf("\n\nL'entier à afficher est %d.\n\n\n",V);
}	



// Exercice 2 - Sous programme 1
/***************************************************************************************/
/*Nom de la fonction : puissance1						       */
/*Description : calcul de a^b avec b strictement positif			       */
/*Retourne : a									       */
/*Effets de bord : affichage à l'écran si b non strictement positif		       */
/*Paramètres en entrée : a et b							       */
/*Paramètres en sortie : a						               */
/***************************************************************************************/
int puissance1(int a, int b)
{
int V,i;
if (b<=0) {
	printf("\n\nb doit etre strictement positif");
	return 0;
	}
else {
	V=a;
	for(i=0;i<b-1;i++) {
		a=a*V;
		}
	return a;
	}
}



// Exercice 2 - Sous programme 2
/***************************************************************************************/
/*Nom de la fonction : puissance2						       */
/*Description : calcul de a^b avec b strictement positif			       */
/*Retourne : c (==a^b)								       */
/*Effets de bord : affichage à l'écran si b non strictement positif 		       */
/*Paramètres en entrée : a et b			                              	       */
/*Paramètres en sortie : rien							       */
/***************************************************************************************/
void puissance2(int a, int b, int *c)
{
int V,i;
if (b<=0) {
	printf("\n\nb doit etre strictement positif");
	}
else {
	V=a;
	for(i=0;i<b-1;i++) {
		a=a*V;
		}
	*c=a;
	}
}



// Exercice 3 - Sous programme 1
/***************************************************************************************/
/*Nom de la fonction : fact							       */
/*Description : calcul de la factorielle d'un entier strictement positif               */
/*Retourne : n si entier strictement positif, 0 sinon				       */
/*Effets de bord : affichage à l'écran si n non strictement positif		       */
/*Paramètres en entrée : n							       */
/*Paramètres en sortie : n ou 0 (cf Retourne)					       */
/***************************************************************************************/
int fact(int n)
{
int V,i;
if(n>=0) {
	V=n-1;
	for(i=V;i>1;i--) {
		n*=i;				// n*=i <=> n=n*i
		}				
	return n;
	}
else {
	printf("\n\nn doit être strictement positif");
	return 0;
	}
}
	


// Exercice 3 - Sous programme 2 :
/***************************************************************************************/
/*Nom de la fonction : fact2							       */
/*Description : calcul de la factorielle d'un entier strictement positif	       */
/*Retourne : rien								       */
/*Effets de bord : affichage à l'écran si n non strictement positif		       */
/*Paramètres en entrée : n et pointeur de c					       */
/*Paramètres en sortie : rien							       */
/***************************************************************************************/
void fact2(int n, int *c)
{
int V,i;
if (n>=0) {
	V=n-1;
	for(i=V;i>1;i--) {
		n*=i;
		}	
	*c=n;
	}
else {
	printf("\n\nn doit être strictement positif");
	}
}



// Annexe
/***************************************************************************************/
/*Nom de la fonction : menu							       */
/*Description : affiche le menu des programmes  et sélection d'un programme 	       */
/*Retourne : choix								       */
/*Effets de bord : affichage à l'écran et saisie au clavier			       */
/*Paramètres en entrée : rien							       */
/*Paramètres en sortie : choix							       */
int menu()	
{
  int choix;
  printf("\n\t\t\t\t 1 - Saisir Valeur1");  
  printf("\n\t\t\t\t 2 - Saisir Valeur2");
  printf("\n\t\t\t\t 3 - Afficher Valeur ");
  printf("\n\t\t\t\t 4 - Puissance 1");
  printf("\n\t\t\t\t 5 - Puissance 2 ");
  printf("\n\t\t\t\t 6 - Factoriel 1");
  printf("\n\t\t\t\t 7 - Factoriel 2");
  printf("\n\t\t\t\t 9 - Quitter");
  
 printf("\n\n\t\t\t\t Votre choix : "); 
 fflush(stdin);
 scanf("%d",&choix);
 getchar(); // supression du retour chariot
 return choix;
}
		



	




