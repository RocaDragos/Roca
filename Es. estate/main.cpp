#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define DIM 8

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

void stampa_tabella(int mat[DIM][DIM])
{
  int numeri;
  srand(time(0));

  for(int i=0;i<DIM;i++)
  {
    for(int r=0;r<DIM;r++)
      printf("+-----+");                                 
    printf("\n");
    for(int j=0;j<DIM;j++)
    { 
       mat[i][j]=rand()%10;
       printf("|  %d  |",mat[i][j]);
    }
    printf("\n");
  }
  for(int r=0;r<DIM;r++)
    {
      printf("+-----+");                                   
    }
}

void max_riga(int mat[DIM][DIM])
{
  int i,max[DIM],j,c=0;
  for(int r=0;r<DIM;r++)
  {
    for(i=0;i<DIM;i++)
    {
     if(mat[r][i]>max[j])
      max[j]=mat[r][i];
    }
    j++;
  }
  for (int j=0;j<DIM;j++)
  {
      printf("\nIl valore maggiore della riga %d e' %d ",c+1,max[j]);
      c++;
  }
}

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
  printf("\nIl valore minimo della tabella è %d",min);
}

void media_colonna(int mat[DIM][DIM])
{
  int i,j,c=0;
  float media[DIM],somma=0;
  for(int r=0;r<DIM;r++)
  {
    somma=0;
    for(i=0;i<DIM;i++)
    {
      somma=mat[i][r]+somma;
    }
    media[r]=somma/DIM;

    j++;
  }
  for (int j=0;j<DIM;j++)
  {
      printf("\nLa media della colonna %d e' %.2f ",c+1,media[j]);
      c++;
  }
}

int main()
{
  int mat[DIM][DIM];
  inizializzazione_tabella(mat);
  stampa_tabella(mat);
  printf("\n\nPremere un tasto...");
  //getch();
  //system("cls");
  max_riga(mat);

  printf("\n\nPremere un tasto...");
  //getch();
  //system("cls");
  min_elemen(mat);

  printf("\n\nPremere un tasto...");
  //getch();
  //system("cls");
  media_colonna(mat);
}