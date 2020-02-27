#include<stdio.h>
#include<stdlib.h>
#include<time.h>   
#include "lab.h"
#include<locale.h>//acentuação
#include <ctype.h>

void criardeck(int *deck)
{
	int i;
	for(i=0; i<104; i++) 
	{
		deck[i]=i+1;
		//printf("%d\n", deck[i]);
	}//distribuir numeros pelas posicoes
}//fim do criar baralho

void tdze(int *baralho)
{
	int i;
	for(i=0; i<104; i++)
	{
		baralho[i]=0;
	}
}//fim do tdze

void ordenar(int *cartas)
{
	int i, x=1, j, aux;
	while(i<6 && x>0)
	{
		x=0;
		for(j=0; j<6-i; j++)
		{
			if(cartas[j]>cartas[j+1])
			{
				aux=cartas[j];
				cartas[j]=cartas[j+1];
				cartas[j+1]=aux;
				x=1;
			}
		}
	}
}//fim do ordenarBot

void baralhar(int *deck)
{
	int i,j;
 	int aux;
 	for(i=0; i<104; i++) 
	{
  		j=rand() %104;
 	 	aux=deck[j];
  		deck[j]=deck[i];
  		deck[i]=aux;
 	}
}//fim do baralhar

void cartanamesa(int *deck, int *mesa)
{
	int j=0, i;
	while (j<1)
	{
		i=rand()%104;
		if (deck[i]>0)
		{
			mesa[0]=deck[i];
			deck[i]=0; 
			j++;
		}
	}
}//fim do cartanamesa

void darcartas(int *carta, int *jogador)
{
	int i=0, j, cont=0;
	while(i<7)
	{
		jogador[i]=0;
		j=rand()%104;
		if (carta[j]!=0)
		{
			jogador[i]=carta[j];
			carta[j]=0; 
			i++;
		}
		if(cont==104)
		criardeck(carta);
		cont++;
	}
}//fim do darcartas

void showcartas(int *player)
{
	int i;
	gotoxy(1,9);
	for(i=0; i<7; i++)
	{
		if(player[i]!=0)
		printf("%d\t", player[i]);
	}
	printf("\n");
}//fim do showcartas

void jogadabot(int *mesa, int contajogadas, int *Recolher, int *som, int *carta)
{
	int x, i, z, u;
	do{
	ordenar(carta);
	printf("Bot\n");
	showcartas(carta);
	for(i=0; i<7; i++)
	{
		if(carta[i]>mesa[contajogadas])
		{
			x=1;
			u=i;
			i+=20;
		}
		else
		x=0;
	}
	if(x==0)
	{
		for(z=0; z<=104; z++)
		{
			Recolher[z]=mesa[z];
		}
		//som+=somar(Recolher, som);
		int soma=0;
		for(i=0; i<104; i++)
		{
			if(Recolher[i]==55)
			{
				Recolher[i]=7;
			}
			else if(Recolher[i]%11==0 && Recolher[i]!=0)
			{
				Recolher[i]=6;
			}
			else if(Recolher[i]%10==0 && Recolher[i]!=0)
			{
				Recolher[i]=3;
			}
			else if(Recolher[i]%5==0 && Recolher[i]!=0)
			{
				Recolher[i]=2;
			}
			else if(Recolher[i]==0)
			{
				Recolher[i]=0;
			}
			else
			{
				Recolher[i]=1;
			}
			soma+=Recolher[i];
		}
		tdze(Recolher);
		*som+=soma;
		tdze(mesa);
	}
	}while(x==0);
	if(x==1)
	{
		mesa[contajogadas+1]=carta[u];
		carta[u]=0;
	}
	system("cls");
}//fim do jogadabots

void showcartamesa(int *mesa, int contajogadas)
{
	printf("Mesa: %d\n", mesa[contajogadas]);	
}
//fim do showcartamesa

void jogadaplayer(int *jogador, char *nome, int *rec, int *som, int contjogadas, int *mesa)
{
	ordenar(jogador);
	int x, i, u, k, l;
	char c;
	char r;
	int q, card, z, somartd;
	for(q=0; q<1; q++)
	{
		do{
		do{
			drawRect(0,3,22,3);
			gotoxy(1,4);
		printf("%s pronto/a?\n", nome);
		gotoxy(1,5);
		printf("A sua resposta:    ");//apagar o que estava anteriormente
		gotoxy(1,5);
		printf("A sua resposta: ");
		fflush(stdin);
		scanf("%c", &r);
		}while(r!='s' && r!='S');
		do{
		do{
			drawRect(0,7,52,7);
			gotoxy(1,8);
		printf("%s\n", nome);
		gotoxy(1,9);
		showcartas(jogador);
		q++;
//		else if(r=='n' || r=='N')
//		{
//			jogadaplayer(jogador, nome, rec, som, contjogadas, mesa);
//			q++;
//		}
//		else if(r!='n' || r!='N' || r=='s' || r=='S')
//		{
//			jogadaplayer(jogador, nome, rec, som, contjogadas, mesa);
//			q++;
//		}
		l=0;
		gotoxy(1,10);
		printf("Jogar ou Recolher?\n");
		gotoxy(1,11);
		printf("A sua escolha:         ");//apagar o que estava anteriormente
		gotoxy(1,11);
		printf("A sua escolha: ");
		fflush(stdin);
		scanf("%c", &c);
		}while(c!='R' && c!='r' && c!='j' && c!='J');
		if (c=='R' || c=='r')
		{
			/*int m;
			for(m=0; m<104; m++)
			{
				printf("Mesa[%d]=%d\n", m, mesa[m]);
			}*/
			for(z=0; z<104; z++)
			{
				rec[z]=mesa[z];
				/*printf("Mesa[%d]=%d\n", z, mesa[z]);
				printf("RECOLHER[%d]=%d\n", z, rec[z]);*/
			}
			//som=somar(rec, &som);
			int soma=0;
			for(i=0; i<104; i++)
			{
			if(rec[i]==55)
			{
				rec[i]=7;
			}
			else if(rec[i]%11==0 && rec[i]!=0)
			{
				rec[i]=6;
			}
			else if(rec[i]%10==0 && rec[i]!=0)
			{
				rec[i]=3;
			}
			else if(rec[i]%5==0 && rec[i]!=0)
			{
				rec[i]=2;
			}
			else if(rec[i]==0)
			{
				rec[i]=0;
			}
			else
			{
				rec[i]=1;
			}
			soma+=rec[i];
			}
			tdze(rec);
			*som+=soma;
			tdze(mesa);
			drawRect(0,0,10,2);
			gotoxy(1,1);
			printf("Mesa: 0  \n");
			gotoxy(1,11);
			printf("A sua escolha:             ");
		}
		}while(c!='J' && c!='j');
		for(k=0; k<7; k++)
		{
			if(jogador[k]<=mesa[contjogadas])
			{	
				l=1;				
			}
		
			else
			{
				l=0;
				k+=20;
			}
		}
		}while(l>0);
		if (c=='J'|| c=='j'){
		do{
		gotoxy(1,12);
		printf("A sua carta:     ");//apagar o que estava anteriormente
		gotoxy(1,12);
		printf("A sua carta: ");
		fflush(stdin);
		scanf("%d", &card);
		for(i=0; i<7; i++)
		{
			if(card>mesa[contjogadas] && card==jogador[i])
			{
				x=1;
				u=i;
				i+=20;
			}
			
			else
			x=0;
		}
		if(x==0){
			gotoxy(1,13);
		printf("Jogada inválida.\n");
		}
		else
		{
			mesa[contjogadas+1]=card;
			jogador[u]=0;
			//showcartas(jogador);
		}
		}while(x<1);
		showcartamesa(mesa, contjogadas+1);
		}
		//}while(c!='R' && c!='r');
		/*if(c!='R' && c!='r' && c!='j' && c!='J')
		jogadaplayer(jogador, nome, rec, som, contjogadas, mesa);*/
	}
	system("cls");
}//fim do jogadaplayer

