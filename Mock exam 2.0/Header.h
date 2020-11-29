#pragma once
void board();
bool move(int attempts);
void mainMenu();
void task1();
void task2();
void task3();
void task4();
void task5();
int moves = 4;


int X = 3;
int Y = 3;
int xpos = 0;
int ypos = 0;

int dice1;
int dice2;
int dice3;
int dice4;
int dice5;
int dice6;


std::vector<std::vector<int>>numbers{ { 1, 2, 3}, { 4, 5, 6}, {7, 8, 9 } };

std::vector<char> password{ 's', 'd', 'w', 'd' };
std::vector<char> myMoves{};
