/*
Roca Dragos
Scrivere un programma che acquisisca da tastiera una parola (cioè una stringa di caratteri priva di
separatori) e dica se tale parola è palindroma, ossia leggibile nello stesso modo da destra a sinistra e
viceversa (es. OSSESSO).
*/

#include <iostream>
#include <string.h>

#define DIM 20 

//procedura che prende in input la parola e la converte in maiuscolo
void input(char parola[])  
{
     int i=0;
     printf("inserisci una parola: ");
     scanf("%s",parola);
     for (i=0; i<strlen(parola); i++) 
        if ((parola[i]>='A') && (parola[i]<='Z'))
            parola[i]+=32; //32 è la differenza nella tabella Ascii tra le lettere maiuscole e quelle minuscole 
}

//funzione che controlla se la parola è palindroma
int contr_palindroma(char parola[])
{
    bool palindroma=true;
    int i;
    for(i=0;(i<strlen(parola)/2)&&(palindroma==true);i++) //controllo per capire se il nome è palindromo
    {
        if(parola[i]!=parola[strlen(parola)-i-1])
            palindroma=false;
    }
    return palindroma;
}

//procedura che stampa se la parola messa è palindroma o no
void output(char parola[],bool palindroma)
{
    if(palindroma==true)
        printf("la parola inserita %c palindroma",138);
    else
        printf("la parola inserita non %c palindroma",138);
}

int main()
{
    char parola[DIM];
    bool palindroma;
    
    input(parola);
    palindroma=contr_palindroma(parola);
    output(parola,palindroma);
    
}

