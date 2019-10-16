/*
문제 링크: https://www.acmicpc.net/problem/3190
문제 이름: 뱀

문제 풀이: 시뮬레이션
문제 풀이 참고 블로그 : https://na982.tistory.com/84?category=145346

*/
#define APPLE		1


#include <iostream>

using namespace std;

int N, K, L;				// 보드 게임 크기

int nMap[101][101];

int head_y, head_x, tail_index;
int snake_y[10101], snake_x[10101];
char cmd[10001];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main(void)
{
	cin >> N;

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int nTemp1, nTemp2;
		cin >> nTemp1 >> nTemp2;

		nMap[nTemp1][nTemp2] = APPLE;
	}

	int nTime = 0;
	char cTurn;

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> nTime >> cTurn;
		cmd[nTime] = cTurn;
	}

	int nDir = 0;
	nTime = 0;
	head_y = 1, head_x = 1, tail_index = 0;
	snake_y[nTime] = head_y, snake_x[nTime] = head_x;
	nMap[head_y][head_x] = -1;
	
	while (true)
	{
		++nTime;

		head_y += dy[nDir];
		head_x += dx[nDir];

		if (head_y < 1 || head_y > N || head_x < 1 || head_x > N || nMap[head_y][head_x] == -1)
		{
			break;
		}

		snake_y[nTime] = head_y;
		snake_x[nTime] = head_x;

		if (nMap[head_y][head_x] == 0)
		{
			int tail_y = snake_y[tail_index];
			int tail_x = snake_x[tail_index];

			nMap[tail_y][tail_x] = 0;
			++tail_index;
		}

		nMap[head_y][head_x] = -1;

		if (cmd[nTime] == 'D')
		{
			nDir = (nDir + 1) % 4;
		}

		if (cmd[nTime] == 'L')
		{
			nDir = (nDir + 3) % 4;
		}

	}

	cout << nTime << endl;
	
	return 0;
}