#include <stdio.h>

#define TAILLE 10



void initialisationTableau(int T[TAILLE+1][TAILLE+1],int taille) 
{
int i,j;
for(i=0;i<taille;i++) {
    for(j=0;j<taille;j++) {
        T[i][j]=0;
        }
    }
}


void construction_carre_impair(int T[TAILLE+1][TAILLE+1],int taille)
{
int i,ligne,colonne,sauv_ligne,sauv_colonne;
//Les variables sauv servent à sauvegarder les lignes et colonnes précédant le traitement à partir de la ligne 31.

initialisationTableau(T,taille);

//1 au milieu de la premiere ligne
ligne=0;colonne=taille/2; T[ligne][colonne]=1;

//On connait le nombre de répétitions => for
for(i=2;i<=taille*taille;i++) {
	sauv_ligne=ligne;
	sauv_colonne=colonne;
	ligne--;colonne--;
	if (ligne<0) ligne=taille-1;
	if (colonne<0) colonne=taille-1;
	if (T[ligne][colonne]!=0 ) {
    		sauv_ligne++;
    		ligne=sauv_ligne;
    		if (i==taille) ligne=0;
    		colonne=sauv_colonne;
   	 	}
	T[ligne][colonne]=i;
	}
}




void afficherTableau(const int T[TAILLE+1][TAILLE+1],int t)
{
int i,j;

for(i=0;i<t;i++) {
    printf("\n");
    for(j=0;j<t;j++) {
    	printf("%d\t",T[i][j]);
    	}
    printf("\n");
    }
}




void main()
{
    int T[TAILLE+1][TAILLE+1], taille;
    
    printf("\n	  CONSTRUCTION D'UN CARRE MAGIQUE DE TAILLE IMPAIRE");
    do
    {
        printf("\n taille de votre carre SVP (taille impaire entre 3 et %d): ",TAILLE);
        scanf("%d",&taille);
    }while(taille<=2 || taille>TAILLE+1 || taille%2==0);

construction_carre_impair(T,taille);
afficherTableau(T,taille);

}

