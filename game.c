/*Naveen Krishna S */
//declaration of header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//declaration of variables and user defined functions
/*
 player1 and player2 stores the name of the players
 symbol stores x or o in the tic tac toe based on the players turn
 key is just to display the mapping aid in tic tac toe
 tic is the actual game board
 cards is the array which stores the names which will be behind those numbers
 open1 and open2 stores the option of card that the plpayer chooses
 rules1 and rules2 are to display the rules of the game
 i,j,m are looping variables
 playerorder swaps the order of the players
 choice is to read thhe option that the player eneters in tic tac toe
 result will store a value which says whether the game is over or not
 menu is to select which game to play
 pairselect1 and pairselect2 are arguements for the function cardopen()
 the array memory keeps track of all the cards that the user has already opened
 */
char player1[20],player2[20],symbol,key[3][3]={'1','2','3','4','5','6','7','8','9'},tic[3][3]={'.','.','.','.','.','.','.','.','.'};
char cards[24][20]={"ELON MUSK","STEVE JOBS","SUNDHAR PICHAI","SATYA NADELLA","LINUS TORVALDS","ELON MUSK","ELON MUSK","LINUS TORVALDS","STEVE JOBS","NARAYANA MOORTHY","ELON MUSK","NARAYANA MOORTHY","LINUS TORVALDS","STEVE JOBS","SUNDHAR PICHAI","LINUS TORVALDS","SUNDHAR PICHAI","SATYA NADELLA","SATYA NADELLA","NARAYANA MOORTHY","STEVE JOBS","SUNDHAR PICHAI","SATYA NADELLA","NARAYANA MOORTHY"},open1,open2;
char rules1[500]={"RULES:\n\t<1>\tPlayer 1 is X and Player 2 is O.\n\t<2>\tPlayers take turns by putting their marks in empty places.\n\t<3>\tThe first player to get 3 of his or her marks in a row (up, down, across, or diagonally) is the winner.\n\t<4>\tWhen a player gets 3 marks together, the game is over.\n\t<5>\tIf no player has 3 marks in a row, the game ends in a tie. "},rules2[500]={"RULES:\n\t<1>\tEach player gets to choose two cards.\n\t<2>\tIf the two cards contain the same names the player gets a point, else the the chance goes to the next player.\n\t<3>\tThe player who gets the highest points wins."};
int i,j,m,playerorder,choice,result=0,menu,pairselect1,pairselect2,memory[24],firstplayer=0,secondplayer=0,replay;
void replace(int repchoice);
void cardopen(int pairselect1, int pairselect2);
void print();
//order() function is to get the user input for both the games. The position in tic tac toe and the cards in memory game
void order()
{
	//the suitable if bolck will be executed based on the turn who needs to play
	if (playerorder%2==0)
	{
		system("color 6");
		//this if else if works upon the game that user enters
		if(menu==1)
		{
			printf("\n%s 's turn\nPosition your key:\t",player1);
			scanf("%d",&choice);
			symbol='x';
			replace(choice);
		}
		else if(menu==2)
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
		else if(menu==2)
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
//cardopen() function is for the memory game which opens two cards. and also the validation is also done here
void cardopen(pairselect1,pairselect2)
{
	//memory array remembers of all the cards that both the players have entered
	if((memory[pairselect1]!=0)&&(memory[pairselect2]!=0))
	{
		printf("Card labelled %d is \"%s\"\nCard labelled %d is \"%s\"",pairselect1+1,cards[pairselect1],pairselect2+1,cards[pairselect2]);
		sleep(3);
		system("CLS");
		//it compares the opened cards, and if both are same, it will assign the value 0 to that particular card
		if((strcmp(cards[pairselect1],cards[pairselect2])==0)&&(memory[pairselect1]!=0)&&(memory[pairselect1]!=0))
		{
			system("color 72");
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
		printf("\nSelect only availale cards:\t");
		order();
	}
}
//replace() function is for the tic tac toe game, where it validates and prints the symbol based on the player's turn
void replace(int repchoice)
{
	//switch case switches the contronl based on the player's choice of position
		switch(repchoice)
		{
			case 1:
					if(tic[0][0]=='.')
					{
						tic[0][0]=symbol;
					}
					else
					{
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
				break;
			case 2:
					if(tic[0][1]=='.')
						tic[0][1]=symbol;
					else
					{
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 3:
					if(tic[0][2]=='.')
						tic[0][2]=symbol;
					else
					{
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 4:
					if(tic[1][0]=='.')
						tic[1][0]=symbol;
					else
					{
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 5:
					if(tic[1][1]=='.')
						tic[1][1]=symbol;
					else
					{
						printf("\nPosition already occupied!\n Enter another position which is free:\t");
						order();
					}
					break;
			case 6:
				if(tic[1][2]=='.')
					tic[1][2]=symbol;
				else
				{
					printf("\nPosition already occupied!\n Enter another position which is free:\t");
					order();
				}
				break;
			case 7:
				if(tic[2][0]=='.')
					tic[2][0]=symbol;
				else
				{
					printf("\nPosition already occupied!\n Enter another position which is free:\t");
					order();
				}
				break;
			case 8:
				if(tic[2][1]=='.')
					tic[2][1]=symbol;
				else
				{
					printf("\nPosition already occupied!\n Enter another position which is free:\t");
					order();
				}
				break;
			case 9:
				if(tic[2][2]=='.')
					tic[2][2]=symbol;
				else
				{
					printf("\nPosition already occupied!\nEnter another position which is free:\t");
					order();
				}
				break;
			default:
				printf("\nEnter the mapping number of only availale places!\n");
				order();		
		}
}
//this function is the most important funtion for the tic tac toe game where it checks for any 3 consecutive symbols
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
				sleep(4);
				system("CLS");
				return 1;
			}
			if((tic[0][j]=='o')&&(tic[0][j]!='.'))
			{
				system("color 5");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player2);
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
				sleep(4);
				system("CLS");
				return 1;
			}
			if((tic[i][0]=='o')&&(tic[i][0]!='.'))
			{
				system("color 5");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player2);
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
				sleep(4);
				system("CLS");
				return 1;
			}
			if((tic[1][1]=='o')&&(tic[1][1]!='.'))
			{
				system("color 40");
				system("CLS");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\n",player2);
				sleep(4);
				system("CLS");
				return 1;
			}
	}
}
//the print() takes care of all the printing process of both the games
void print()
{
	if(menu==1)
	{
		system("CLS");
		//this loop prints the small mapping aid that appears on the top of the playboard everytime
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
	//this is for memory game
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
	system("CLS");
	printf("\nPlayer 1... Enter your name:\t");
	fflush(stdin);
	gets(player1);
	printf("\nPlayer 2... Enter your name:\t");
	fflush(stdin);
	gets(player2);
	do
	{
		printf("\t<1>\tTIC TAC TOE\n\t<2>\tMEMORY GAME\nYour choice:\t");
		scanf("%d",&menu);
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
		//switch menu is to choose between the two games
		switch(menu)
		{
		case 1:
			system("CLS");
			system("color 70");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tTIC TAC TOE");
			sleep(2);
			system("CLS");
			for(i=0;i<strlen(rules1);i++)
			{
				printf("%c",rules1[i]);
				usleep(125000);
			}
			sleep(4);
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
			break;
		case 2:
			system("CLS");
			system("color 70");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tMEMORY GAME");
			sleep(2);
			system("CLS");
			for(i=0;i<strlen(rules2);i++)
			{
				printf("%c",rules2[i]);
				usleep(125000);
			}
			sleep(4);
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
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\npoints-----%d\t%d",player1,firstplayer,secondplayer);
			else if(firstplayer<secondplayer)
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t%s wins\npoints-----%d\t%d",player2,firstplayer,secondplayer);
			else 
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tDraw");
			sleep(4);			
		}
		printf("\nPress 1 to continue the fun\t");
		scanf("%d",&replay);
	}while(replay==1);
}
