#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>
//coloca o Cursor na posicao X,Y
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


//desenha um retangulo com linhas duplas na posicao X,Y com as dimensoes Width e Height 
void drawRect(int x, int y, int width, int height)
{
	  setlocale(LC_ALL, "C");
	int i;
	gotoxy(x, y);
	printf("%c", 201);
	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 187);
	gotoxy(x, height + y);
	printf("%c", 200);

	for (i = 1; i < width; i++) {
		printf("%c", 205);
	}

	printf("%c", 188);

	for (i = y + 1; i < height + y; i++)
	{
		gotoxy(x, i);
		printf("%c", 186);

		gotoxy(x + width, i);
		printf("%c", 186);

	} 
	 setlocale(LC_ALL, "");
}

