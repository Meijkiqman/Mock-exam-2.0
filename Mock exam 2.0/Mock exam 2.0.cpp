#include <iostream>
#include <vector>
#include<conio.h>
#include "Header.h" 



int main()
{
    std::cout << "Hello World!\n";
	move();
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

			if (k == 0)
			{
				std::cout << "|";
			}
			
			
			if (i == xpos && k == ypos)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << numbers[i][k]; // this is how you print a 2d vector
			}
		}
		std::cout << std::endl;
	}
	for (int j = 0; j < X; j++)
	{
		std::cout << "_";
	}
}

void move()
{
	char input;
	board();
	while (attempts > 0)
	{
		moves = 4;
		for (int M = 0; M < moves; M++)
		{
			{


				do
				{
					input = _getch();

					switch (input)
					{
					case 'w':

						xpos--;
						moves--;

						break;

					case 's':

						xpos++;
						moves--;

						break;

					case 'd':

						ypos++;
						moves--;
						break;

					case 'a':

						ypos--;
						moves--;

						break;

					default:
						break;

					}
					if (ypos >= Y)
					{

						ypos = 0;

					}
					if (ypos < 0)
					{
						ypos = Y - 1;
					}
					if (xpos >= X)
					{
						xpos = 0;
					}
					if (xpos < 0)
					{
						xpos = X - 1;
					}
					board();

				} while (true && moves != 0);
			}
		}
		
		system("cls");
		std::cout << "failed!, reseting board... \n";
		ypos == 0;
		xpos == 0;
		system("pause");
		
		attempts--;
	}
	if (attempts == 0)
	{
		std::cout << "\n failed to enter password, goodbye!:" << std::exit;
	}
	
}