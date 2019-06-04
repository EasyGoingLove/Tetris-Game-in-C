#include <stdio.h>
#include <curses.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#define true 1 
#define false 0
#define Rows 20
#define Colms 10


unsigned char field[Rows][Colms] = { 0 };
int Score = 0;
int  i, j, end = 0;

//Blocks 
unsigned char I[4][4] = { 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 };
unsigned char J[4][4] = { 0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0 };
unsigned char L[4][4] = { 0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0 };
unsigned char O[4][4] = { 0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0 };
unsigned char S[4][4] = { 0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0 };
unsigned char T[4][4] = { 0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0 };
unsigned char Z[4][4] = { 0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0 };
// Blocks

void Menu(void);
void Field(void);
void GameOn(void);
void GameOff(void);
void Random_Blocks(void);
void Field(void);
void Gravity(void);
void RowCompletion_andScore(void);
void Control(void);


int main()
{
	Menu();
	return 0;
}

void Menu(void)
{
	char choice;
	while (true)
	{
		system("cls");
		printf("Welcome to 1984 <-------->Tetris Game\n\n");
		printf("\t To START Press [Z] \n\n");
		printf("\t For Party [X]  \n\n");
		printf("\t To Exit Press [C]  \n\n");


		choice = _getch();

		switch (choice)
		{
		case 'z': system("cls"); GameOn();
			break;
		case 'x': printf("igrata ne e gotowa brat\n\n");
			break;
		case 'c': printf("Goodbye\n"); return false;
			break;
		default: printf("Wrong Choice. Enter again\n"); Sleep(2000);
			break;
		}

	}

}

void GameOff(void)
{
	for (i = 0; i < Rows; i++)
	{
		for (j = 0; j < Colms; j++)
		{
			field[i][j] = 0;
		}
	}
	Score = 0;
}

void GameOn(void)
{
	initscr();
	int p = 0;
	Random_Blocks();

	do
	{
		clear();
		Field();
		Control();
		Gravity();
		RowCompletion_andScore();
		refresh();
		Sleep(500);
	} while (end == 0);

	clear();
	refresh();
	end = 0;
	GameOff();
	endwin();
	printf("\n\n\n\n\t Game Over my boi <3");
	Sleep(2000);
	system("cls");

}

void Random_Blocks(void) {

	int p, i, j;
	srand(time(NULL));
	p = rand() % 7;

	if (p == 0) {

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 2) {
					memcpy(&field[i][j + 3], &I[i][j], 1);
				}
				else if (field[i][j + 3] != 2|| field[i][j + 3] != 0) { end++; }
			}
		}

	}
	if (p == 1) {
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 2) {
					memcpy(&field[i][j + 3], &J[i][j], 1);
				}
				else if (field[i][j + 3] != 2 || field[i][j + 3] != 0) { end++; }
			}
		}
	}
	if (p == 2) {
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 2) {
					memcpy(&field[i][j + 3], &L[i][j], 1);
				}
				else if (field[i][j + 3] != 2 || field[i][j + 3] != 0) { end++; }
			}
		}
	}
	if (p == 3) {
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 2) {
					memcpy(&field[i][j + 3], &O[i][j], 1);
				}
				else if (field[i][j + 3] != 2 || field[i][j + 3] != 0) { end++; }
			}
		}
	}
	if (p == 4) {
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 1) {
					memcpy(&field[i][j + 3], &S[i][j], 1);
				}
				else if (field[i][j + 3] != 2 || field[i][j + 3] != 0) { end++; }
			}
		}
	}
	if (p == 5) {
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 2) {
					memcpy(&field[i][j + 3], &T[i][j], 1);
				}
				else if (field[i][j + 3] != 2 || field[i][j + 3] != 0) { end++; }
			}
		}
	}
	if (p == 6) {
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (field[i][j + 3] != 2)
				{
					memcpy(&field[i][j + 3], &Z[i][j], 1);
				}
				else if (field[i][j + 3] != 2 || field[i][j + 3] != 0) { end++; }
			}
		}
	}

}

