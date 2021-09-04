/*
Roca Dragos
5) Realizzare un programma che, data una matrice di n righe ed m colonne, permetta di
visualizzare il massimo degli elementi di ciascuna riga, il minimo di tutti gli elementi della matrice
e la media di ciascuna colonna
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define DIM 10

//procedura che inizializza tutta la matrice a 0
void inizializzazione_tabella(int mat[DIM][DIM])
{
  for(int i=0;i<DIM;i++)
  {
    for(int j=0;j<DIM;j++)
   {
    mat[i][j]=0;
   }
  }
}

//procedura che attribuisce un valore random ad ogni elemento della matrice
void random(int mat[DIM][DIM])
{

  srand(time(0));

  for(int i=0;i<DIM;i++)
  {
    for(int j=0;j<DIM;j++)
    { 
       mat[i][j]=rand()%10;
    }
  }
}

//procedura che stampa la matrice
void stampa(int mat[DIM][DIM])
{
	for(int i=0;i<DIM;i++)
  {
	for(int r=0;r<DIM;r++)
      printf("+-----+");                                 
    printf("\n");
    for(int j=0;j<DIM;j++)
    { 
       printf("|  %d  |",mat[i][j]);
    }
    printf("\n");
  }
	for(int r=0;r<DIM;r++)
    {
      printf("+-----+");                                   
    }
}

//procedura che calcola il valore maggiore per ogni riga
void max_riga(int mat[DIM][DIM])
{
  int i,j=0,c=0,r;
  int max[DIM]={0}; //array contenente i valori maggiori delle righe
  for(r=0;r<DIM;r++)
  {
    for(i=0;i<DIM;i++)
    {
     if(mat[r][i]>max[j])
      max[j]=mat[r][i];
	}
	j++;
  }
  for (j=0;j<DIM;j++)
  {
      printf("\n\nIl valore maggiore della riga %d %c %d ",c+1,138,max[j]);
      c++;
  }
}

//procedura che controlla il valore minore della matrice
void min_elemen(int mat[DIM][DIM])
{
  int min=9;
  for(int i=0;i<DIM;i++)
  {
    for(int j=0;j<DIM;j++)
   {
      if(mat[i][j]<min)
      min=mat[i][j];
   }
  }
  printf("\n\nIl valore minimo della tabella %c %d",138,min);
}

//procedura che calcola la media dei valori di ogni colonna
void media_colonna(int mat[DIM][DIM])
{
  int i,j,c=0;
  float media[DIM],somma=0;
  for(int j=0;j<DIM;j++) //colonne
  {
    somma=0;
    for(i=0;i<DIM;i++) //righe
    {
      somma=mat[i][j]+somma; 
    }
    media[j]=somma/DIM;

  }
  for (int j=0;j<DIM;j++)
  {
      printf("\n\nLa media della colonna %d e' %.2f ",c+1,media[j]);
      c++;
  }
}

//procedura per stampare il menù
void menu(int mat[DIM][DIM])
{
 int scelta;
 do
  {
    do
	{
	system("cls");
	stampa(mat);
	printf("\n\n1) Valore massimo delle righe\n\n");
	printf("2) Valore minimo della matrice\n\n");
	printf("3) Media delle colonne\n\n");
	printf("4) Esci\n\n");

	printf("scegli --> ");
	scanf("%d",&scelta);	
	}
	while(scelta<1||scelta>5);
	
    switch(scelta)
	{
		case 1:
			system("cls");
		{
			stampa(mat);
			max_riga(mat);
			getch();
			break;
		}
		case 2:
			system("cls");
		{	
		    stampa(mat);
		    min_elemen(mat);
			getch();
			break;
		}
		case 3:
			system("cls");
		{
			stampa(mat);
			media_colonna(mat);
			getch();
			break;
		}
	}
}
 while(scelta!=4);
}

int main()
{
  int mat[DIM][DIM];
  
  inizializzazione_tabella(mat);
  random(mat);
  menu(mat);
}
  
