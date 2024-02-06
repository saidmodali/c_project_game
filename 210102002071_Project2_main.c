#include "210102002071_Project2_Tic_Tac_Toe.h"
#include <stdio.h>
#include <ctype.h>

/*

	This code written by Muhammed Said Modali
	this code is a game that is tic tac to game.
	firstly, the code starts starting animation additionally (I have search it from internet.)
	and asks a character (x or o) to user. If player1 choose x then other player automatically has o.
	If vertical, horizontal or diagonal occurs, the player wins.If nothing occurs then togetherness, and the game finished.
	Additionally, the animation when the game over is just like starting animation.
	additional functions : void sleep_ms(int milliseconds), void starting_animation(void), void winner_animation(int winner).



*/


int main()
{

	starting_animation();
	char player1, player2;
	char xox_board[3][3];
	initialize_Game_Board(xox_board);
	printf("please enter x or o (for player1) : \n");
	scanf("%c", &player1);
	player1 = toupper(player1);
	while (1)
	{
		if (player1 == 'X')
		{
			player2 = 'O';
			printf("player2 has O automaticaly...\n");
			break;
		}
		else if (player1 == 'O')
		{
			player2 = 'X';
			printf("player2 has X automaticaly...\n");
			break;
		}
		else
		{
			printf("wrong enter, please enter valid (x or o) : ");
			scanf("%c", &player1);
			player1 = toupper(player1);
			continue;
		}

	}
	start_Game(xox_board, player1, player2);
}