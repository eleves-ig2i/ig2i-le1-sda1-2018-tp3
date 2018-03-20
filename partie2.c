/***********************************************************************************************/
/*NOM DU PROGRAMME : TP3_PARTIEII							       */
/*DESCRIPTION : Saisie d'un carré de dimension 9*9 maximum, et vérification s'il est magique   */
/*AUTEUR : Nathan SALEZ									       */
/*DATE DE DERNIERE MODIFICATION : 15/01/18						       */
/*VERSION : 1.4 									       */
/***********************************************************************************************/
#include <stdio.h>
#define MAXELT 10	

/***************************Déclaration des sous programmes*************************************/


void saisircarre(int T[MAXELT+1][MAXELT+1],int t);
/***********************************************************************************************/
/*Nom de la fonction : saisircarre							       */
/*Description : saisir un tableau de dimensions t*t    					       */
/*Retourne : rien									       */
/*Effets de bord : scanf								       */
/*Paramètres en entrée : T (tableau[MAXELT+1][MAXELT+1]), t (taille du tableau) 	       */
/*Paramètres en sortie : T (tableau[MAXELT+1][MAXELT+1])				       */
/***********************************************************************************************/



void affichercarre(int T[MAXELT+1][MAXELT+1],int t);
/***********************************************************************************************/
/*Nom de la fonction : affichercarre    				                       */
/*Description : afficher un tableau de dimensions t*t    		                       */
/*Retourne : rien 								               */
/*Effets de bord : printf 						                       */
/*Paramètres en entrée : T (tableau[MAXELT+1][MAXELT+1]), t (taille du carré)        	       */
/*Paramètres en sortie : rien			 				               */
/***********************************************************************************************/



int sumligne(int T[MAXELT+1][MAXELT+1],int t, int l);
/***********************************************************************************************/
/*Nom de la fonction : sumligne                                                                */
/*Description : Sommer les cases de la ligne l du carré (dimensions t*t)                       */
/*Retourne : somme									       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : T (tableau[MAXELT+1][MAXELT+1]),t (taille..),l(ligne du tableau)      */
/*Paramètres en sortie : somme								       */
/***********************************************************************************************/



int sumcolonne(int T[MAXELT+1][MAXELT+1],int t, int c);
/***********************************************************************************************/
/*Nom de la fonction : sumcolonne                                                              */
/*Description : Sommer les cases de la colonne c du carré (dimensions t*t)                     */
/*Retourne : somme									       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : T (tableau[MAXELT+1][MAXELT+1]),t (taille..),c (colonne du tableau)   */
/*Paramètres en sortie : somme								       */
/***********************************************************************************************/



int sumdiag1(int T[MAXELT+1][MAXELT+1], int t);
/***********************************************************************************************/
/*Nom de la fonction : sumdiag1								       */
/*Description : sommer les cases de la diagonale du carré du tableau T                         */
/*Retourne : somme									       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : T (tableau[MAXELT+1][MAXELT+1]),t (taille..)			       */
/*Paramètres en sortie : somme								       */
/***********************************************************************************************/



int sumdiag2(int T[MAXELT+1][MAXELT+1], int t);
/***********************************************************************************************/
/*Nom de la fonction : sumdiag2								       */
/*Description : sommer les cases de la diagonale opposée du carré du tableau T		       */
/*Retourne : somme									       */
/*Effets de bord : aucun								       */
/*Paramètres en entrée : T (tableau[MAXELT+1][MAXELT+1]),t (taille..)			       */
/*Paramètres en sortie : somme								       */
/***********************************************************************************************/






/******************************Programme principal**********************************************/
int main()
{	
int Tableau[MAXELT+1][MAXELT+1],taille,ligne,colonne,pasmagique;

do {
	printf("\n\nSaisir la taille:\t");
	scanf("%d",&taille);
 	}
	while((taille<0)||(taille>MAXELT-1)); 		
		saisircarre(Tableau,taille);		// Sous programme 1
		affichercarre(Tableau,taille);		// Sous programme 2

	for(ligne=1;ligne<=taille;ligne++) {
		Tableau[ligne][taille]=sumligne(Tableau, taille, ligne); // Sous programme 3
	}
	for(colonne=0;colonne<taille;colonne++)	{
		Tableau[taille+1][colonne]=sumcolonne(Tableau, taille, colonne); // ss prgm 4
	}
	Tableau[taille+1][taille]=sumdiag1(Tableau, taille); 		// Sous programme 5
	Tableau[0][taille]=sumdiag2(Tableau, taille); 		// Sous programme 6


			// On verifie si le carre est magique
	colonne=1;
	pasmagique=0;			//magique=faux
	while((pasmagique==0)&&(colonne<taille)) {	
		if(Tableau[taille+1][colonne]!=Tableau[taille+1][colonne+1]) {	
			pasmagique=1;
		}
		colonne++;
	}
	ligne=0;
	while((pasmagique==0)&&(ligne<taille+1))	{	
		if(Tableau[ligne][taille]!=Tableau[ligne+1][taille])	{
			pasmagique=1;
		}
		ligne++;
	}
	if((pasmagique==0)&&(Tableau[taille+1][taille]==(taille*(taille*taille+1)/2)))	{
		printf("\n\n\nLe carré est magique.\n");
	}
	else {
		printf("\n\n\nle carré n'est pas magique.\n");
	}
	return 0;
}

/******************************Zone des sous programmes*****************************************/


void saisircarre(int T[MAXELT+1][MAXELT+1],int t)
{
	int n=1,l,c;
	printf("\n\nSaisissez le carré magique :");
	for(l=1;l<=t;l++)
	{
		printf("\nligne %d",n);
		n++;
		for(c=0;c<t;c++) {
			printf("\t");
			scanf("%d",&T[l][c]);
		}
	}
}



void affichercarre(int T[MAXELT+1][MAXELT+1],int t)
{
	int	l,c;
	printf("\n\nLe tableau est le suivant :\n");
	for(l=1;l<=t;l++) {
		for(c=0;c<t;c++) {
			printf("\t%d",T[l][c]);
		}
		printf("\n");
	}
}




int sumligne(int T[MAXELT+1][MAXELT+1],int t, int l)
{
int somme=0,i;
	for(i=0;i<t;i++) {
	somme=somme+T[l][i];
	}
return somme;
}



int sumcolonne(int T[MAXELT+1][MAXELT+1],int t, int c)
{
int somme=0,j;
	for(j=1;j<=t;j++) {
	somme=somme+T[j][c];
	}
return somme;
}



int sumdiag1(int T[MAXELT+1][MAXELT+1], int t)
{
int somme=0,d;
	for(d=1;d<=t;d++) {
	somme=somme+T[d][d-1];
	}
return somme;
}



int sumdiag2(int T[MAXELT+1][MAXELT+1], int t)
{
int somme=0,d,i=0;
	for(d=t-1;d>-1;d--) {
	i++;
	somme=somme+T[i][d];
	}
return somme;
}



















