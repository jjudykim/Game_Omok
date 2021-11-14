#include<iostream>
#include<stdlib.h>
using namespace std;
void settingdata(int listxy[20][20]); //gridnum의 초기값 설정
void printgrid(int listxy[20][20], int player, int win); // 화면 출력
void playomok(); // 오목 실행하기
void changetogrid(int gridnum); // gridnum을 격자 기호로 바꿔줌
void inputneed(int inputx, int inputy, int listxy[20][20], int player); // 입력한 x와 y의 조건이 충족되는지 검사
void checkomok(int listxy[20][20], int player, int win); //오목 승리 체크
void cinomok(int player, int listxy[20][20]); //좌표입력
void askplayagain(); //replay
int main()
{
	playomok();
}
void playomok()
{
	int win = 0;
	int count = 0;
	int listxy[20][20];
	int player = 0;
	settingdata(listxy);
	while (true)
	{
		system("cls");
		if (count % 2 == 0) player = 9; else player = 10;
		printgrid(listxy, player, win);
		checkomok(listxy, player, win);
		count++;
	}
}
void settingdata(int listxy[20][20])
{
	for (int j = 1; j < 20; j++)
	{
		if (j == 1)
		{
			listxy[1][1] = 0;
			for (int k = 2; k < 19; k++)
			{
				listxy[1][k] = 1;
			}
			listxy[1][19] = 2;
		}
		else if (j == 19)
		{
			listxy[19][1] = 6;
			for (int k = 2; k < 19; k++)
			{
				listxy[19][k] = 7;
			}
			listxy[19][19] = 8;
		}
		else
		{
			for (int k = 1; k < 20; k++)
			{
				if (k == 1) listxy[j][k] = 3;
				else if (k == 19) listxy[j][k] = 5;
				else listxy[j][k] = 4;
			}
		}
	}
}
void printgrid(int listxy[20][20], int player, int win)
{
	char playagain;
	int gridnum = 0;
	cout << " ===== Let's Play Omok =====" << endl << endl;
	cout << " ";
	for (int i = 1; i < 20; i++)
	{
		cout.width(2) << cout.fill(' ');
		cout << i;
	}cout << endl;
	for (int j = 1; j < 20; j++)
	{
		cout.width(2) << cout.fill(' ');
		cout << j;
		cout << " ";
		for (int k = 1; k < 20; k++)
		{
			gridnum = listxy[j][k];
			changetogrid(gridnum);
		}
		cout << endl;
	}
	cout << endl;
}
void changetogrid(int gridnum)
{
	switch (gridnum)
	{
	case 0:
		cout << "┌";
		break;
	case 1:
		cout << "┬";
		break;
	case 2:
		cout << "┐";
		break;
	case 3:
		cout << "├";
		break;
	case 4:
		cout << "┼";
		break;
	case 5:
		cout << "┤";
		break;
	case 6:
		cout << "└"; break;
	case 7:
		cout << "┴";
		break;
	case 8:
		cout << "┘";
		break;
	case 9:
		cout << "●";
		break;
	case 10:
		cout << "○";
		break;
	}
}
void checkomok(int listxy[20][20], int player, int win)
{
	cinomok(player, listxy);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (listxy[i][j] == player && listxy[i][j + 1] == player && listxy[i][j + 2] == player &&
				listxy[i][j + 3] == player && listxy[i][j + 4] == player) win = 1; //가로 체크
			else if (listxy[i][j] == player && listxy[i + 1][j] == player && listxy[i + 2][j] == player
				&& listxy[i + 3][j] == player && listxy[i + 4][j] == player) win = 1; //세로 체크
			else if (listxy[i][j] == player && listxy[i + 1][j + 1] == player && listxy[i + 2][j + 2] ==
				player && listxy[i + 3][j + 3] == player && listxy[i + 4][j + 4] == player) win = 1; //↘체크
			else if (listxy[i][j] == player && listxy[i + 1][j - 1] == player && listxy[i + 2][j - 2] ==
				player && listxy[i + 3][j - 3] == player && listxy[i + 4][i - 4] == player) win = 1; //↙체크
			else if (listxy[i][j] == player && listxy[i - 1][j + 1] == player && listxy[i - 2][j + 2] ==
				player && listxy[i - 3][j + 3] == player && listxy[i - 4][j + 4] == player) win = 1; //↗체크
			else if (listxy[i][j] == player && listxy[i - 1][j - 1] == player && listxy[i - 2][j - 2] ==
				player && listxy[i - 3][j - 3] == player && listxy[i - 4][j - 4] == player) win = 1; //↖체크
		}
	}
	system("cls");
	printgrid(listxy, player, win);
	if (win == 1)
	{
		if (player == 9)
		{
			cout << "●'s Win!" << endl;
			askplayagain();
		}
		else
		{
			cout << "○'s Win!" << endl;
			askplayagain();
		}
	}
}
void cinomok(int player, int listxy[20][20])
{
	int inputx, inputy;
	if (player == 9)
	{
		cout << "●'s X, Y : ";
		cin >> inputx >> inputy;
		inputneed(inputx, inputy, listxy, player);
	}
	else if (player == 10)
	{
		cout << "○'s X, Y : ";
		cin >> inputx >> inputy;
		inputneed(inputx, inputy, listxy, player);
	}
}
void inputneed(int inputx, int inputy, int listxy[20][20], int player)
{
	int a = 0;
	int b = 0;
	if (listxy[inputy][inputx] == 9 || listxy[inputy][inputx] == 10)
	{
		cout << "Cannot put there. Try again.";
		cin >> a >> b;
		if (player == 9) listxy[b][a] = 9;
		else listxy[b][a] = 10;
	}
	else if (1 <= inputx && inputx <= 19 && 1 <= inputy && inputy <= 19) if (player == 9) listxy[inputy][inputx] = 9; else listxy[inputy][inputx] = 10;
	else if (inputx == 99 && inputy == 99) exit(0);
}
void askplayagain()
{
	char playagain;
	cout << "Play again? (y/n)";
	cin >> playagain;
	if (playagain == 'Y' || playagain == 'y') playomok();
	else if (playagain == 'N' || playagain == 'n') exit(0);
}