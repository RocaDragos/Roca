/*
Roca Dragos 
2) Scrivere un programma che permetta all’utente di inserire un’intera frase. Il programma
successivamente visualizzi il numero di parole che compone la frase. Si supponga che una frase sia
costituita di parole, dove una parola è una sequenza di caratteri diversi dallo spazio e delimitata da
uno o più spazi a destra e sinistra. Uno o più spazi possono aprire o chiudere la frase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 1000 //dimensione massima della stringa, ovvero il numero massimo di caratteri da inserire

 void input(char frase[DIM])
 {
  printf("Questo programma permette di contare le parole inserite, che dovranno essere separate tra loro con uno spazio\n");
  printf("\nInserire una frase: ");
  gets(frase); //prende in input la frase interita
}

 //funzione che permette di contare il numero di parole inserite, contando il numero di spazi inseriti
 //i       variabile che viene incrementata per controllare se nella stringa "frase" sono presenti spazi
 //frase   stringa che contiene la frase che si è inserita in input
 int conteggio_parole(char frase[DIM])
 {
 	
 	int spazio = 1; //viene inizializata la variabile spazio a 1
 	int i;
 	
	 
	//ciclo che conta il numero di spazi presenti nella frase
	for(i=0;i<strlen(frase);i++)
	{
	 if(frase[i] == ' ')
	 {
	 	do{
	 		i++;
		 }while(frase[i]==' ');
		 spazio++;
	 }
    }
	
	return(spazio);
}

// procedura che stampa il numero di parole presenti nella frase
 void stampa(int spazio)
{
	 printf("\nIl numero delle parole presenti nella frase e': %d", spazio);

}


main()
{
 int n_parole;
 char frase[DIM];
 
 input(frase);
 n_parole=conteggio_parole(frase);
 stampa(n_parole);
 
return(0);
}
