#include <stdio.h>
#include <stdlib.h>

#include<locale.h> //include do set locale
#include "lab.h"
#include <string.h>

void main()
{
	//defenir logo no inicio para permitir suportar é á í ó ã õ ç 
	setlocale(LC_ALL, ""); 


	
	gotoxy(1,1);
	printf("1º Texto  a começar na linha 0 e coluna 0 com caracteres especiais é í ã º ç ã ");
	
	gotoxy(5,8);
	
	printf("2º Texto na linha 10 e coluna 5");
	
	gotoxy(15, 3);
	
	printf("3º texto na linha 5 e coluna 15");
	
	
	
	drawRect(8,10,6,6); //rectangulo de tamanho 6 x 6 a começar na linha 10, e coluna 8
	
	
	drawRect(18,10,20,8);  //Cara
	drawRect(21,12,4,2); //olho
	drawRect(31,12,4,2); //olho
	drawRect(24,16,8,1); //boca
	
	
	
	gotoxy(20,20);
}
