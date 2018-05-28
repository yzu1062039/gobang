// five.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int M = 10;//row
const int N = 10;//column
int board[M][N];
int save[M][N];
//---------------------
//    0: empty
//    1: player1
//    2: player2
//---------------------
void init()
{
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			board[i][j] = 0;
}
void write()
{
	ofstream file;
	file.open("board.txt");
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			file << board[i][j] << endl;
	file.close();
}
void read()
{
	ifstream file;
	file.open("board.txt");
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			file >> board[i][j];
	file.close();
}
void show()
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			cout << board[i][j];
		cout << endl;
	}
}
bool set(int i, int j, int m)
{
	if (0 == board[i][j])
	{
		board[i][j] = m;
		return true;
	}
	else
		return false;
}
void play(int m)
{
	int x = 4;
	int y = 4;
	int i, j, max = save[x][y];
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			save[i][j] = board[i][j];
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++) {
			//我方4顆
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j + 2] == m && save[i][j + 3] == m && save[i][j + 4] == m) || (save[i][j] == 0 && save[i][j - 1] == m && save[i][j - 2] == m && save[i][j - 3] == m && save[i][j - 4] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j - 1] == m && save[i][j - 2] == m && save[i][j - 3] == m) || (save[i][j] == 0 && save[i][j - 1] == m && save[i][j + 1] == m && save[i][j + 2] == m && save[i][j + 3] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i + 1][j] == m && save[i + 2][j] == m && save[i + 3][j] == m && save[i + 4][j] == m) || (save[i][j] == 0 && save[i - 1][j] == m && save[i - 2][j] == m && save[i - 3][j] == m && save[i - 4][j] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i + 1][j] == m && save[i - 1][j] == m && save[i - 2][j] == m && save[i - 3][j] == m) || (save[i][j] == 0 && save[i - 1][j] == m && save[i + 1][j] == m && save[i + 2][j] == m && save[i + 3][j] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j + 2] == m && save[i][j - 1] == m && save[i][j - 2] == m) || (save[i][j] == 0 && save[i + 1][j] == m && save[i + 2][j] == m && save[i - 1][j] == m && save[i - 2][j] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i + 1][j + 1] == m && save[i + 2][j + 2] == m && save[i + 3][j + 3] == m && save[i + 4][j + 4] == m) || (save[i][j] == 0 && save[i - 1][j - 1] == m && save[i - 2][j - 2] == m && save[i - 3][j - 3] == m && save[i - 4][j - 4] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i + 1][j - 1] == m && save[i + 2][j - 2] == m && save[i + 3][j - 3] == m && save[i + 4][j - 4] == m) || (save[i][j] == 0 && save[i - 1][j + 1] == m && save[i - 2][j + 2] == m && save[i - 3][j + 3] == m && save[i - 4][j + 4] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i + 1][j + 1] == m && save[i + 2][j + 2] == m && save[i - 1][j - 1] == m && save[i - 2][j - 2] == m) || (save[i][j] == 0 && save[i + 1][j - 1] == m && save[i + 2][j - 2] == m && save[i - 1][j + 1] == m && save[i - 2][j + 2] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i - 1][j - 1] == m && save[i + 1][j + 1] == m && save[i + 2][j + 2] == m && save[i + 3][j + 3] == m) || (save[i][j] == 0 && save[i + 1][j + 1] == m && save[i - 1][j - 1] == m && save[i - 2][j - 2] == m && save[i - 3][j - 3] == m))
				save[i][j] = 100;
			if ((save[i][j] == 0 && save[i + 1][j - 1] == m && save[i - 1][j + 1] == m && save[i - 2][j + 2] == m && save[i - 3][j + 3] == m) || (save[i][j] == 0 && save[i - 1][j + 1] == m && save[i + 1][j - 1] == m && save[i + 2][j - 2] == m && save[i + 3][j - 3] == m))
				save[i][j] = 100;
			//敵方4顆
			if ((save[i][j] == 0 && save[i][j + 1] != 0 && save[i][j + 1] != m && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j + 2] != 0 && save[i][j + 2] != m && save[i][j + 2] != 100 && save[i][j + 2] != 90 && save[i][j + 2] != 80 && save[i][j + 2] != 70 && save[i][j + 2] != 60 && save[i][j + 2] != 50 && save[i][j + 2] != 40 && save[i][j + 2] != 30 && save[i][j + 3] != 0 && save[i][j + 3] != m && save[i][j + 3] != 100 && save[i][j + 3] != 90 && save[i][j + 3] != 80 && save[i][j + 3] != 70 && save[i][j + 3] != 60 && save[i][j + 3] != 50 && save[i][j + 3] != 40 && save[i][j + 3] != 30 && save[i][j + 4] != 0 && save[i][j + 4] != m && save[i][j + 4] != 100 && save[i][j + 4] != 90 && save[i][j + 4] != 80 && save[i][j + 4] != 70 && save[i][j + 4] != 60 && save[i][j + 4] != 50 && save[i][j + 4] != 40 && save[i][j + 4] != 30) ||
				(save[i][j] == 0 && save[i][j - 1] != 0 && save[i][j - 1] != m && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j - 2] != 0 && save[i][j - 2] != m && save[i][j - 2] != 100 && save[i][j - 2] != 90 && save[i][j - 2] != 80 && save[i][j - 2] != 70 && save[i][j - 2] != 60 && save[i][j - 2] != 50 && save[i][j - 2] != 40 && save[i][j - 2] != 30 && save[i][j - 3] != 0 && save[i][j - 3] != m && save[i][j - 3] != 100 && save[i][j - 3] != 90 && save[i][j - 3] != 80 && save[i][j - 3] != 70 && save[i][j - 3] != 60 && save[i][j - 3] != 50 && save[i][j - 3] != 40 && save[i][j - 3] != 30 && save[i][j - 4] != 0 && save[i][j - 4] != m && save[i][j - 4] != 100 && save[i][j - 4] != 90 && save[i][j - 4] != 80 && save[i][j - 4] != 70 && save[i][j - 4] != 60 && save[i][j - 4] != 50 && save[i][j - 4] != 40 && save[i][j - 4] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j] != 0 && save[i + 1][j] != m && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i + 2][j] != 0 && save[i + 2][j] != m && save[i + 2][j] != 100 && save[i + 2][j] != 90 && save[i + 2][j] != 80 && save[i + 2][j] != 70 && save[i + 2][j] != 60 && save[i + 2][j] != 50 && save[i + 2][j] != 40 && save[i + 2][j] != 30 && save[i + 3][j] != 0 && save[i + 3][j] != m && save[i + 3][j] != 100 && save[i + 3][j] != 90 && save[i + 3][j] != 80 && save[i + 3][j] != 70 && save[i + 3][j] != 60 && save[i + 3][j] != 50 && save[i + 3][j] != 40 && save[i + 3][j] != 30 && save[i + 4][j] != 0 && save[i + 4][j] != m && save[i + 4][j] != 100 && save[i + 4][j] != 90 && save[i + 4][j] != 80 && save[i + 4][j] != 70 && save[i + 4][j] != 60 && save[i + 4][j] != 50 && save[i + 4][j] != 40 && save[i + 4][j] != 30) ||
				(save[i][j] == 0 && save[i - 1][j] != 0 && save[i - 1][j] != m && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i - 2][j] != 0 && save[i - 2][j] != m && save[i - 2][j] != 100 && save[i - 2][j] != 90 && save[i - 2][j] != 80 && save[i - 2][j] != 70 && save[i - 2][j] != 60 && save[i - 2][j] != 50 && save[i - 2][j] != 40 && save[i - 2][j] != 30 && save[i - 3][j] != 0 && save[i - 3][j] != m && save[i - 3][j] != 100 && save[i - 3][j] != 90 && save[i - 3][j] != 80 && save[i - 3][j] != 70 && save[i - 3][j] != 60 && save[i - 3][j] != 50 && save[i - 3][j] != 40 && save[i - 3][j] != 30 && save[i - 4][j] != 0 && save[i - 4][j] != m && save[i - 4][j] != 100 && save[i - 4][j] != 90 && save[i - 4][j] != 80 && save[i - 4][j] != 70 && save[i - 4][j] != 60 && save[i - 4][j] != 50 && save[i - 4][j] != 40 && save[i - 4][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i + 2][j + 2] != 0 && save[i + 2][j + 2] != m && save[i + 2][j + 2] != 100 && save[i + 2][j + 2] != 90 && save[i + 2][j + 2] != 80 && save[i + 2][j + 2] != 70 && save[i + 2][j + 2] != 60 && save[i + 2][j + 2] != 50 && save[i + 2][j + 2] != 40 && save[i + 2][j + 2] != 30 && save[i + 3][j + 3] != 0 && save[i + 3][j + 3] != m && save[i + 3][j + 3] != 100 && save[i + 3][j + 3] != 90 && save[i + 3][j + 3] != 80 && save[i + 3][j + 3] != 70 && save[i + 3][j + 3] != 60 && save[i + 3][j + 3] != 50 && save[i + 3][j + 3] != 40 && save[i + 3][j + 3] != 30 && save[i + 4][j + 4] != 0 && save[i + 4][j + 4] != m && save[i + 4][j + 4] != 100 && save[i + 4][j + 4] != 90 && save[i + 4][j + 4] != 80 && save[i + 4][j + 4] != 70 && save[i + 4][j + 4] != 60 && save[i + 4][j + 4] != 50 && save[i + 4][j + 4] != 40 && save[i + 4][j + 4] != 30) ||
				(save[i][j] == 0 && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i - 2][j - 2] != 0 && save[i - 2][j - 2] != m && save[i - 2][j - 2] != 100 && save[i - 2][j - 2] != 90 && save[i - 2][j - 2] != 80 && save[i - 2][j - 2] != 70 && save[i - 2][j - 2] != 60 && save[i - 2][j - 2] != 50 && save[i - 2][j - 2] != 40 && save[i - 2][j - 2] != 30 && save[i - 3][j - 3] != 0 && save[i - 3][j - 3] != m && save[i - 3][j - 3] != 100 && save[i - 3][j - 3] != 90 && save[i - 3][j - 3] != 80 && save[i - 3][j - 3] != 70 && save[i - 3][j - 3] != 60 && save[i - 3][j - 3] != 50 && save[i - 3][j - 3] != 40 && save[i - 3][j - 3] != 30 && save[i - 4][j - 4] != 0 && save[i - 4][j - 4] != m && save[i - 4][j - 4] != 100 && save[i - 4][j - 4] != 90 && save[i - 4][j - 4] != 80 && save[i - 4][j - 4] != 70 && save[i - 4][j - 4] != 60 && save[i - 4][j - 4] != 50 && save[i - 4][j - 4] != 40 && save[i - 4][j - 4] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i + 2][j - 2] != 0 && save[i + 2][j - 2] != m && save[i + 2][j - 2] != 100 && save[i + 2][j - 2] != 90 && save[i + 2][j - 2] != 80 && save[i + 2][j - 2] != 70 && save[i + 2][j - 2] != 60 && save[i + 2][j - 2] != 50 && save[i + 2][j - 2] != 40 && save[i + 2][j - 2] != 30 && save[i + 3][j - 3] != 0 && save[i + 3][j - 3] != m && save[i + 3][j - 3] != 100 && save[i + 3][j - 3] != 90 && save[i + 3][j - 3] != 80 && save[i + 3][j - 3] != 70 && save[i + 3][j - 3] != 60 && save[i + 3][j - 3] != 50 && save[i + 3][j - 3] != 40 && save[i + 3][j - 3] != 30 && save[i + 4][j - 4] != 0 && save[i + 4][j - 4] != m && save[i + 4][j - 4] != 100 && save[i + 4][j - 4] != 90 && save[i + 4][j - 4] != 80 && save[i + 4][j - 4] != 70 && save[i + 4][j - 4] != 60 && save[i + 4][j - 4] != 50 && save[i + 4][j - 4] != 40 && save[i + 4][j - 4] != 30) ||
				(save[i][j] == 0 && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i - 2][j + 2] != 0 && save[i - 2][j + 2] != m && save[i - 2][j + 2] != 100 && save[i - 2][j + 2] != 90 && save[i - 2][j + 2] != 80 && save[i - 2][j + 2] != 70 && save[i - 2][j + 2] != 60 && save[i - 2][j + 2] != 50 && save[i - 2][j + 2] != 40 && save[i - 2][j + 2] != 30 && save[i - 3][j + 3] != 0 && save[i - 3][j + 3] != m && save[i - 3][j + 3] != 100 && save[i - 3][j + 3] != 90 && save[i - 3][j + 3] != 80 && save[i - 3][j + 3] != 70 && save[i - 3][j + 3] != 60 && save[i - 3][j + 3] != 50 && save[i - 3][j + 3] != 40 && save[i - 3][j + 3] != 30 && save[i - 4][j + 4] != 0 && save[i - 4][j + 4] != m && save[i - 4][j + 4] != 100 && save[i - 4][j + 4] != 90 && save[i - 4][j + 4] != 80 && save[i - 4][j + 4] != 70 && save[i - 4][j + 4] != 60 && save[i - 4][j + 4] != 50 && save[i - 4][j + 4] != 40 && save[i - 4][j + 4] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j + 2] != m && save[i][j + 2] != 0 && save[i][j + 2] != 100 && save[i][j + 2] != 90 && save[i][j + 2] != 80 && save[i][j + 2] != 70 && save[i][j + 2] != 60 && save[i][j + 2] != 50 && save[i][j + 2] != 40 && save[i][j + 2] != 30 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j - 2] != m && save[i][j - 2] != 0 && save[i][j - 2] != 100 && save[i][j - 2] != 90 && save[i][j - 2] != 80 && save[i][j - 2] != 70 && save[i][j - 2] != 60 && save[i][j - 2] != 50 && save[i][j - 2] != 40 && save[i][j - 2] != 30) ||
				(save[i][j] == 0 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i + 2][j] != m && save[i + 2][j] != 0 && save[i + 2][j] != 100 && save[i + 2][j] != 90 && save[i + 2][j] != 80 && save[i + 2][j] != 70 && save[i + 2][j] != 60 && save[i + 2][j] != 50 && save[i + 2][j] != 40 && save[i + 2][j] != 30 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i - 2][j] != m && save[i - 2][j] != 0 && save[i - 2][j] != 100 && save[i - 2][j] != 90 && save[i - 2][j] != 80 && save[i - 2][j] != 70 && save[i - 2][j] != 60 && save[i - 2][j] != 50 && save[i - 2][j] != 40 && save[i - 2][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i + 2][j + 2] != m && save[i + 2][j + 2] != 0 && save[i + 2][j + 2] != 100 && save[i + 2][j + 2] != 90 && save[i + 2][j + 2] != 80 && save[i + 2][j + 2] != 70 && save[i + 2][j + 2] != 60 && save[i + 2][j + 2] != 50 && save[i + 2][j + 2] != 40 && save[i + 2][j + 2] != 30 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i - 2][j - 2] != m && save[i - 2][j - 2] != 0 && save[i - 2][j - 2] != 100 && save[i - 2][j - 2] != 90 && save[i - 2][j - 2] != 80 && save[i - 2][j - 2] != 70 && save[i - 2][j - 2] != 60 && save[i - 2][j - 2] != 50 && save[i - 2][j - 2] != 40 && save[i - 2][j - 2] != 30) ||
				(save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i + 2][j - 2] != m && save[i + 2][j - 2] != 0 && save[i + 2][j - 2] != 100 && save[i + 2][j - 2] != 90 && save[i + 2][j - 2] != 80 && save[i + 2][j - 2] != 70 && save[i + 2][j - 2] != 60 && save[i + 2][j - 2] != 50 && save[i + 2][j - 2] != 40 && save[i + 2][j - 2] != 30 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i - 2][j + 2] != m && save[i - 2][j + 2] != 0 && save[i - 2][j + 2] != 100 && save[i - 2][j + 2] != 90 && save[i - 2][j + 2] != 80 && save[i - 2][j + 2] != 70 && save[i - 2][j + 2] != 60 && save[i - 2][j + 2] != 50 && save[i - 2][j + 2] != 40 && save[i - 2][j + 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j - 2] != m && save[i][j - 2] != 0 && save[i][j - 2] != 100 && save[i][j - 2] != 90 && save[i][j - 2] != 80 && save[i][j - 2] != 70 && save[i][j - 2] != 60 && save[i][j - 2] != 50 && save[i][j - 2] != 40 && save[i][j - 2] != 30 && save[i][j - 3] != m && save[i][j - 3] != 0 && save[i][j - 3] != 100 && save[i][j - 3] != 90 && save[i][j - 3] != 80 && save[i][j - 3] != 70 && save[i][j - 3] != 60 && save[i][j - 3] != 50 && save[i][j - 3] != 40 && save[i][j - 3] != 30) ||
				(save[i][j] == 0 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j + 2] != m && save[i][j + 2] != 0 && save[i][j + 2] != 100 && save[i][j + 2] != 90 && save[i][j + 2] != 80 && save[i][j + 2] != 70 && save[i][j + 2] != 60 && save[i][j + 2] != 50 && save[i][j + 2] != 40 && save[i][j + 2] != 30 && save[i][j + 3] != m && save[i][j + 3] != 0 && save[i][j + 3] != 100 && save[i][j + 3] != 90 && save[i][j + 3] != 80 && save[i][j + 3] != 70 && save[i][j + 3] != 60 && save[i][j + 3] != 50 && save[i][j + 3] != 40 && save[i][j + 3] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i - 2][j] != m && save[i - 2][j] != 0 && save[i - 2][j] != 100 && save[i - 2][j] != 90 && save[i - 2][j] != 80 && save[i - 2][j] != 70 && save[i - 2][j] != 60 && save[i - 2][j] != 50 && save[i - 2][j] != 40 && save[i - 2][j] != 30 && save[i - 3][j] != m && save[i - 3][j] != 0 && save[i - 3][j] != 100 && save[i - 3][j] != 90 && save[i - 3][j] != 80 && save[i - 3][j] != 70 && save[i - 3][j] != 60 && save[i - 3][j] != 50 && save[i - 3][j] != 40 && save[i - 3][j] != 30) ||
				(save[i][j] == 0 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i + 2][j] != m && save[i + 2][j] != 0 && save[i + 2][j] != 100 && save[i + 2][j] != 90 && save[i + 2][j] != 80 && save[i + 2][j] != 70 && save[i + 2][j] != 60 && save[i + 2][j] != 50 && save[i + 2][j] != 40 && save[i + 2][j] != 30 && save[i + 3][j] != m && save[i + 3][j] != 0 && save[i + 3][j] != 100 && save[i + 3][j] != 90 && save[i + 3][j] != 80 && save[i + 3][j] != 70 && save[i + 3][j] != 60 && save[i + 3][j] != 50 && save[i + 3][j] != 40 && save[i + 3][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i - 2][j + 2] != m && save[i - 2][j + 2] != 0 && save[i - 2][j + 2] != 100 && save[i - 2][j + 2] != 90 && save[i - 2][j + 2] != 80 && save[i - 2][j + 2] != 70 && save[i - 2][j + 2] != 60 && save[i - 2][j + 2] != 50 && save[i - 2][j + 2] != 40 && save[i - 2][j + 2] != 30 && save[i - 3][j + 3] != m && save[i - 3][j + 3] != 0 && save[i - 3][j + 3] != 100 && save[i - 3][j + 3] != 90 && save[i - 3][j + 3] != 80 && save[i - 3][j + 3] != 70 && save[i - 3][j + 3] != 60 && save[i - 3][j + 3] != 50 && save[i - 3][j + 3] != 40 && save[i - 3][j + 3] != 30) ||
				(save[i][j] == 0 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i + 2][j - 2] != m && save[i + 2][j - 2] != 0 && save[i + 2][j - 2] != 100 && save[i + 2][j - 2] != 90 && save[i + 2][j - 2] != 80 && save[i + 2][j - 2] != 70 && save[i + 2][j - 2] != 60 && save[i + 2][j - 2] != 50 && save[i + 2][j - 2] != 40 && save[i + 2][j - 2] != 30 && save[i + 3][j - 3] != m && save[i + 3][j - 3] != 0 && save[i + 3][j - 3] != 100 && save[i + 3][j - 3] != 90 && save[i + 3][j - 3] != 80 && save[i + 3][j - 3] != 70 && save[i + 3][j - 3] != 60 && save[i + 3][j - 3] != 50 && save[i + 3][j - 3] != 40 && save[i + 3][j - 3] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i - 2][j - 2] != m && save[i - 2][j - 2] != 0 && save[i - 2][j - 2] != 100 && save[i - 2][j - 2] != 90 && save[i - 2][j - 2] != 80 && save[i - 2][j - 2] != 70 && save[i - 2][j - 2] != 60 && save[i - 2][j - 2] != 50 && save[i - 2][j - 2] != 40 && save[i - 2][j - 2] != 30 && save[i - 3][j - 3] != m && save[i - 3][j - 3] != 0 && save[i - 3][j - 3] != 100 && save[i - 3][j - 3] != 90 && save[i - 3][j - 3] != 80 && save[i - 3][j - 3] != 70 && save[i - 3][j - 3] != 60 && save[i - 3][j - 3] != 50 && save[i - 3][j - 3] != 40 && save[i - 3][j - 3] != 30) ||
				(save[i][j] == 0 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i + 2][j + 2] != m && save[i + 2][j + 2] != 0 && save[i + 2][j + 2] != 100 && save[i + 2][j + 2] != 90 && save[i + 2][j + 2] != 80 && save[i + 2][j + 2] != 70 && save[i + 2][j + 2] != 60 && save[i + 2][j + 2] != 50 && save[i + 2][j + 2] != 40 && save[i + 2][j + 2] != 30 && save[i + 3][j + 3] != m && save[i + 3][j + 3] != 0 && save[i + 3][j + 3] != 100 && save[i + 3][j + 3] != 90 && save[i + 3][j + 3] != 80 && save[i + 3][j + 3] != 70 && save[i + 3][j + 3] != 60 && save[i + 3][j + 3] != 50 && save[i + 3][j + 3] != 40 && save[i + 3][j + 3] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 90;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			//我方三顆
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j + 2] == m && save[i][j + 3] == m) || (save[i][j] == 0 && save[i][j - 1] == m && save[i][j - 2] == m && save[i][j - 3] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j - 1] == m && save[i][j - 2] == m) || (save[i][j] == 0 && save[i][j - 1] == m && save[i][j + 1] == m && save[i][j + 2] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j] == m && save[i + 2][j] == m && save[i + 3][j] == m) || (save[i][j] == 0 && save[i - 1][j] == m && save[i - 2][j] == m && save[i - 3][j] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j] == m && save[i + 1][j] == m && save[i + 2][j] == m) || (save[i][j] == 0 && save[i - 1][j] == m && save[i - 2][j] == m && save[i + 1][j] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] == m && save[i + 2][j + 2] == m && save[i + 3][j + 3] == m) || (save[i][j] == 0 && save[i - 1][j - 1] == m && save[i - 2][j - 2] == m && save[i - 3][j - 3] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j - 1] == m && save[i + 1][j + 1] == m && save[i + 2][j + 2] == m) || (save[i][j] == 0 && save[i + 1][j + 1] == m && save[i - 1][j - 1] == m && save[i - 2][j - 2] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j + 1] == m && save[i - 2][j + 2] == m && save[i - 3][j + 3] == m) || (save[i][j] == 0 && save[i + 1][j - 1] == m && save[i + 2][j - 2] == m && save[i + 3][j - 3] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j + 1] == m && save[i + 1][j - 1] == m && save[i + 2][j - 2] == m) || (save[i][j] == 0 && save[i + 1][j - 1] == m && save[i - 1][j + 1] == m && save[i - 2][j + 2] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 80;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			//敵方3顆
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j + 2] != m && save[i][j + 2] != 0 && save[i][j + 2] != 100 && save[i][j + 2] != 90 && save[i][j + 2] != 80 && save[i][j + 2] != 70 && save[i][j + 2] != 60 && save[i][j + 2] != 50 && save[i][j + 2] != 40 && save[i][j + 2] != 30 && save[i][j + 3] != m && save[i][j + 3] != 0 && save[i][j + 3] != 100 && save[i][j + 3] != 90 && save[i][j + 3] != 80 && save[i][j + 3] != 70 && save[i][j + 3] != 60 && save[i][j + 3] != 50 && save[i][j + 3] != 40 && save[i][j + 3] != 30) ||
				(save[i][j] == 0 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j - 2] != m && save[i][j - 2] != 0 && save[i][j - 2] != 100 && save[i][j - 2] != 90 && save[i][j - 2] != 80 && save[i][j - 2] != 70 && save[i][j - 2] != 60 && save[i][j - 2] != 50 && save[i][j - 2] != 40 && save[i][j - 2] != 30 && save[i][j - 3] != m && save[i][j - 3] != 0 && save[i][j - 3] != 100 && save[i][j - 3] != 90 && save[i][j - 3] != 80 && save[i][j - 3] != 70 && save[i][j - 3] != 60 && save[i][j - 3] != 50 && save[i][j - 3] != 40 && save[i][j - 3] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j - 2] != m && save[i][j - 2] != 0 && save[i][j - 2] != 100 && save[i][j - 2] != 90 && save[i][j - 2] != 80 && save[i][j - 2] != 70 && save[i][j - 2] != 60 && save[i][j - 2] != 50 && save[i][j - 2] != 40 && save[i][j - 2] != 30) ||
				(save[i][j] == 0 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j + 2] != m && save[i][j + 2] != 0 && save[i][j + 2] != 100 && save[i][j + 2] != 90 && save[i][j + 2] != 80 && save[i][j + 2] != 70 && save[i][j + 2] != 60 && save[i][j + 2] != 50 && save[i][j + 2] != 40 && save[i][j + 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i + 2][j] != m && save[i + 2][j] != 0 && save[i + 2][j] != 100 && save[i + 2][j] != 90 && save[i + 2][j] != 80 && save[i + 2][j] != 70 && save[i + 2][j] != 60 && save[i + 2][j] != 50 && save[i + 2][j] != 40 && save[i + 2][j] != 30 && save[i + 3][j] != m && save[i + 3][j] != 0 && save[i + 3][j] != 100 && save[i + 3][j] != 90 && save[i + 3][j] != 80 && save[i + 3][j] != 70 && save[i + 3][j] != 60 && save[i + 3][j] != 50 && save[i + 3][j] != 40 && save[i + 3][j] != 30) ||
				(save[i][j] == 0 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i - 2][j] != m && save[i - 2][j] != 0 && save[i - 2][j] != 100 && save[i - 2][j] != 90 && save[i - 2][j] != 80 && save[i - 2][j] != 70 && save[i - 2][j] != 60 && save[i - 2][j] != 50 && save[i - 2][j] != 40 && save[i - 2][j] != 30 && save[i - 3][j] != m && save[i - 3][j] != 0 && save[i - 3][j] != 100 && save[i - 3][j] != 90 && save[i - 3][j] != 80 && save[i - 3][j] != 70 && save[i - 3][j] != 60 && save[i - 3][j] != 50 && save[i - 3][j] != 40 && save[i - 3][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i + 2][j] != m && save[i + 2][j] != 0 && save[i + 2][j] != 100 && save[i + 2][j] != 90 && save[i + 2][j] != 80 && save[i + 2][j] != 60 && save[i + 2][j] != 70 && save[i + 2][j] != 50 && save[i + 2][j] != 40 && save[i + 2][j] != 30) ||
				(save[i][j] == 0 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i - 2][j] != m && save[i - 2][j] != 0 && save[i - 2][j] != 100 && save[i - 2][j] != 90 && save[i - 2][j] != 80 && save[i - 2][j] != 70 && save[i - 2][j] != 60 && save[i - 2][j] != 50 && save[i - 2][j] != 40 && save[i - 2][j] != 30 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i + 2][j + 2] != m && save[i + 2][j + 2] != 0 && save[i + 2][j + 2] != 100 && save[i + 2][j + 2] != 90 && save[i + 2][j + 2] != 80 && save[i + 2][j + 2] != 70 && save[i + 2][j + 2] != 60 && save[i + 2][j + 2] != 50 && save[i + 2][j + 2] != 40 && save[i + 2][j + 2] != 30 && save[i + 3][j + 3] != m && save[i + 3][j + 3] != 0 && save[i + 3][j + 3] != 100 && save[i + 3][j + 3] != 90 && save[i + 3][j + 3] != 80 && save[i + 3][j + 3] != 70 && save[i + 3][j + 3] != 60 && save[i + 3][j + 3] != 50 && save[i + 3][j + 3] != 40 && save[i + 3][j + 3] != 30) ||
				(save[i][j] == 0 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i - 2][j - 2] != m && save[i - 2][j - 2] != 0 && save[i - 2][j - 2] != 100 && save[i - 2][j - 2] != 90 && save[i - 2][j - 2] != 80 && save[i - 2][j - 2] != 70 && save[i - 2][j - 2] != 60 && save[i - 2][j - 2] != 50 && save[i - 2][j - 2] != 40 && save[i - 2][j - 2] != 30 && save[i - 3][j - 3] != m && save[i - 3][j - 3] != 0 && save[i - 3][j - 3] != 100 && save[i - 3][j - 3] != 90 && save[i - 3][j - 3] != 80 && save[i - 3][j - 3] != 70 && save[i - 3][j - 3] != 60 && save[i - 3][j - 3] != 50 && save[i - 3][j - 3] != 40 && save[i - 3][j - 3] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i + 2][j + 2] != m && save[i + 2][j + 2] != 0 && save[i + 2][j + 2] != 100 && save[i + 2][j + 2] != 90 && save[i + 2][j + 2] != 80 && save[i + 2][j + 2] != 70 && save[i + 2][j + 2] != 60 && save[i + 2][j + 2] != 50 && save[i + 2][j + 2] != 40 && save[i + 2][j + 2] != 30) ||
				(save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i - 2][j - 2] != m && save[i - 2][j - 2] != 0 && save[i - 2][j - 2] != 100 && save[i - 2][j - 2] != 90 && save[i - 2][j - 2] != 80 && save[i - 2][j - 2] != 70 && save[i - 2][j - 2] != 60 && save[i - 2][j - 2] != 50 && save[i - 2][j - 2] != 40 && save[i - 2][j - 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i - 2][j + 2] != m && save[i - 2][j + 2] != 0 && save[i - 2][j + 2] != 100 && save[i - 2][j + 2] != 90 && save[i - 2][j + 2] != 80 && save[i - 2][j + 2] != 70 && save[i - 2][j + 2] != 60 && save[i - 2][j + 2] != 50 && save[i - 2][j + 2] != 40 && save[i - 2][j + 2] != 30 && save[i - 3][j + 3] != m && save[i - 3][j + 3] != 0 && save[i - 3][j + 3] != 100 && save[i - 3][j + 3] != 90 && save[i - 3][j + 3] != 80 && save[i - 3][j + 3] != 70 && save[i - 3][j + 3] != 60 && save[i - 3][j + 3] != 50 && save[i - 3][j + 3] != 40 && save[i - 3][j + 3] != 30) ||
				(save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i + 2][j - 2] != m && save[i + 2][j - 2] != 0 && save[i + 2][j - 2] != 100 && save[i + 2][j - 2] != 90 && save[i + 2][j - 2] != 80 && save[i + 2][j - 2] != 70 && save[i + 2][j - 2] != 60 && save[i + 2][j - 2] != 50 && save[i + 2][j - 2] != 40 && save[i + 2][j - 2] != 30 && save[i + 3][j - 3] != m && save[i + 3][j - 3] != 0 && save[i + 3][j - 3] != 100 && save[i + 3][j - 3] != 90 && save[i + 3][j - 3] != 80 && save[i + 3][j - 3] != 70 && save[i + 3][j - 3] != 60 && save[i + 3][j - 3] != 50 && save[i + 3][j - 3] != 40 && save[i + 3][j - 3] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i + 2][j - 2] != m && save[i + 2][j - 2] != 0 && save[i + 2][j - 2] != 100 && save[i + 2][j - 2] != 90 && save[i + 2][j - 2] != 80 && save[i + 2][j - 2] != 70 && save[i + 2][j - 2] != 60 && save[i + 2][j - 2] != 50 && save[i + 2][j - 2] != 40 && save[i + 2][j - 2] != 30) ||
				(save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i - 2][j + 2] != m && save[i - 2][j + 2] != 0 && save[i - 2][j + 2] != 100 && save[i - 2][j + 2] != 90 && save[i - 2][j + 2] != 80 && save[i - 2][j + 2] != 70 && save[i - 2][j + 2] != 60 && save[i - 2][j + 2] != 50 && save[i - 2][j + 2] != 40 && save[i - 2][j + 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 70;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			//我方2顆
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j + 2] == m) || (save[i][j] == 0 && save[i][j - 1] == m && save[i][j - 2] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 60;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j] == m && save[i + 2][j] == m) || (save[i][j] == 0 && save[i - 1][j] == m && save[i - 2][j] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 60;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] == m && save[i + 2][j + 2] == m) || (save[i][j] == 0 && save[i - 1][j - 1] == m && save[i - 1][j - 2] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 60;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j + 1] == m && save[i - 2][j + 2] == m) || (save[i][j] == 0 && save[i + 1][j - 1] == m && save[i + 2][j - 2] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 60;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i][j + 1] == m && save[i][j - 1] == m) || (save[i][j] == 0 && save[i + 1][j] == m && save[i - 1][j] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 60;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] == m && save[i - 1][j - 1] == m) || (save[i][j] == 0 && save[i + 1][j - 1] == m && save[i - 1][j + 1] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 60;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			//敵方2顆
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j + 2] != m && save[i][j + 2] != 0 && save[i][j + 2] != 100 && save[i][j + 2] != 90 && save[i][j + 2] != 80 && save[i][j + 2] != 70 && save[i][j + 2] != 60 && save[i][j + 2] != 50 && save[i][j + 2] != 40 && save[i][j + 2] != 30) ||
				(save[i][j] == 0 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30 && save[i][j - 2] != m && save[i][j - 2] != 0 && save[i][j - 2] != 100 && save[i][j - 2] != 90 && save[i][j - 2] != 80 && save[i][j - 2] != 70 && save[i][j - 2] != 60 && save[i][j - 2] != 50 && save[i][j - 2] != 40 && save[i][j - 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 50;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i + 2][j] != m && save[i + 2][j] != 0 && save[i + 2][j] != 100 && save[i + 2][j] != 90 && save[i + 2][j] != 80 && save[i + 2][j] != 70 && save[i + 2][j] != 60 && save[i + 2][j] != 50 && save[i + 2][j] != 40 && save[i + 2][j] != 30) ||
				(save[i][j] == 0 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30 && save[i - 2][j] != m && save[i - 2][j] != 0 && save[i - 2][j] != 100 && save[i - 2][j] != 90 && save[i - 2][j] != 80 && save[i - 2][j] != 70 && save[i - 2][j] != 60 && save[i - 2][j] != 50 && save[i - 2][j] != 40 && save[i - 2][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 50;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i + 2][j + 2] != m && save[i + 2][j + 2] != 0 && save[i + 2][j + 2] != 100 && save[i + 2][j + 2] != 90 && save[i + 2][j + 2] != 80 && save[i + 2][j + 2] != 70 && save[i + 2][j + 2] != 60 && save[i + 2][j + 2] != 50 && save[i + 2][j + 2] != 40 && save[i + 2][j + 2] != 30) ||
				(save[i][j] == 0 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30 && save[i - 1][j - 2] != m && save[i - 1][j - 2] != 0 && save[i - 1][j - 2] != 100 && save[i - 1][j - 2] != 90 && save[i - 1][j - 2] != 80 && save[i - 1][j - 2] != 70 && save[i - 1][j - 2] != 60 && save[i - 1][j - 2] != 50 && save[i - 1][j - 2] != 40 && save[i - 1][j - 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 50;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30 && save[i - 2][j + 2] != m && save[i - 2][j + 2] != 0 && save[i - 2][j + 2] != 100 && save[i - 2][j + 2] != 90 && save[i - 2][j + 2] != 80 && save[i - 2][j + 2] != 70 && save[i - 2][j + 2] != 60 && save[i - 2][j + 2] != 50 && save[i - 2][j + 2] != 40 && save[i - 2][j + 2] != 30) ||
				(save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i + 2][j - 2] != m && save[i + 2][j - 2] != 0 && save[i + 2][j - 2] != 100 && save[i + 2][j - 2] != 90 && save[i + 2][j - 2] != 80 && save[i + 2][j - 2] != 70 && save[i + 2][j - 2] != 60 && save[i + 2][j - 2] != 50 && save[i + 2][j - 2] != 40 && save[i + 2][j - 2] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 50;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30) ||
				(save[i][j] == 0 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 50;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			if ((save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30) ||
				(save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 50;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			//我方1顆
			if ((save[i][j] == 0 && save[i][j + 1] == m) || (save[i][j] == 0 && save[i][j - 1] == m) || (save[i][j] == 0 && save[i + 1][j] == m) || (save[i][j] == 0 && save[i - 1][j] == m) || (save[i][j] == 0 && save[i + 1][j + 1] == m) || (save[i][j] == 0 && save[i - 1][j + 1] == m) || (save[i][j] == 0 && save[i - 1][j - 1] == m) || (save[i][j] == 0 && save[i + 1][j - 1] == m))
			{
				int tmp = save[i][j];
				save[i][j] = 40;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
			//敵方1顆
			if ((save[i][j] == 0 && save[i][j + 1] != m && save[i][j + 1] != 0 && save[i][j + 1] != 100 && save[i][j + 1] != 90 && save[i][j + 1] != 80 && save[i][j + 1] != 70 && save[i][j + 1] != 60 && save[i][j + 1] != 50 && save[i][j + 1] != 40 && save[i][j + 1] != 30) || (save[i][j] == 0 && save[i][j - 1] != m && save[i][j - 1] != 0 && save[i][j - 1] != 100 && save[i][j - 1] != 90 && save[i][j - 1] != 80 && save[i][j - 1] != 70 && save[i][j - 1] != 60 && save[i][j - 1] != 50 && save[i][j - 1] != 40 && save[i][j - 1] != 30) || (save[i][j] == 0 && save[i + 1][j] != m && save[i + 1][j] != 0 && save[i + 1][j] != 100 && save[i + 1][j] != 90 && save[i + 1][j] != 80 && save[i + 1][j] != 70 && save[i + 1][j] != 60 && save[i + 1][j] != 50 && save[i + 1][j] != 40 && save[i + 1][j] != 30) || (save[i][j] == 0 && save[i - 1][j] != m && save[i - 1][j] != 0 && save[i - 1][j] != 100 && save[i - 1][j] != 90 && save[i - 1][j] != 80 && save[i - 1][j] != 70 && save[i - 1][j] != 60 && save[i - 1][j] != 50 && save[i - 1][j] != 40 && save[i - 1][j] != 30) || (save[i][j] == 0 && save[i + 1][j + 1] != m && save[i + 1][j + 1] != 0 && save[i + 1][j + 1] != 100 && save[i + 1][j + 1] != 90 && save[i + 1][j + 1] != 80 && save[i + 1][j + 1] != 70 && save[i + 1][j + 1] != 60 && save[i + 1][j + 1] != 50 && save[i + 1][j + 1] != 40 && save[i + 1][j + 1] != 30) || (save[i][j] == 0 && save[i - 1][j + 1] != m && save[i - 1][j + 1] != 0 && save[i - 1][j + 1] != 100 && save[i - 1][j + 1] != 90 && save[i - 1][j + 1] != 80 && save[i - 1][j + 1] != 70 && save[i - 1][j + 1] != 60 && save[i - 1][j + 1] != 50 && save[i - 1][j + 1] != 40 && save[i - 1][j + 1] != 30) || (save[i][j] == 0 && save[i - 1][j - 1] != m && save[i - 1][j - 1] != 0 && save[i - 1][j - 1] != 100 && save[i - 1][j - 1] != 90 && save[i - 1][j - 1] != 80 && save[i - 1][j - 1] != 70 && save[i - 1][j - 1] != 60 && save[i - 1][j - 1] != 50 && save[i - 1][j - 1] != 40 && save[i - 1][j - 1] != 30) || (save[i][j] == 0 && save[i + 1][j - 1] != m && save[i + 1][j - 1] != 0 && save[i + 1][j - 1] != 100 && save[i + 1][j - 1] != 90 && save[i + 1][j - 1] != 80 && save[i + 1][j - 1] != 70 && save[i + 1][j - 1] != 60 && save[i + 1][j - 1] != 50 && save[i + 1][j - 1] != 40 && save[i + 1][j - 1] != 30))
			{
				int tmp = save[i][j];
				save[i][j] = 30;
				if (tmp > save[i][j])
					save[i][j] = tmp;
			}
		}
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (max < save[i][j])
			{
				max = save[i][j];
				x = i;
				y = j;
			}
	cout << "(" << x << "," << y << ")" << endl;
	set(x, y, m);
}
int check()
{
	int winner = 0;
	return winner;
}
int main(int n, char** args)
{
	int player = args[1][0] - '0';
	srand(time(0));
	if (player == 0) {
		init(); write(); show();
	}
	else
	{
		read();
		cout << "player" << player << endl;
		play(player);
		write();
		show();
	}
	return 0;
}