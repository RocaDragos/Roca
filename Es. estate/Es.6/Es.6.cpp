/*Dragos Roca 
6) Realizzare un programma che
- prenda in input da un file .csv i nomi e i voti di una serie di studenti in un compito in classe.
Un voto con valore 0 indica che lo studente è assente al momento della prova.
- Stampi la media dei voti non considerando le assenze
- Stampi il nome dello studente che ha riportato il voto massimo
- Stampi l’elenco degli studenti insufficienti (esclusi gli assenti)
- Stampi la percentuale di studenti assenti
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define DIM 20


void leggi_registro(FILE *f)
{
    system("cls");
    //apertura file
    f = fopen("registro.csv","r");
    if(f == NULL)
    {
    	printf("FIle non trovato");
    	getch();
	}
	fclose(f);
}

//procedura che permette di inserire il nome degli alunni in un array di stringhe e i loro voti in un array tutti e due di dimensione 20 
void alunni_voti(char alunni[DIM][DIM],float voti[DIM])
{
	int i=0;
	int j=0;
	FILE *f;
	int c=0;
	
	//apertura file in caso non si fosse aperto precedentemente
	if((f=fopen("registro.csv","r"))!=NULL)
	{
		for(i=0;i<DIM;i++)
		{
			for(j=0;j<DIM && c==0;j++)
			{
				fscanf(f,"%c",&alunni[i][j]); //viene inserito lettera per lettera il nome degli allievi fino a quando si trova la ','  
				if(alunni[i][j]==',')
				{
					c=1;
					alunni[i][j]='\0'; //quando si trova la ',' si inserisce il fine stringa
				}
			}
			c=0;
			fscanf(f,"%f",&voti[i]);  //vengono inseriti tutti i voti nell'array
		}	
	}
	
	fclose(f); //viene chiuso il file
}

//sottoprogramma che calcola la media dei voti esclusi gli assenti (0)
void media_voti(float voti[DIM])
{
	int i=0;
	float media=0;
	int assenti=0;
	
		for(i=0;i<DIM;i++)
		{
			if(voti[i]>0)
			media=media+voti[i];
			else
			assenti=assenti+1;
		}
    media=media/(DIM-assenti);
    printf("La media dei voti senza calcolare gli assenti %c: %.2f",138,media);
}

//procedura che stampa il nome dello studente con il voto più alto e il suo voto
void voto_maggiore(char alunni[DIM][DIM],float voti[DIM])
{
	int i=0;
	int j=0;
	float max=0;
	int posizione;
	
	for(j=0;j<DIM;j++)
	{
		if(voti[j]>max)
		{
		max=voti[j];
		posizione=j; //si mantiene la posizione del voto maggiore presente nell'array per risalire al nome dell'alunno
		}
	}
		
	printf("La persona con il voto maggiore %c :",138);
	for(i=0;i<DIM&&alunni[posizione][i]!='\0';i++)
	{
		printf("%c",alunni[posizione][i]);
	}
  	printf(" che ha preso %.2f",voti[posizione]);
    
}


//procedura che stampa i nomi di tutti gli studenti insufficenti
void studenti_insufficienti(char alunni[DIM][DIM],float voti[DIM])
{
	int i, j, c;
    c=0;
	
	for(i=0;i<DIM;i++)
	{
      if(voti[i]<6 && voti[i]!=0)
      {
        for(j=0;j<DIM&&alunni[i][j]!='\0';j++)
	      {
		      printf("%c",alunni[i][j]);
	      }
        c++;
      }
	}
    if(c==0)
        printf("Non ci sono alunni insufficienti");
    
}

//procedura che stampa la percentuale degli studenti assenti
void percentuale_assenti(float voti[DIM])
{
   int i;
   float c,percentuale;
    c=0;
	for(i=0;i<DIM;i++)
	{
      if(voti[i]==0)
      {
        c++;
      }
	}
    percentuale=c/DIM*100;
    printf("La percentuale degli assenti %c il %.2f per cento",138,percentuale);
}



//procedura per stampare il menù
void menu(FILE *f,float voti[DIM],char alunni[DIM][DIM])
{
 int scelta;
 do
  {
    do
	{
	//system("cls");
	printf("\n\n1) Media voti\n\n");
	printf("2) Studente con il voto maggiore\n\n");
	printf("3) Studenti insufficienti\n\n");
	printf("4) Percentuale degli assenti\n\n");
	printf("5) Esci\n\n");

	printf("scegli --> ");
	scanf("%d",&scelta);	
	}
	while(scelta<1||scelta>6);
	
    switch(scelta)
	{
		case 1:
		{
			system("cls");
			media_voti(voti);
			getch();
			system("cls");
			break;
		}
		case 2:
		{	
			system("cls");
		    voto_maggiore(alunni,voti);
			getch();
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			studenti_insufficienti(alunni,voti);
			getch();
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			percentuale_assenti(voti);
			getch();
			system("cls");
			break;
		}
	}
}
 while(scelta!=5);
}

int main()
{
	FILE *f;
	float voti[DIM];
	char alunni[DIM][DIM]={'\0'};
	
	leggi_registro(f);
	alunni_voti(alunni,voti);
	menu(f,voti,alunni);
}
