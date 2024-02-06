#include <stdio.h>
#include "210102002071_Project2_Tic_Tac_Toe.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void sleep_ms(int milliseconds)
{
	clock_t start_time = clock();
	while (clock() < start_time + milliseconds);
}


void starting_animation(void)
{
	char str[] = "Welcome to Tic Tac Toe Game";
	int len = (int)strlen(str);
	for (int i = 0; i < 5; i++) {
		printf("\n");
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 3; j++) {
			printf("---------------------------------------------------------------------\n");
			printf("---------------------------------------------------------------------\n");
		}

		for (int j = 0; j <= i; j++) {
			printf("%c ", str[j]);
		}
		for (int j = 0; j < 3; j++)
			printf("-----------------------------\n");

		printf("\n");
		fflush(stdout);
		sleep_ms(50);
		system("clear");
	}
	for (int i = 0; i < 2; i++) {
		printf("\n");
	}
}

void winner_animation(int winner)
{
	char str1[] = "\nWINNER : PLAYER1.........................";
	char str2[] = "\nWINNER : PLAYER2.........................";
	char str3[] = "\nNo Winner,The Game Togetherness....................";
	char* str;
	if (winner == 1)
		str = str1;
	else if (winner == 2) 
		str = str2;
	else
		str = str3;
	

	int len = (int)strlen(str);
	for (int i = 0; i < 5; i++) {
		printf("\n");
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 3; j++) {
			printf("^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^'\n");
		}

		for (int j = 0; j <= i; j++) {
			printf("%c ", str[j]);
		}
		for (int j = 0; j < 3; j++)
			printf("^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^' ^--^'\n");
		printf("\n");
		fflush(stdout);
		sleep_ms(100);
		system("clear");
	}
	for (int i = 0; i < 2; i++) {
		printf("\n");
	}
	printf("the game finished....\n");
}

void initialize_Game_Board(char ptr[][3])
{
	ptr[0][0] = '0';
	ptr[0][1] = '1';
	ptr[0][2] = '2';
	ptr[1][0] = '3';
	ptr[1][1] = '4';
	ptr[1][2] = '5';
	ptr[2][0] = '6';
	ptr[2][1] = '7';
	ptr[2][2] = '8';
}


void show_Game_Board(char ptr[][3])
{
	if (ptr[0][0] == 'X' || ptr[0][0] == 'O')
		printf("  %c  ||", ptr[0][0]);
	else
		printf("     ||");


	if (ptr[0][1] == 'X' || ptr[0][1] == 'O')
		printf("  %c  ||", ptr[0][1]);
	else
		printf("     ||");


	if (ptr[0][2] == 'X' || ptr[0][2] == 'O')
		printf("  %c  ||", ptr[0][2]);
	else
		printf("     ||");

	printf("\n");

	if (ptr[1][0] == 'X' || ptr[1][0] == 'O')
		printf("  %c  ||", ptr[1][0]);
	else
		printf("     ||");


	if (ptr[1][1] == 'X' || ptr[1][1] == 'O')
		printf("  %c  ||", ptr[1][1]);
	else
		printf("     ||");


	if (ptr[1][2] == 'X' || ptr[1][2] == 'O')
		printf("  %c  ||", ptr[1][2]);
	else
		printf("     ||");
	printf("\n");


	if (ptr[2][0] == 'X' || ptr[2][0] == 'O')
		printf("  %c  ||", ptr[2][0]);
	else
		printf("     ||");


	if (ptr[2][1] == 'X' || ptr[2][1] == 'O')
		printf("  %c  ||", ptr[2][1]);
	else
		printf("     ||");


	if (ptr[2][2] == 'X' || ptr[2][2] == 'O')
		printf("  %c  ||", ptr[2][2]);
	else
		printf("     ||");
	printf("\n");

}

int update_Game_Board(char ptr[][3], int row, int column, char val)
{
	if (row < 4 && column < 4)
	{
		if (!isdigit(ptr[row - 1][column - 1]))
			return 0;
		ptr[row - 1][column - 1] = val;
	}
	else
		return 0;
	return 1;

}


int check_for_Win(char ptr[][3]) 
{
	int i, k;
	int cnt = 0;
	for (i = 0; i < 3; ++i)
	{
		if (ptr[i][0] == ptr[i][1] && ptr[i][1] == ptr[i][2])
		{
			if (ptr[i][0] == 'X')
				return 'X';  //  (winner)  // horizontal control
			else
				return 'O';  // (winner)
		}

		else if (ptr[0][i] == ptr[1][i] && ptr[1][i] == ptr[2][i])
		{
			if (ptr[i][0] == 'X')
				return 'X';  //  (winner)			// vertical control
			else
				return 'O';  //  (winner)
		}
		else if ((ptr[0][0] == ptr[1][1] && ptr[1][1] == ptr[2][2]) || (ptr[0][2] == ptr[1][1] && ptr[1][1] == ptr[2][0]))
			return 4;   // diagonal control
		else
		{
			for (i = 0; i < 3; ++i)
				for (k = 0; k < 3; ++k)
				{
					if (ptr[i][k] == 'X' || ptr[i][k] == 'O')
						cnt++;
				}
			if (cnt == 9)
				return 3; // (togetherness)
			cnt = 0;

		}
	}
	return 0; // nobody wins...

}

void start_Game(char ptr[][3], int player1, int player2)
{

	show_Game_Board(ptr);
	int row, column;
	while (1)
	{
		printf("enter row (for player1) : ");
		scanf("%d", &row);
		printf("enter column (for player1) : ");
		scanf("%d", &column);
		if (!(update_Game_Board(ptr, row, column, player1)))
		{
			printf("invalid enter, please try again...\n");
			continue;
		}
		show_Game_Board(ptr);
		if (check_for_Win(ptr) == 3)
		{
			winner_animation(3);
			break;
		}
		if (check_for_Win(ptr))
		{
			winner_animation(1);
			break;
		}
		printf("enter row (for player2) : ");
		scanf("%d", &row);
		printf("enter column (for player2) : ");
		scanf("%d", &column);
		if (!(update_Game_Board(ptr, row, column, player2)))
		{
			printf("invalid enter, please try again...\n");
			continue;
		}
		if (check_for_Win(ptr) == 3)
		{
			winner_animation(3);
			break;
		}
		show_Game_Board(ptr);
		if (check_for_Win(ptr))
		{
			winner_animation(2);
			break;
		}
	}





}