/*int somar(int *recolher, int *soma)
{
	int i;
	
	for(i=0; i<104; i++)
	{
		if(recolher[i]==55)
		{
			recolher[i]=7;
		}
		else if(recolher[i]%11==0 && recolher[i]!=0)
		{
			recolher[i]=6;
		}
		else if(recolher[i]%10==0 && recolher[i]!=0)
		{
			recolher[i]=3;
		}
		else if(recolher[i]%5==0 && recolher[i]!=0)
		{
			recolher[i]=2;
		}
		else if(recolher[i]==0)
		{
			recolher[i]=0;
		}
		else
		{
			recolher[i]=1;
		}
		*soma+=recolher[i];
	}
	tdze(recolher);
	return *soma;
}*/	

int main()
{
	
	setlocale(LC_ALL, ""); 
	srand(time(NULL));
	FILE *result, *LastRound;
	int som=0, menor, jogos=1, ronda=0, control=0;
	int Deck[104], Mesa[105], Njogada;
	char Nome1[20];
	int Recolher1[104], Soma1=0, CartasJogador1[7];
	char Nome2[20];
	int Recolher2[104], Soma2=0, CartasJogador2[7]; 
	char Nome3[20];
	int Recolher3[104], Soma3=0, CartasJogador3[7];  
	char Nome4[20];
	int Recolher4[104], Soma4=0, CartasJogador4[7];  
	char Nome5[20];
	int Recolher5[104], Soma5=0, CartasJogador5[7];
	char menu, decisao;
	int num, contjog;
	int Rec1[104], SomaB1=0, CartasBot1[7];//Bot1
	int Rec2[104], SomaB2=0, CartasBot2[7];//Bot2
	int Rec3[104], SomaB3=0, CartasBot3[7];//Bot3
	int controlar=0;
	
	drawRect(0,0,50,7);
	gotoxy(20,1);
	printf("Jogo leva6!\n");
//	printf("****************************************************\n");
	gotoxy(1,2);
	printf("a. Jogar uma partida de leva 6!\n");
	gotoxy(1,3);
	printf("b. Carregar uma partida a partir de ficheiro.\n");
	gotoxy(1,4);	
	printf("c. Apresentar uma descricao do jogo na consola.\n");
	gotoxy(1,5);
	printf("d. Sair da aplicacao.\n");
//	printf("****************************************************\n");
	gotoxy(1,6);
	printf("A sua opção: ");
	scanf("%c", &menu);  
	if(menu=='a' || menu=='A')
	{
		drawRect(0,8,50,3);
		gotoxy(1,9);
		printf("Indique o número de jogardores. No maximo 5.\n");
		gotoxy(1,10);		
		scanf(" %d", &num);
		switch(num)
		{
			case 1:
				drawRect(0,12,50,3);
				gotoxy(1,13);
				printf("Insira o nome do jogador.\n");
				fflush(stdin);
				gotoxy(1,14);
				gets(Nome1);
				//scanf("%s", Nome1);
				//printf("%s\n", Nome1);
				break;
			case 2:
				drawRect(0,12,50,4);
				gotoxy(1,13);
				printf("Insira o nome dos dois jogadores.\n");
				fflush(stdin);
				gotoxy(1,14);
				scanf("%s", Nome1);
				fflush(stdin);
				gotoxy(1,15);
				scanf("%s", Nome2);
				//printf("%s\n%s\n", Nome1, Nome2);
				break;
			case 3:
				drawRect(0,12,50,5);
				gotoxy(1,13);
				printf("Insira o nome dos três jogadores.\n");
				fflush(stdin);
				gotoxy(1,14);
				scanf("%s", Nome1);
				fflush(stdin);
				gotoxy(1,15);
				scanf("%s", Nome2);
				fflush(stdin);
				gotoxy(1,16);
				scanf("%s", Nome3);
				//printf("%s\n%s\n%s\n", Nome1, Nome2, Nome3);
				break;
			case 4:
				drawRect(0,12,50,6);
				gotoxy(1,13);
				printf("Insira o nome dos quatro jogadores.\n");
				fflush(stdin);
				gotoxy(1,14);
				scanf("%s", Nome1);
				fflush(stdin);
				gotoxy(1,15);
				scanf("%s", Nome2);
				fflush(stdin);
				gotoxy(1,16);
				scanf("%s", Nome3);
				fflush(stdin);
				gotoxy(1,17);
				scanf("%s", Nome4);
				//printf("%s\n%s\n%s\n%s\n", Nome1, Nome2, Nome3, Nome4);
				break;
			case 5:
				drawRect(0,12,50,7);
				gotoxy(1,13);
				printf("Insira o nome dos cinco jogadores.\n");
				fflush(stdin);
				gotoxy(1,14);
				scanf("%s", Nome1);
				fflush(stdin);
				gotoxy(1,15);
				scanf("%s", Nome2);
				fflush(stdin);
				gotoxy(1,16);
				scanf("%s", Nome3);
				fflush(stdin);
				gotoxy(1,17);
				scanf("%s", Nome4);
				fflush(stdin);
				gotoxy(1,18);
				scanf("%s", Nome5);
				//printf("%s\n%s\n%s\n%s\n%s\n", Nome1, Nome2, Nome3, Nome4, Nome5);
				break;
			default :
				drawRect(0,12,50,2);
				gotoxy(1,13);
				printf("Jogadores inválidos.\n");
				exit(0);
		}
		do{
			system("cls");
			drawRect(0,0,20,2);
			gotoxy(1,1);
			printf("Preparando o jogo.\n");
			sleep(2);
			system("cls");
			ronda=0;
			Soma1=0;
			Soma2=0;
			Soma3=0;
			Soma4=0;
			Soma5=0;
			SomaB1=0;
			SomaB2=0;
			SomaB3=0;
		system("cls");
		criardeck(Deck);
		do{
		baralhar(Deck);
		tdze(Mesa);
		Mesa[105]=0;
		tdze(Rec1);
		tdze(Rec2);
		tdze(Rec3);
		tdze(Recolher1);
		tdze(Recolher2);
		tdze(Recolher3);
		tdze(Recolher4);
		tdze(Recolher5);
		contjog=0;
		drawRect(0,0,10,2);
		gotoxy(1,1);
		/*if(control==0)//depois de acabar as cartas da mao, nao tera carta nenhuma na mesa
		{
			cartanamesa(Deck, Mesa);
			control++;
		}*/
		cartanamesa(Deck, Mesa);
		if (num==1)
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasJogador1);

		}
		else if(num==2)
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasBot2);
			darcartas(Deck, CartasBot3);
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
		}
		else if(num==3)
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasBot2);
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
			darcartas(Deck, CartasJogador3);
		}
		else if(num==4)
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
			darcartas(Deck, CartasJogador3);
			darcartas(Deck, CartasJogador4);
		}
		else if(num==5)
		{
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
			darcartas(Deck, CartasJogador3);
			darcartas(Deck, CartasJogador4);
			darcartas(Deck, CartasJogador5);
		}
		do{
			drawRect(0,0,10,2);
			gotoxy(1,1);
		showcartamesa(Mesa, contjog);
		if(num==1)
		{
			//printf("%d", Soma1);
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}		
		if(num==2)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			jogadabot(Mesa, contjog, Rec2, &SomaB2, CartasBot2);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot2 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			jogadabot(Mesa, contjog, Rec3, &SomaB3, CartasBot3);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot3 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}
		if(num==3)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador3, Nome3, Recolher3, &Soma3, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			jogadabot(Mesa, contjog, Rec2, &SomaB2, CartasBot2);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot2 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}
		if(num==4)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador3, Nome3, Recolher3, &Soma3, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador4, Nome4, Recolher4, &Soma4, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}
		if (num==5)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
		
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador3, Nome3, Recolher3, &Soma3, contjog, Mesa);
			contjog++;
		
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador4, Nome4, Recolher4, &Soma4, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador5, Nome5, Recolher5, &Soma5, contjog, Mesa);
			contjog++;
			ronda++;
		}
		if((LastRound=fopen("UltimaRonda.txt", "w"))==NULL)
		{
			printf("Erro: não é possivel salvar a ultima ronda.\n");
			printf("Proxima ronda em 3.");
			sleep(1);
			printf("Proxima ronda em 2.");
			sleep(1);
			printf("Proxima ronda em 1.");
			sleep(1);
		}
		int xp;
		fprintf(LastRound, "%d\n", num);
		if(num==1)
		{
			ordenar(CartasJogador1);
			ordenar(CartasBot1);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			//fclose(LastRound);
		}
		if(num==2)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasBot1);
			ordenar(CartasBot2);
			ordenar(CartasBot3);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			fprintf(LastRound, "4:V;Bot2;%d:", SomaB2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot2[xp]);
			}	
			fprintf(LastRound, "5:V;Bot3;%d:", SomaB3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot3[xp]);
			}	
			//fclose(LastRound);
		}
		if(num==3)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasJogador3);
			ordenar(CartasBot1);
			ordenar(CartasBot2);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:R;%s;%d:", Nome3, Soma3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador3[xp]);
			}	
			fprintf(LastRound, "4:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			fprintf(LastRound, "5:V;Bot2;%d:", SomaB2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot2[xp]);
			}	
			//fclose(LastRound);	
		}
		if(num==4)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasJogador3);
			ordenar(CartasJogador4);
			ordenar(CartasBot1);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:R;%s;%d:", Nome3, Soma3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador3[xp]);
			}	
			fprintf(LastRound, "4:R;%s;%d:", Nome4, Soma4);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador4[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador4[xp]);
			}
			fprintf(LastRound, "5:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			//fclose(LastRound);	
		}
		if(num==5)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasJogador3);
			ordenar(CartasJogador4);
			ordenar(CartasJogador5);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:R;%s;%d:", Nome3, Soma3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador3[xp]);
			}	
			fprintf(LastRound, "4:R;%s;%d:", Nome4, Soma4);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador4[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador4[xp]);
			}
			fprintf(LastRound, "5:R;%s;%d:", Nome5, Soma5);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador5[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador5[xp]);
			}
			//fclose(LastRound);
		}
		fprintf(LastRound, "#0:M;");
		for(xp=0; xp<104; xp++)
		{
			if(Mesa[xp]>0 && Mesa[xp+1]>0)
			fprintf(LastRound, "%d,", Mesa[xp]);
			if(Mesa[xp]>0 && Mesa[xp+1]==0)
			fprintf(LastRound, "%d\n", Mesa[xp]);
		}	
		fclose(LastRound);
		}while(CartasJogador1[6]!=0 || CartasJogador1[5]!=0);
		contjog=0;
		}while(Soma1<66 && Soma2<66 && Soma3<66 && Soma4<66 && Soma5<66 && SomaB1<66 && SomaB2<66 && SomaB3<66);
		
		menor=Soma1;
		if(menor>Soma2 && num>1)
		menor=Soma2;
		if(menor>Soma3 && num>2)
		menor=Soma3;
		if(menor>Soma4 && num>3)
		menor=Soma4;
		if(menor>Soma5 && num==5)
		menor=Soma5;
		if(menor>SomaB1 && num>0 && num<5)
		menor=SomaB1;
		if(menor>SomaB2 && num>1 && num<4)
		menor=SomaB2;
		if(menor>SomaB3 && num==2)
		menor=SomaB3;
		if(controlar>0)
		{
			if((result=fopen("resultados.txt", "a"))==NULL)
			{
				printf("Erro: não é possivel abrir o ficheiro resultados.txt\n");
				exit(-1);
			}
		}
		else 
		{
			if((result=fopen("resultados.txt", "w"))==NULL)
			{
				printf("Erro: não é possivel abrir o ficheiro resultados.txt\n");
				exit(-1);
			}
			controlar++;
		}
		if(menor==Soma1)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome1);
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome1, ronda, Soma1);
		}
		else if(menor==Soma2)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome2);	
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome2, ronda, Soma2);
		}
		else if(menor==Soma3)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome3);	
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome3, ronda, Soma3);
		}
		else if(menor==Soma4)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome4);
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome4, ronda, Soma4);
		}
		else if(menor==Soma5)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome5);
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome5, ronda, Soma5);
		}
		else if(menor==SomaB1)
		{
			drawRect(0,0,22,2);
			gotoxy(1,1);
			printf("O vencedor é o Bot 1.\n");
			fprintf(result, "O vencedor do %dº jogo foi o Bot 1 na ronda %d com %d cabeças de boi.\n", jogos, ronda, SomaB1);
		}
		else if(menor==SomaB2)
		{
			drawRect(0,0,22,2);
			gotoxy(1,1);
			printf("O vencedor é o Bot 2.\n");
			fprintf(result, "O vencedor do %dº jogo foi o Bot 2 na ronda %d com %d cabeças de boi.\n", jogos, ronda, SomaB2);
		}
		else if(menor==SomaB3)
		{
			drawRect(0,0,22,2);
			gotoxy(1,1);
			printf("O vencedor é o Bot 3.\n");
			fprintf(result, "O vencedor  do %dº jogo foi o Bot 3 na ronda %d com %d cabeças de boi.\n", jogos, ronda, SomaB3);
		}
		fclose(result);
		drawRect(0,3,22,3);
		gotoxy(1,4);
		printf("Jogar outra vez? s/n\n");
		fflush(stdin);
		gotoxy(1,5);
		scanf("%c", &decisao);
		if(decisao=='S' || decisao=='s')
		jogos++;
		}while(decisao=='S' || decisao=='s');
	}
	else if(menu=='b' || menu=='B')
	{
		char c[1000];
		int xp=0, aux, contletras, cartas=0, aux1=1, ajuda, ajuda1;
		tdze(Mesa);
		if((LastRound=fopen("UltimaRonda.txt", "r"))==NULL)
		{
			system("cls");
			printf("Erro: Não é possivel carregar a ultima ronda.\n");
			system("pause");
			exit(-1);
		}
		do
		{
			c[xp]=fgetc(LastRound);
			xp++;
		}while(c[xp]!=EOF);
		//printf("%c", c[0]);
		//system("pause");
		//fscanf(LastRound,"%[^EOF]", c);
		
	//	printf("Data from the file:\n%c", c);
		num=c[0]-48;
		int f;
		for(f=0; f<20; f++)
		{
			Nome1[f]='\0';
			Nome2[f]='\0';
			Nome3[f]='\0';
			Nome4[f]='\0';
			Nome5[f]='\0';
		}
		xp=0;
		do{
		if(c[xp]==';')//nomes
		{
			aux=xp;
			contletras=0;
			do{
			if(c[xp+1]!=';')
			{
				//printf("%c\n", c[xp+1]);
				if(c[aux-3]=='1' && c[xp+1]!=';' && c[aux-1]=='R')
				{
					Nome1[contletras]=c[xp+1];
					//printf("%c", Nome1[contletras]);
					contletras++;
				}
				if(c[aux-3]=='2' && c[xp+1]!=';' && c[aux-1]=='R')
				{
					Nome2[contletras]=c[xp+1];
					//printf("%c", Nome2[contletras]);
					contletras++;
				}
				if(c[aux-3]=='3' && c[xp+1]!=';' && c[aux-1]=='R')
				{
					Nome3[contletras]=c[xp+1];
					//printf("%c", Nome3[contletras]);
					contletras++;
				}
				if(c[aux-3]=='4' && c[xp+1]!=';' && c[aux-1]=='R')
				{
					Nome4[contletras]=c[xp+1];
					//printf("%c", Nome4[contletras]);
					contletras++;
				}
				if(c[aux-3]=='5' && c[xp+1]!=';' && c[aux-1]=='R')
				{
					Nome5[contletras]=c[xp+1];
					//printf("%c", Nome5[contletras]);
					contletras++;
				}
			}
			xp++;
			}while(c[xp]!=';');//fim dos nomes
			/*printf("Nome %c com ", c[aux-3]);
			printf("%d\n", contletras);*/
		}
		xp++;
		}while(c[xp]!='#');//fim de ler os nomes
		xp=0;
		do{
		if(c[xp]==':')//cartas
		if(isdigit(c[xp+1]))
		do{
			//printf("%c", c[xp+1]);
			if(aux1==1  && (c[xp+2]==',' || c[xp+2]=='\n'))
			{
				CartasJogador1[cartas]=c[xp+1]-48;
				cartas++;
			}
			else if(aux1==1  && c[xp+1]!=',' && c[xp+1]!='\n' && (c[xp+2]!=',' || c[xp+2]!='\n') && (c[xp+3]==',' || c[xp+3]=='\n'))
			{
				ajuda=c[xp+1]-48;
				CartasJogador1[cartas]=ajuda*10+(c[xp+2]-48);
				cartas++;
				xp++;
			}
			else if(aux1==1  && c[xp+1]!=',' && c[xp+1]!='\n' && c[xp+2]!=',' && c[xp+2]!='\n' && (c[xp+3]!=',' || c[xp+3]!='\n'))
			{
				ajuda=c[xp+1]-48;
				ajuda1=c[xp+2]-48;
				CartasJogador1[cartas]=ajuda*100+ajuda1*10+(c[xp+3]-48);
				cartas++;
				xp+=2;
			}
			//____________________________________________________________________________________________
			if(aux1==2  && (c[xp+2]==',' || c[xp+2]=='\n'))
			{
				CartasJogador2[cartas]=c[xp+1]-48;
				cartas++;
			}
			else if(aux1==2  && c[xp+1]!=',' && c[xp+1]!='\n' && (c[xp+2]!=',' || c[xp+2]!='\n') && (c[xp+3]==',' || c[xp+3]=='\n'))
			{
				ajuda=c[xp+1]-48;
				CartasJogador2[cartas]=ajuda*10+(c[xp+2]-48);
				cartas++;
				xp++;
			}
			else if(aux1==2  && c[xp+1]!=',' && c[xp+1]!='\n' && c[xp+2]!=',' && c[xp+2]!='\n' && (c[xp+3]!=',' || c[xp+3]!='\n'))
			{
				ajuda=c[xp+1]-48;
				ajuda1=c[xp+2]-48;
				CartasJogador2[cartas]=ajuda*100+ajuda1*10+(c[xp+3]-48);
				cartas++;
				xp+=2;
			}
			//____________________________________________________________________________________________
			if(aux1==3 && (c[xp+2]==',' || c[xp+2]=='\n'))
			{
				CartasJogador3[cartas]=c[xp+1]-48;
				cartas++;
			}
			else if(aux1==3 && c[xp+1]!=',' && c[xp+1]!='\n' && (c[xp+2]!=',' || c[xp+2]!='\n') && (c[xp+3]==',' || c[xp+3]=='\n'))
			{
				ajuda=c[xp+1]-48;
				CartasJogador3[cartas]=ajuda*10+(c[xp+2]-48);
				cartas++;
				xp++;
			}
			else if(aux1==3 && c[xp+1]!=',' && c[xp+1]!='\n' && c[xp+2]!=',' && c[xp+2]!='\n' && (c[xp+3]!=',' || c[xp+3]!='\n'))
			{
				ajuda=c[xp+1]-48;
				ajuda1=c[xp+2]-48;
				CartasJogador3[cartas]=ajuda*100+ajuda1*10+(c[xp+3]-48);
				cartas++;
				xp+=2;
			}
			//____________________________________________________________________________________________
			if(aux1==4 && (c[xp+2]==',' || c[xp+2]=='\n'))
			{
				CartasJogador4[cartas]=c[xp+1]-48;
				cartas++;
			}
			else if(aux1==4 && c[xp+1]!=',' && c[xp+1]!='\n' && (c[xp+2]!=',' || c[xp+2]!='\n') && (c[xp+3]==',' || c[xp+3]=='\n'))
			{
				ajuda=c[xp+1]-48;
				CartasJogador4[cartas]=ajuda*10+(c[xp+2]-48);
				cartas++;
				xp++;
			}
			else if(aux1==4 && c[xp+1]!=',' && c[xp+1]!='\n' && c[xp+2]!=',' && c[xp+2]!='\n' && (c[xp+3]!=',' || c[xp+3]!='\n'))
			{
				ajuda=c[xp+1]-48;
				ajuda1=c[xp+2]-48;
				CartasJogador4[cartas]=ajuda*100+ajuda1*10+(c[xp+3]-48);
				cartas++;
				xp+=2;
			}
			//____________________________________________________________________________________________
			if(aux1==5 && (c[xp+2]==',' || c[xp+2]=='\n'))
			{
				CartasJogador5[cartas]=c[xp+1]-48;
				cartas++;
			}
			else if(aux1==5  && c[xp+1]!=',' && c[xp+1]!='\n' && (c[xp+2]!=',' || c[xp+2]!='\n') && (c[xp+3]==',' || c[xp+3]=='\n'))
			{
				ajuda=c[xp+1]-48;
				CartasJogador5[cartas]=ajuda*10+(c[xp+2]-48);
				cartas++;
				xp++;
			}
			else if(aux1==5 && c[xp+1]!=',' && c[xp+1]!='\n' && c[xp+2]!=',' && c[xp+2]!='\n' && (c[xp+3]!=',' || c[xp+3]!='\n'))
			{
				ajuda=c[xp+1]-48;
				ajuda1=c[xp+2]-48;
				CartasJogador5[cartas]=ajuda*100+ajuda1*10+(c[xp+3]-48);
				cartas++;
				xp+=2;
			}
			xp++;
			if(c[xp+1]=='\n')
			aux1++;
		}while(c[xp]!='\n');//fim de cada linha das cartas
		cartas=0;
		xp++;
		}while(c[xp]!='#');//fim de ler todas as cartas
		xp=0;
		int auxilio=1;
		do{
		if(c[xp]==';')//cabeças de boi
		if(isdigit(c[xp+1]))
		do{
			//printf("%c", c[xp+1]);
			if (auxilio==1)
			{
				if(c[xp+2]==':')
				Soma1=c[xp+1]-48;
				else 
				{
					Soma1=(c[xp+1]-48)*10+c[xp+2]-48;
					xp++;
				}
			}
			if (auxilio==2)
			{
				if(c[xp+2]==':')
				Soma2=c[xp+1]-48;
				else 
				{
					Soma2=(c[xp+1]-48)*10+c[xp+2]-48;
					xp++;
				}
			}
			if (auxilio==3)
			{
				if(c[xp+2]==':')
				Soma3=c[xp+1]-48;
				else 
				{
					Soma3=(c[xp+1]-48)*10+c[xp+2]-48;
					xp++;
				}
			}
			if (auxilio==4)
			{
				if(c[xp+2]==':')
				Soma4=c[xp+1]-48;
				else 
				{
					Soma4=(c[xp+1]-48)*10+c[xp+2]-48;
					xp++;
				}
			}
			if (auxilio==5)
			{
				if(c[xp+2]==':')
				Soma5=c[xp+1]-48;
				else 
				{
					Soma5=(c[xp+1]-48)*10+c[xp+2]-48;
					xp++;
				}
			}
			xp++;
			auxilio++;
		}while(c[xp+1]!=':');//fim de cada cabeça de boi dos jogadores
		xp++;
		}while(c[xp]!='#');//fim de ler todas as cabeças de boi
		/*printf("\n%s\n", Nome1);
		printf("%s\n", Nome2);
		printf("%s\n", Nome3);
		printf("%s\n", Nome4);
		printf("%s\n", Nome5);*/
		int i;
		if(num==1)
		{
			for(i=0;i<7;i++)
			{
				SomaB1=Soma2;
				CartasBot1[i]=CartasJogador2[i];
				CartasJogador2[i]=0;
			}
		}
		if(num==2)
		{
			for(i=0;i<7;i++)
			{
				SomaB1=Soma3;
				CartasBot1[i]=CartasJogador3[i];
				CartasJogador3[i]=0;
			}
			for(i=0;i<7;i++)
			{
				SomaB2=Soma4;
				CartasBot2[i]=CartasJogador4[i];
				CartasJogador4[i]=0;
			}
			for(i=0;i<7;i++)
			{
				SomaB3=Soma5;
				CartasBot3[i]=CartasJogador5[i];
				CartasJogador5[i]=0;
			}
		}
		if(num==3)
		{
			for(i=0;i<7;i++)
			{
				SomaB1=Soma4;
				CartasBot1[i]=CartasJogador4[i];
				CartasJogador4[i]=0;
			}
			for(i=0;i<7;i++)
			{
				SomaB2=Soma5;
				CartasBot2[i]=CartasJogador5[i];
				CartasJogador5[i]=0;
			}
		}
		if(num==4)
		{
			for(i=0;i<7;i++)
			{
				SomaB1=Soma5;
				CartasBot1[i]=CartasJogador5[i];
				CartasJogador5[i]=0;
			}
		}
		xp=0;
		do{
			cartas=0;
			if(c[xp]=='#')
			do{
				if(c[xp+1]-48>0 && c[xp+1]!=':' && c[xp+1]!='M' && c[xp+1]!=';')
				if(c[xp+2]==',' || c[xp+2]=='\n')
			{
				Mesa[cartas]=c[xp+1]-48;
				cartas++;
			}
			else if( c[xp+1]!=',' && c[xp+1]!='\n' && (c[xp+2]!=',' || c[xp+2]!='\n') && (c[xp+3]==',' || c[xp+3]=='\n'))
			{
				ajuda=c[xp+1]-48;
				Mesa[cartas]=ajuda*10+(c[xp+2]-48);
				cartas++;
				xp++;
			}
			else if( c[xp+1]!=',' && c[xp+1]!='\n' && c[xp+2]!=',' && c[xp+2]!='\n' && (c[xp+3]!=',' || c[xp+3]!='\n'))
			{
				ajuda=c[xp+1]-48;
				ajuda1=c[xp+2]-48;
				Mesa[cartas]=ajuda*100+ajuda1*10+(c[xp+3]-48);
				cartas++;
				xp+=2;
			}
			xp++;
			}while(c[xp+1]!='\n');
			
			
			xp++;
		}while(c[xp]!=EOF);
		/*printf("%d\n", num);
		for(i=0;i<7;i++)
		printf("%d\t", CartasJogador1[i]);
		printf("\n");
		for(i=0;i<7;i++)
		printf("%d\t", CartasJogador2[i]);
		printf("\n");
		for(i=0;i<7;i++)
		printf("%d\t", CartasJogador3[i]);
		printf("\n");
		for(i=0;i<7;i++)
		printf("%d\t", CartasJogador4[i]);
		printf("\n");
		for(i=0;i<7;i++)
		printf("%d\t", CartasJogador5[i]);
		printf("\n");
		printf("%d\t", Soma1);
		printf("\n");
		printf("%d\t", Soma2);
		printf("\n");
		printf("%d\t", Soma3);
		printf("\n");
		printf("%d\t", Soma4);
		printf("\n");
		printf("%d\t", Soma5);
		printf("\n");
		printf("%d\t", Mesa);*/
	/*	for(i=0;i<7;i++)
		printf("%d\t", CartasBot1[i]);
		printf("\n");
		for(i=0;i<7;i++)
		printf("%d\t", CartasBot2[i]);
		printf("\n");
		for(i=0;i<7;i++)
		printf("%d\t", CartasBot3[i]);
		printf("\n");*/
		
		/*int x=0;
		//printf("%c", num);
		xp=6;
		
		do{
			if(!isdigit(c[xp+1]))
			Mesa[x]=c[xp];
			if(isdigit(c[xp+1]))
			{
				
				Mesa[x]=c[xp]*10+c[xp+1];
				//xp++;
			}
			if(isdigit(c[xp+2]))
			Mesa[x]=c[xp]*100+c[xp+1]*10+c[xp+2];
			x++;
			xp+=2;	
		}while(c[xp+1]!='\n' && c[xp+2]!='\n' && c[xp+3]!='\n');*/
		//printf("%c", Mesa[0]);
		/*fscanf(LastRound, "%d\n0:M;", &num);
		do
		{
			fscanf(LastRound, "%d", &Mesa[xp]);
			fscanf(LastRound, ",");
			printf("%d", Mesa[xp]);
			xp++;
		}while(Mesa[xp]==0);
		
		system("pause");
		if(num==1)
		{
			ordenar(CartasJogador1);
			ordenar(CartasBot1);
			fscanf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fscanf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fscanf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fscanf(LastRound, "2:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fscanf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fscanf(LastRound, "%d\n", CartasBot1[xp]);
			}	
		} */
		int contamesa=0;
		for(i=0; i<104; i++)
		if(Mesa[i]>0)
		contamesa++;
		contjog=contamesa-1;
		//system("pause");
		system("cls");
		int qualquer=0;
		jogos=1;
		do{
			system("cls");
			drawRect(0,0,20,2);
			gotoxy(1,1);
			printf("Carregando o jogo.\n");
			sleep(2);
			system("cls");
			ronda=0;
			if(qualquer==1)
			{
			Soma1=0;
			Soma2=0;
			Soma3=0;
			Soma4=0;
			Soma5=0;
			SomaB1=0;
			SomaB2=0;
			SomaB3=0;
			}
		system("cls");
		criardeck(Deck);
		do{
		baralhar(Deck);
		if(qualquer==1 ||CartasJogador1[6]==0)
		{
			contjog=0;
			tdze(Mesa);
		}
		Mesa[105]=0;
		tdze(Rec1);
		tdze(Rec2);
		tdze(Rec3);
		tdze(Recolher1);
		tdze(Recolher2);
		tdze(Recolher3);
		tdze(Recolher4);
		tdze(Recolher5);
		drawRect(0,0,10,2);
		gotoxy(1,1);
		/*if(control==0)//depois de acabar as cartas da mao, nao tera carta nenhuma na mesa
		{
			cartanamesa(Deck, Mesa);
			control++;
		}*/
		cartanamesa(Deck, Mesa);
		if (num==1 && (qualquer==1 ||CartasJogador1[6]==0))
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasJogador1);

		}
		else if(num==2 && (qualquer==1 ||CartasJogador1[6]==0))
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasBot2);
			darcartas(Deck, CartasBot3);
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
		}
		else if(num==3 && (qualquer==1 ||CartasJogador1[6]==0))
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasBot2);
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
			darcartas(Deck, CartasJogador3);
		}
		else if(num==4 && (qualquer==1 ||CartasJogador1[6]==0))
		{
			darcartas(Deck, CartasBot1);
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
			darcartas(Deck, CartasJogador3);
			darcartas(Deck, CartasJogador4);
		}
		else if(num==5 && (qualquer==1 ||CartasJogador1[6]==0))
		{
			darcartas(Deck, CartasJogador1);
			darcartas(Deck, CartasJogador2);
			darcartas(Deck, CartasJogador3);
			darcartas(Deck, CartasJogador4);
			darcartas(Deck, CartasJogador5);
		}
		do{
			drawRect(0,0,10,2);
			gotoxy(1,1);
		showcartamesa(Mesa, contjog);
		if(num==1)
		{
			//printf("%d", Soma1);
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}		
		if(num==2)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			jogadabot(Mesa, contjog, Rec2, &SomaB2, CartasBot2);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot2 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			jogadabot(Mesa, contjog, Rec3, &SomaB3, CartasBot3);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot3 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}
		if(num==3)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador3, Nome3, Recolher3, &Soma3, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			jogadabot(Mesa, contjog, Rec2, &SomaB2, CartasBot2);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot2 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}
		if(num==4)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador3, Nome3, Recolher3, &Soma3, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador4, Nome4, Recolher4, &Soma4, contjog, Mesa);
			contjog++;
			showcartamesa(Mesa, contjog);
			jogadabot(Mesa, contjog, Rec1, &SomaB1, CartasBot1);
			drawRect(0,0,15,2);
			gotoxy(1,1);
			printf("Bot1 a jogar.\n");
			sleep(2);
			system("cls");
			contjog++;
			ronda++;
		}
		if (num==5)
		{
			jogadaplayer(CartasJogador1, Nome1, Recolher1, &Soma1, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador2, Nome2, Recolher2, &Soma2, contjog, Mesa);
			contjog++;
		
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador3, Nome3, Recolher3, &Soma3, contjog, Mesa);
			contjog++;
		
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador4, Nome4, Recolher4, &Soma4, contjog, Mesa);
			contjog++;
			
			drawRect(0,0,10,2);
			gotoxy(1,1);
			showcartamesa(Mesa, contjog);
			jogadaplayer(CartasJogador5, Nome5, Recolher5, &Soma5, contjog, Mesa);
			contjog++;
			ronda++;
		}
		qualquer=1;
		if((LastRound=fopen("UltimaRonda.txt", "w"))==NULL)
		{
			printf("Erro: não é possivel salvar a ultima ronda.\n");
			printf("Proxima ronda em 3.");
			sleep(1);
			printf("Proxima ronda em 2.");
			sleep(1);
			printf("Proxima ronda em 1.");
			sleep(1);
		}
		int xp;
		fprintf(LastRound, "%d\n", num);
		if(num==1)
		{
			ordenar(CartasJogador1);
			ordenar(CartasBot1);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			//fclose(LastRound);
		}
		if(num==2)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasBot1);
			ordenar(CartasBot2);
			ordenar(CartasBot3);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			fprintf(LastRound, "4:V;Bot2;%d:", SomaB2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot2[xp]);
			}	
			fprintf(LastRound, "5:V;Bot3;%d:", SomaB3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot3[xp]);
			}	
			//fclose(LastRound);
		}
		if(num==3)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasJogador3);
			ordenar(CartasBot1);
			ordenar(CartasBot2);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:R;%s;%d:", Nome3, Soma3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador3[xp]);
			}	
			fprintf(LastRound, "4:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			fprintf(LastRound, "5:V;Bot2;%d:", SomaB2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot2[xp]);
			}	
			//fclose(LastRound);	
		}
		if(num==4)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasJogador3);
			ordenar(CartasJogador4);
			ordenar(CartasBot1);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:R;%s;%d:", Nome3, Soma3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador3[xp]);
			}	
			fprintf(LastRound, "4:R;%s;%d:", Nome4, Soma4);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador4[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador4[xp]);
			}
			fprintf(LastRound, "5:V;Bot1;%d:", SomaB1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasBot1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasBot1[xp]);
			}	
			//fclose(LastRound);	
		}
		if(num==5)
		{
			ordenar(CartasJogador1);
			ordenar(CartasJogador2);
			ordenar(CartasJogador3);
			ordenar(CartasJogador4);
			ordenar(CartasJogador5);
			fprintf(LastRound, "1:R;%s;%d:", Nome1, Soma1);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador1[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador1[xp]);
			}	
			fprintf(LastRound, "2:R;%s;%d:", Nome2, Soma2);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador2[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador2[xp]);
			}	
			fprintf(LastRound, "3:R;%s;%d:", Nome3, Soma3);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador3[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador3[xp]);
			}	
			fprintf(LastRound, "4:R;%s;%d:", Nome4, Soma4);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador4[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador4[xp]);
			}
			fprintf(LastRound, "5:R;%s;%d:", Nome5, Soma5);
			for(xp=0; xp<7; xp++)
			{
				if(xp<6)
				fprintf(LastRound, "%d,", CartasJogador5[xp]);
				if(xp==6)
				fprintf(LastRound, "%d\n", CartasJogador5[xp]);
			}
			//fclose(LastRound);
		}
		fprintf(LastRound, "#0:M;");
		for(xp=0; xp<104; xp++)
		{
			if(Mesa[xp]>0 && Mesa[xp+1]>0)
			fprintf(LastRound, "%d,", Mesa[xp]);
			if(Mesa[xp]>0 && Mesa[xp+1]==0)
			fprintf(LastRound, "%d\n", Mesa[xp]);
		}	
		fclose(LastRound);
		}while(CartasJogador1[6]!=0 || CartasJogador1[5]!=0);
		contjog=0;
		}while(Soma1<66 && Soma2<66 && Soma3<66 && Soma4<66 && Soma5<66 && SomaB1<66 && SomaB2<66 && SomaB3<66);
		
		menor=Soma1;
		if(menor>Soma2 && num>1)
		menor=Soma2;
		if(menor>Soma3 && num>2)
		menor=Soma3;
		if(menor>Soma4 && num>3)
		menor=Soma4;
		if(menor>Soma5 && num==5)
		menor=Soma5;
		if(menor>SomaB1 && num>0 && num<5)
		menor=SomaB1;
		if(menor>SomaB2 && num>1 && num<4)
		menor=SomaB2;
		if(menor>SomaB3 && num==2)
		menor=SomaB3;
		if(controlar>0)
		{
			if((result=fopen("resultados.txt", "a"))==NULL)
			{
				printf("Erro: não é possivel abrir o ficheiro resultados.txt\n");
				exit(-1);
			}
		}
		else 
		{
			if((result=fopen("resultados.txt", "w"))==NULL)
			{
				printf("Erro: não é possivel abrir o ficheiro resultados.txt\n");
				exit(-1);
			}
			controlar++;
		}
		if(menor==Soma1)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome1);
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome1, ronda, Soma1);
		}
		else if(menor==Soma2)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome2);	
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome2, ronda, Soma2);
		}
		else if(menor==Soma3)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome3);	
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome3, ronda, Soma3);
		}
		else if(menor==Soma4)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome4);
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome4, ronda, Soma4);
		}
		else if(menor==Soma5)
		{
			drawRect(0,0,32,2);
			gotoxy(1,1);
			printf("O vencedor é o/a %s.\n", Nome5);
			fprintf(result, "O vencedor do %dº jogo foi o/a %s na ronda %d com %d cabeças de boi.\n", jogos, Nome5, ronda, Soma5);
		}
		else if(menor==SomaB1)
		{
			drawRect(0,0,22,2);
			gotoxy(1,1);
			printf("O vencedor é o Bot 1.\n");
			fprintf(result, "O vencedor do %dº jogo foi o Bot 1 na ronda %d com %d cabeças de boi.\n", jogos, ronda, SomaB1);
		}
		else if(menor==SomaB2)
		{
			drawRect(0,0,22,2);
			gotoxy(1,1);
			printf("O vencedor é o Bot 2.\n");
			fprintf(result, "O vencedor do %dº jogo foi o Bot 2 na ronda %d com %d cabeças de boi.\n", jogos, ronda, SomaB2);
		}
		else if(menor==SomaB3)
		{
			drawRect(0,0,22,2);
			gotoxy(1,1);
			printf("O vencedor é o Bot 3.\n");
			fprintf(result, "O vencedor  do %dº jogo foi o Bot 3 na ronda %d com %d cabeças de boi.\n", jogos, ronda, SomaB3);
		}
		fclose(result);
		drawRect(0,3,22,3);
		gotoxy(1,4);
		printf("Jogar outra vez? s/n\n");
		fflush(stdin);
		gotoxy(1,5);
		scanf("%c", &decisao);
		if(decisao=='S' || decisao=='s')
		jogos++;
		}while(decisao=='S' || decisao=='s');
	}
	else if(menu=='c' || menu=='C')
	{
		system("cls");
		drawRect(0,0,80,6);
		gotoxy(30,1);
		printf("Descrição do jogo.\n");
		gotoxy(1,3);
		printf("O 6 Nimmt! Ou Leva 6! é um jogo de cartas de 1 a 5 jogadores reais.\n");
		gotoxy(1,4);
		printf("Este jogo possui 104 cartas.\n");
		gotoxy(1,5);
		printf("O Jogo tem como objetivo ficar com o menor número possível de cabeças boi.\n");
		drawRect(0,7,80,10);
		gotoxy(1,8);
		printf("Cabeças de boi das cartas:\n");
		gotoxy(1,10);
		printf("Numero da carta");
		gotoxy(35,10);
		printf("Numero de cabeças de boi");
		gotoxy(64,10);
		printf("Numero de cartas");
		gotoxy(1,12);
		printf("55");
		gotoxy(1,13);
		printf("Multiplos de 11(exepto a 55)");
		gotoxy(1,14);
		printf("Multiplos de 10");
		gotoxy(1,15);
		printf("Multiplos de 5 que nao de 10");
		gotoxy(1,16);
		printf("Restantes");
		gotoxy(36,12);
		printf("7");
		gotoxy(36,13);
		printf("6");
		gotoxy(36,14);
		printf("3");
		gotoxy(36,15);
		printf("2");
		gotoxy(36,16);
		printf("1");
		gotoxy(65,12);
		printf("1");
		gotoxy(65,13);
		printf("8");
		gotoxy(65,14);
		printf("10");
		gotoxy(65,15);
		printf("9");
		gotoxy(65,16);
		printf("76");
		gotoxy(0,18);
		printf("Renicie o jogo.\n");
		system("pause");
	}
	else if(menu=='d' || menu=='D')
	{
		exit(0);
	}
	else
	{
		system("cls");
		drawRect(0,0,30,3);
		gotoxy(1,1);
		printf("Erro: Opção inválida");
		gotoxy(1,2);
		printf("Renicie o jogo\n");
	}
	return 0;
}//fim do main
