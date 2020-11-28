#include <iostream>
#include <vector>
#include<conio.h>
#include "Header.h" 



int main()
{
    std::cout << "Hello World!\n";
	if (move(3))
	{
		mainMenu();
	}
	else
	{
		return 0;
	}
	
}


void board()
{
	
    system("cls");
	for (int j = 0; j < X; j++)
	{
		std::cout << "_";
	}
	std::cout << std::endl;
	for (int i = 0; i < X; i++)
	{
		for (int k = 0; k < Y; k++)
		{

			
			
			
			if (i == xpos && k == ypos)
			{
				std::cout << "*" << "|";
			}
			else
			{
				std::cout << numbers[i][k] << "|"; // this is how you print a 2d vector
			}
		}
		std::cout << std::endl;
	}
	for (int j = 0; j < X; j++)
	{
		std::cout << "_";
	}
}

bool move(int attempts)
{
	for (int i = 0; i < attempts; i++)
	{
		xpos == 0;
		ypos == 0;
		myMoves = {};
		for (int k = 0; k < moves; k++)
		{
			board();
			char input;
			input = _getch();
			switch (input)
			{
			case 'w':
				xpos--;
				
				break;
			case 's':
				xpos++;
				
				break;
			case 'a':
				ypos--;
				
				break;
			case 'd':

				ypos++;
				
				break;
			default:
				break;
			}
			//resets position if you go outside the grid
			if (xpos < 0)
			{
				xpos = 0;
			}
			if (ypos < 0)
			{
				ypos = 0;
			}
			if (ypos >= Y)
			{
				ypos = Y - 1;
			}
			if (xpos >= X)
			{
				xpos = X - 1;
			}
			myMoves.push_back(input);
			
		}
		if (myMoves == password)
		{
			return true;
		}
	}
	return false;
}
void mainMenu()
{
	std::cout << "main menu";
}