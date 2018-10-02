//Naveen Krishna S
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char player1[20],player2[20],symbol,key[3][3]={'1','2','3','4','5','6','7','8','9'},tic[3][3]={'.','.','.','.','.','.','.','.','.'};
char cards[24][20]={"ELON MUSK","STEVE JOBS","SUNDHAR PICHAI","SATYA NADELLA","LINUS TORVALDS","ELON MUSK","ELON MUSK","LINUS TORVALDS","STEVE JOBS","NARAYANA MOORTHY","ELON MUSK","NARAYANA MOORTHY","LINUS TORVALDS","STEVE JOBS","SUNDHAR PICHAI","LINUS TORVALDS","SUNDHAR PICHAI","SATYA NADELLA","SATYA NADELLA","NARAYANA MOORTHY","STEVE JOBS","SUNDHAR PICHAI","SATYA NADELLA","NARAYANA MOORTHY"},open1,open2;
char rules1[1500]={"RULES:\n\t<1>\tPlayer 1 is X and Player 2 is O.\n\t<2>\tPlayers take turns by putting their marks in empty squares.\n\t<3>\tThe first player to get 3 of his or her marks in a row (up, down, across, or diagonally) is the winner.\n\t<4>\tWhen a player gets 3 marks together, the game is over.\n\t<5>\tIf no player has 3 marks in a row, the game ends in a tie. "},rules2[1500]={"RULES:\n\t<1>\tEach player gets to choose two cards.\n\t<2>\tIf the two cards contain the same names, the player gets a point, else the chance goes to the next player.\n\t<3>\tThe player who gets the highest points wins."};
int i,j,m,playerorder,choice,result,menu,attempt,pairselect1,pairselect2,memory[24],firstplayer,secondplayer,replay=0,game1=0,game2=0;
void replace(int repchoice);
void cardopen(int pairselect1, int pairselect2);
void print();
void order()
{
	if (playerorder%2==0)
	{
		system("color 6");
		if(menu==1)
		{
			printf("\n%s 's turn\nPosition your key:\t",player1);
			scanf("%d",&choice);
			symbol='x';
			replace(choice);
		}
		if(menu==2)
		{
			printf("\n%s open two cards:\n",player1);
			scanf("%d%d",&pairselect1,&pairselect2);
			while((pairselect1>24)||(pairselect2>24)||(pairselect1==pairselect2))
			{
				printf("\nEnter numbers only less than 24\t");
				scanf("%d%d",&pairselect1,&pairselect2);
			}
			pairselect1--;
			pairselect2--;
			cardopen(pairselect1,pairselect2);
		}
	}
	else
	{
		system("color 5");
		if(menu==1)
		{
			printf("\n%s 's turn\nPosition your key:\t",player2);
			scanf("%d",&choice);
			symbol='o';
			replace(choice);
		}
		if(menu==2)
		{
			printf("\n%s open two cards:\n",player2);
			scanf("%d%d",&pairselect1,&pairselect2);
			while((pairselect1>24)||(pairselect2>24))
			{
				printf("\nEnter numbers only less than 24\t");
				scanf("%d%d",&pairselect1,&pairselect2);
			}
			pairselect1--;
			pairselect2--;
			cardopen(pairselect1,pairselect2);
		}
	}
}
void cardopen(pairselect1,pairselect2)
{
	if((memory[pairselect1]!=0)&&(memory[pairselect2]!=0))
	{
		music('c');
		printf("Card labelled %d is \"%s\"\nCard labelled %d is \"%s\"",pairselect1+1,cards[pairselect1],pairselect2+1,cards[pairselect2]);
		sleep(3);
		system("CLS");
		if((strcmp(cards[pairselect1],cards[pairselect2])==0)&&(memory[pairselect1]!=0)&&(memory[pairselect1]!=0))
		{
			system("color 72");
			music('c');
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMatch");
			sleep(2);
			system("CLS");
			memory[pairselect1]=0;
			memory[pairselect2]=0;
			if(playerorder%2==0)
				firstplayer++;
			else
				secondplayer++;
		}
		else
		{
			system("color 74");
			music('b');
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tNo match!");
			sleep(2);
			system("CLS");
			playerorder++;
			print();
			order();
		}
	}
	else
	{
		music('b');
		printf("\nSelect only availale cards:\t");
		order();
	}
}
void replace(int repchoice)
{
		switch(repchoice)
		{
			case 1:
					if(tic[0][0]=='.')
					{
						music('c');
						tic[0][0]=symbol;
					}
					else
					{
						music('b');
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
				break;
			case 2:
					if(tic[0][1]=='.')
					{
						music('c');
						tic[0][1]=symbol;
					}
					else
					{
						music('b');
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 3:
					if(tic[0][2]=='.')
					{
						music('c');
						tic[0][2]=symbol;
					}
					else
					{
						music('b');
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 4:
					if(tic[1][0]=='.')
					{
						music('c');
						tic[1][0]=symbol;
					}
					else
					{
						music('b');
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 5:
					if(tic[1][1]=='.')
					{
						music('c');
						tic[1][1]=symbol;
					}
					else
					{
						music('b');
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 6:
				if(tic[1][2]=='.')
					{
						music('c');
						tic[1][2]=symbol;
					}
				else
				{
					music('b');
					printf("\nPosition already occupied!\n Enter another position which is free:\t");
					order();
				}
				break;
			case 7:
				if(tic[2][0]=='.')
					{
						music('c');
						tic[2][0]=symbol;
					}
				else
				{
					music('b');
					printf("\nPosition already occupied!\n Enter another position which is free:\t");
					order();
				}
				break;
			case 8:
				if(tic[2][1]=='.')
					{
						music('c');
						tic[2][1]=symbol;
					}
				else
				{
					music('b');
					printf("\nPosition already occupied!\n Enter another position which is free:\t");
					order();
				}
				break;
			case 9:
				if(tic[2][2]=='.')
					{
						music('c');
						tic[2][2]=symbol;
					}
				else
				{
					music('b');
					printf("\nPosition already occupied!\nEnter another position which is free:\t");
					order();
				}
				break;
			default:
				printf("\nEnter the mapping number of only availale places!\n");		
		}
		if(repchoice>9)
			order();
}
int check()
{
	//vertical
	for(j=0;j<3;j++)
	{
		if((tic[0][j]==tic[1][j])&&(tic[1][j]==tic[2][j]))
		{
			if((tic[0][j]=='x')&&(tic[0][j]!='.'))
			{
				system("color 6");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player1);
				music('a');
				sleep(4);
				system("CLS");
				return 1;
			}
			if((tic[0][j]=='o')&&(tic[0][j]!='.'))
			{
				system("color 5");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player2);
				music('a');
				sleep(4);
				system("CLS");
				return 1;
			}
		}
	}
	//horizontal
	for(i=0;i<3;i++)
	{
		if((tic[i][0]==tic[i][1])&&(tic[i][1]==tic[i][2]))
		{
			if((tic[i][0]=='x')&&(tic[i][0]!='.'))
			{
				system("color 6");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player1);
				music('a');
				sleep(4);
				system("CLS");
				return 1;
			}
			if((tic[i][0]=='o')&&(tic[i][0]!='.'))
			{
				system("color 5");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player2);
				music('a');
				sleep(4);
				system("CLS");
				return 1;
			}
		}
	}
	//diagonal
	if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2]))||((tic[0][2]==tic[1][1])&&(tic[1][1]==tic[2][0])))
	{
			if((tic[1][1]=='x')&&(tic[1][1]!='.'))
			{
				system("color 20");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player1);
				music('a');
				sleep(4);
				system("CLS");
				return 1;
			}
			if((tic[1][1]=='o')&&(tic[1][1]!='.'))
			{
				system("color 40");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player2);
				music('a');
				sleep(4);
				system("CLS");
				return 1;
			}
	}
}
void print()
{
	if(menu==1)
	{
		system("CLS");
		for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					printf("%c ",key[i][j]);
				}
				printf("\n");
			}
		printf("\n\n");
		for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					printf("\t%c\t",tic[i][j]);
				}
				printf("\n\n\n");
			}
	}
	if(menu==2)
	{
		printf("\n\n");
		for(i=0;i<24;i++)
		{
			if(memory[i]==0)
			{
				printf("\t\t");
			}
			else
			printf("\t%d\t",memory[i]);
			if((i+1)%4==0)
			printf("\n\n");
		}
	}
}
main()
{			
	printf("\nPlayer 1... Enter your name:\t");
	fflush(stdin);
	gets(player1);
	printf("\nPlayer 2... Enter your name:\t");
	fflush(stdin);
	gets(player2);
	music('t');
	do
	{
		printf("\t<1>\tTIC TAC TOE\n\t<2>\tMEMORY GAME\nYour choice:\t");
		scanf("%d",&menu);
		music('w');
		system("CLS");
		for(i=0;i<30;i++)
		{
			if(i%2==0)
				system("color 60");
			else
				system("color 57");
			system("CLS");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s\tVS\t%s",strupr(player1),strupr(player2));
			usleep(10);
		}
		switch(menu)
		{
			case 1:
				for(i=0;i<3;i++)
					for(j=0;j<3;j++)
						tic[i][j]='.';
				result=0;
				system("CLS");
				system("color 70");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tTIC TAC TOE");
				sleep(2);
				system("CLS");
				if(game1==0)
				{
					for(i=0;i<strlen(rules1);i++)
					{
						printf("%c",rules1[i]);
						usleep(150000);
					}
				}
				for(playerorder=0;(playerorder<9)&&(result!=1);playerorder++)
				{
					print();
					if(result!=1)
					{
						order();
						result=check();
					}
				}
				if(result!=1)
				{
					print();
					system("CLS");
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tdraw");
					sleep(4);
					system("CLS");
				}
				game1=1;
				break;
			case 2:
				firstplayer=0;
				secondplayer=0;
				system("CLS");
				system("color 70");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMEMORY GAME");
				sleep(2);
				system("CLS");
				if(game2==0)
				{
					for(i=0;i<strlen(rules2);i++)
					{
						printf("%c",rules2[i]);
						usleep(150000);
					}
				}
				game2=1;
				system("CLS");
				for(i=1;i<=24;i++)
					memory[i-1]=i;
				for(playerorder=0;(firstplayer+secondplayer)<12;playerorder++)
				{
					print();
					order();
				}
				system("CLS");
				if(firstplayer>secondplayer)
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\npoints-----%d\t%d",player1,firstplayer,secondplayer);
					music('a');
				}
				else if(firstplayer<secondplayer)
				{
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\npoints-----%d\t%d",player2,firstplayer,secondplayer);
					music('a');
				}
				else 
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tDraw");
				sleep(4);			
		}
		printf("\nPress 1 to continue the fun\t");
		scanf("%d",&replay);
	}while(replay==1);
}
