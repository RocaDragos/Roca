/*
Roca Dragos
Scrivere un programma che realizzi il gioco del Master Mind. Bisogna indovinare in 10 tentativi
un numero di 4 cifre pensato dal computer. Il numero in realtà sarà composto da 4 cifre singole
contenute in un vettore di tipo int di 4 posizioni. Ad ogni tiro il computer risponde indicando quante
cifre giuste al posto giusto e quante cifre giuste al posto sbagliato ci sono nel vostro numero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <CTIME>
#include <conio.h>

#define DIM 4

//procedura che genera 4 numeri random, contenenti nell'array "numeri"
void numeri_random (int numeri[DIM])
{
	int i;
	for(i=0; i<DIM; i++)
	{
		srand(time(NULL)+rand()%time(NULL));
    	numeri[i]=rand()%10;
    }
    //printf("%d %d %d %d",numeri[0],numeri[1],numeri[2],numeri[3]);
}

//procedura che chiede in input di inserire 4 numeri
int input(int tentativo[],int numeri[])
{
	int i,j=0;
		for(i=0;i<DIM;i++)
		{
		  do //se il numero inserito è maggiore di 9, mediante un ciclo "do while" si chiede di reinserire un altro valore corretto
		  {
		    printf("\nInserire il %d%c numero --> ",i+1,248);
		    scanf("%d",&tentativo[i]);
		    j=0;
		     if(tentativo[i]<0 || tentativo[i]>9)
		     {
		      printf("\nIl numero inserito non %c presente nel range tra 0 e 9",138);
		      j=1;
		     }
		  }while(j==1);
		}
}

//procedura che confronta l'array "numeri" (scelto dal computer) e l'array "tentativo" (inserito dall'utente), controlla i numeri inseriti in posizione giusta e in posizione errata
int confronto_numero_tentativo(int tentativo[], int numeri[DIM], int *posizione_giusta, int *posizione_errata)
{
	int i, j, k[]={0,0,0,0};					
	
	*posizione_giusta=0; //variabile che contiene i numeri giusti in posizione giusta 
	*posizione_errata=0; //variabile che contiene i numeri giusti in posizione sbagliata
	
	for(i=0; i<DIM; i++)
	{
		if(numeri[i] == tentativo[i]) //ciclo per controllare quanti numeri giusti in posizione giusta sono stati inseriti
		{
			*posizione_giusta=*posizione_giusta+1;
			k[i]=1; //l'array k è composto da due valori 1 e 0, 1 se sono presenti numeri in posizione giusta e 0 se sono presenti numeri in posizione sbagliatta
		}
	}
	
	for(i=0; i<DIM; i++)
	{
		if(k[i]==0)
		{
			for(j=0; j<DIM; j++)
			{
				if(k[j]==0 && j!=i) //per non controllare i valori inseriti in posizione giusta, controllati in precedenza
				{
					if(numeri[i] == tentativo[j]) //ciclo per controllare quanti numeri giusti in posizione sbagliata sono stati inseriti 
					{
					 	*posizione_errata=*posizione_errata+1;
					}
				}
			}
		}
	}
}

//procedura che in un ciclo "do while"  effettua il gioco del master mind fino a quando il numero di tentativi sarà maggiore di 10 o se si indovinano tutti i 4 numeri
// vittoria    variabile booleana, se ha il valore "true" l'utente ha vinto, se "false" l'utente ha perso o sta perdendo
//n_tentativi  numeri di tentativi(max 10)
void master_mind (bool *vittoria, int n_tentativi,int numeri[DIM])
{
    int posizione_giusta, posizione_errata, tentativo[DIM],i=0;
    n_tentativi=1;
    do
	{
		i=i+1;
		system("cls");
		printf("\nInserisci il %d%c tentativo--> \n",i,248);
	    
		input(tentativo,numeri);
		confronto_numero_tentativo(tentativo, numeri, &posizione_giusta, &posizione_errata);
		 if(posizione_giusta==4)
		 {
			*vittoria=true;
		 }
		 else
		 {
		 	*vittoria=false;
		 }
		 n_tentativi=n_tentativi+1;
		 if(*vittoria==false && n_tentativi<11)
		 {
		 	printf("\n\nHai inserito %d numeri nella posizione giusta\n",posizione_giusta);
			printf("Hai inserito %d numeri nella posizione sbagliata\n",posizione_errata);
			getch();
		 }
	}while(*vittoria==false && n_tentativi<11);
}

//procedura che stampa a schermo l'esito del gioco
void esito (bool vittoria,int numeri[DIM])
{
	if(vittoria==true)
	{
		printf("\nHAI VINTO");
	}
	else
	{
		printf("\nHAI PERSO");
		printf("\nI numeri erano: %d %d %d %d",numeri[0],numeri[1],numeri[2],numeri[3]);
	}
}


int main ()
{
	int numeri[DIM], tentativo[DIM], posizione_giusta, posizione_errata,n_tentativi;
	bool vittoria;
	numeri_random(numeri);
	master_mind(&vittoria,n_tentativi,numeri);
	esito (vittoria,numeri);
	return(0);
}