void Field(void)
{
	int i, j;
	for (i = 0; i < Rows; i++)
	{
		printw("\t<|>");
		for (j = 0; j < Colms; j++)
		{

			if (field[i][j] == 0)
			{
				printw("%c ", '.');
			}
			else { printw("%c ", 'O'); }
			if (j == 9)
			{
				printw("<|>");
				printw("\n");
			}
		}
	}
	printw("\t");
	for (i = 0; i < 9; i++)
	{
		printw("<=>");
	}printw("\n");
}

void Gravity(void)
{
	int z, v;

	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < Colms; j++)
		{

			if (field[i][j] == 1)
			{
				if (i != 19 && field[i + 1][j] != 1 && field[i + 1][j] != 2)
				{
					field[i][j] = 0;
					field[i + 1][j] = 1;
				}
				else
				{
					for (z = 0; z < Rows; z++)
					{
						for (v = 0; v < Colms; v++)
						{
							if (field[z][v] == 1)
							{
								field[z][v] = 2;
							}

						}

					}
					Random_Blocks();
				}

			}

		}
	}




}

void RowCompletion_andScore(void)
{
	int i, j, y, boom = 0;
	int z, v;
	for (i = 0; i < Rows; i++)
	{
		y = 0;
		for (j = 0; j < Colms; j++)
		{
			y += field[i][j];
		}
		if (y == 2 * Colms)
		{
			boom++;
			for (z = i; z >= 1; z--)
				for (v = 0; v < Colms; v++)
					field[z][v] = field[z - 1][v];
			for (v = 0; v < Colms; v++)
				field[z][v] = 0;

			Score += 100;
		}
	}
	printw("\n\tYour Score is | %d |", Score);
}

void Control(void)
{
	char c;
	int i, j;

	int z, v, d = 0;
	int indexOf_Z = 0, Control_index = 3;

	int breaker=0;

	if (_kbhit())
	{
		c = _getch();
		switch (c)
		{
		case 'a':
			for (i = 0; i < Rows; i++)
			{
				if (breaker != 0) { break; }
				for (j = 0; j < Colms; j++)
				{
					if (field[i][j] == 1)
					{
						if (field[i][j - 1] == 0 && j - 1 != -1 && field[i][j - 1] != 2)
						{
							field[i][j - 1] = 1;
							field[i][j] = 0;
						}
						else { breaker++; }
					}
				}
			}
			break;
		case 'd':
			for (i = 0; i < Rows; i++)
			{
				if (breaker != 0) { break; }
				for (j = 9; j >= 0; j--)
				{
					if (field[i][j] == 1)
					{
						if (field[i][j + 1] == 0 && j + 1 != 10 && field[i][j + 1] != 2)
						{
								field[i][j + 1] = 1;
								field[i][j] = 0;
						}
						else { breaker++; }
					}
				}
			}
			break;
		case 'w':

			for (i = 0; i < Rows; i++)
			{
				for (j = 0; j < Colms; j++)
				{
					if (field[i][j] == 1)
					{
						if (d != 1) {
							for (z = i; z < i + 4; z++)
							{
								for (v = j - 1; v < j + 3; v++)
								{
									if (field[z][v] == 1)
									{
										field[z + indexOf_Z - 3][19 - z] = field[z][v];
										field[z + indexOf_Z - 3][19 - z] = 3;
									}
									if (indexOf_Z == Control_index) { indexOf_Z = Control_index - 4; Control_index -= 1; }
									else { indexOf_Z += 1; }
								}
							}d++;
						}
					}

				}

			}
			for (i = 0; i < Rows; i++)
			{
				for (j = 0; j < Colms; j++)
				{
					if (field[i][j] == 1)
					{
						field[i][j] = 0;
					}
					else if (field[i][j] == 3)
					{
						field[i][j] = 1;
					}
				}

			}
			break;
		case 's':
			for (i = 19; i >= 0; i--)
			{
				for (j = 0; j < Colms; j++)
				{
					if (field[i][j] == 1 && field[i + 1][j] != 2 && field[i + 1][j] != 1 && i != 19)
					{
						field[i][j] = 0;
						field[i + 1][j] = 1;
					}
				}

			}
			break;
		}
	}
}


