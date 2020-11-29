#include <iostream>
#include <vector>
#include<conio.h>
#include<time.h>
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
		xpos = 0;
		ypos = 0;
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
			std::cout << "\nSucces!\n";
			system("pause");
			return true;
		}

	}
	return false;
}
void mainMenu()
{
	system("cls");
	std::cout << "Main Menu\n";
	std::cout << "Welcome to the main menu please choose a task. \n";
	std::vector<std::string> menu{ "task1", "task2", "task3", "task4", "task5" };
	for (int i = 0; i < menu.size(); i++)
	{
		std::cout << i + 1 << ". " << menu[i] << std::endl;
	}
	char input;
	input = _getch();
	switch (input)
	{
	case '1':
		task1();
		break;
	case '2':
		task2();
		break;
	case '3':
		task3();
		break;
	case '4':
		task4();
		break;
	case '5':
		task5();
		break;
	default:
		std::cout << "please choose a valid option\n";
		mainMenu();
		break;
	}
}

void task1()
{
	system("cls");
	std::cout << "this tasks throws dice(1-6) 2000 times, it will count how many times it got each number and display them \n ";
	std::cout << "press any key to throw the dice \n";
	_getch();

	for (int i = 0; i < 2000; i++)
	{
		int dice;

		dice = rand() % 6 + 1;
		if (dice == 1)
		{
			dice1 += 1;
		}
		else if (dice == 2)
		{
			dice2 += 1;
		}
		else if (dice == 3)
		{
			dice3 += 1;
		}
		else if (dice == 4)
		{
			dice4 += 1;
		}
		else if (dice == 5)
		{
			dice5 += 1;
		}
		else if (dice == 6)
		{
			dice6 += 1;
		}

	}
	std::cout << "1: " << dice1 << " Times.\n\n";
	std::cout << "2: " << dice2 << " Times.\n\n";
	std::cout << "3: " << dice3 << " Times.\n\n";
	std::cout << "4: " << dice4 << " Times.\n\n";
	std::cout << "5: " << dice5 << " Times.\n\n";
	std::cout << "6: " << dice6 << " Times.\n\n";

}

class Classvalue
{
	char name;
	int value;
	int place;
};
void task2()
{

}

void task3()
{
	//declare grid:
	const int Xaxis = 25;
	const int Yaxis = 15;
	int xpos = 1;
	int ypos = 1;

	char grid[Yaxis][Xaxis];

	bool moving = true;

	// fiil the grid with random "#"
	for (int i = 0; i < Yaxis; i++)
	{
		for (int k = 0; k < Xaxis; k++) //fills border with "#"
		{
			if (i == 0 || i == Yaxis - 1)
			{
				grid[i][k] = '#';
			}
			else if (k == 0 || k == Xaxis - 1)
			{
				grid[i][k] = '#';
			}
			else if ((rand() % 20) < 2)//populates the grid with random "#"
			{
				grid[i][k] = '#';
			}
			else
			{
				grid[i][k] = ' ';
			}

		}
	}
	while (moving)
	{
		system("cls");
		std::cout << "controls are WASD" << std::endl;
		for (int i = 0; i < Yaxis; i++)
		{
			for (int k = 0; k < Xaxis; k++)
			{
				if (i == ypos && k == xpos) //player
				{
					std::cout << 'O';
				}
				else
				{
					std::cout << grid[i][k];
				}
			}
			std::cout << std::endl;
		}
		char input;
		input = _getch();
		switch (input) //the if statements checks if theres and ' ' space to each side, if yes you can move.
		{
		case 'w':
			if (grid[ypos - 1][xpos] == ' ')
			{
				ypos -= 1;
			}

			break;
		case 's':
			if (grid[ypos + 1][xpos] == ' ')
			{
				ypos += 1;
			}
			break;

		case 'a':
			if (grid[ypos][xpos - 1] == ' ')
			{
				xpos -= 1;
			}
			break;

		case 'd':
			if (grid[ypos][xpos + 1] == ' ')
			{
				xpos += 1;
			}
			break;
		default:
			std::cout << "invalid input";
			break;

		}
		
	}
}

void task4()
{
	int points = 0;

	//declare grid

	const int Xaxis = 25;
	const int Yaxis = 15;
	int xpos = 1;
	int ypos = 1;

	char grid[Yaxis][Xaxis];

	bool moving = true;


	//makes borders and wall out of '#'
	for (int i = 0; i < Yaxis; i++)
	{
		for (int k = 0; k < Xaxis; k++) //fills border with "#"
		{
			if (i == 0 || i == Yaxis - 1)
			{
				grid[i][k] = '#';
			}
			else if (k == 0 || k == Xaxis - 1)
			{
				grid[i][k] = '#';
			}
			else if ((rand() % 20) < 2)//populates the grid with random "#"
			{
				grid[i][k] = '#';
			}
			else if ((rand() % 20) < 5)
			{
				grid[i][k] = '-'; // populates the grid with random points
			}
			else
			{
				grid[i][k] = ' ';
			}

		}
	}
	
	while (moving)
	{
		system("cls");
		std::cout << "controls are WASD" << std::endl;
		for (int i = 0; i < Yaxis; i++)
		{
			for (int k = 0; k < Xaxis; k++)
			{
				if (i == ypos && k == xpos) //player
				{
					std::cout << 'O';
				}
				else
				{
					std::cout << grid[i][k];
				}
			}
			std::cout << std::endl;
		}
		std::cout << "\npoints: " << points;
		char input;
		input = _getch();
		switch (input) //the if statements checks if theres a '#', if it is it cant move there.
		case 'w':
		{
			if (grid[ypos - 1][xpos] != '#')
			{
				ypos -= 1;
			}

			break;
		case 's':
			if (grid[ypos + 1][xpos] != '#')
			{
				ypos += 1;
			}
			break;

		case 'a':
			if (grid[ypos][xpos - 1] != '#')
			{
				xpos -= 1;
			}
			break;

		case 'd':
			if (grid[ypos][xpos + 1] != '#')
			{
				xpos += 1;
			}
			break;
		default:
			std::cout << "invalid input";
			break;

		}
		//checks if the player/"O" is on a "-" then deletets the "-"
		if (grid[ypos][xpos] == '-')
		{
			points += 1;
			grid[ypos][xpos] = ' '; //replaces "-" with " " when player is on said grid
		}

	}
	
}

void task5()
{
	std::cout << "goodbye" << std::exit;
}