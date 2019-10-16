#include <iostream>

using namespace std;


int nMap[21][21];

int dice[6];

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = { 0, 1, -1, 0, 0 };

void move_dice(int dir)
{
	int nDice[6];

	switch (dir)
	{
	case 1:
		nDice[0] = dice[0];
		nDice[5] = dice[1];
		nDice[2] = dice[2];
		nDice[4] = dice[3];
		nDice[1] = dice[4];
		nDice[3] = dice[5];
		break;
	case 2:
		nDice[0] = dice[0];
		nDice[4] = dice[1];
		nDice[2] = dice[2];
		nDice[5] = dice[3];
		nDice[3] = dice[4];
		nDice[1] = dice[5];
		break;
	case 3:
		nDice[3] = dice[0];
		nDice[0] = dice[1];
		nDice[1] = dice[2];
		nDice[2] = dice[3];
		nDice[4] = dice[4];
		nDice[5] = dice[5];
		break;
	case 4:
		nDice[1] = dice[0];
		nDice[2] = dice[1];
		nDice[3] = dice[2];
		nDice[0] = dice[3];
		nDice[4] = dice[4];
		nDice[5] = dice[5];
		break;
	default:
		break;
	}

	for (int i = 0; i < 6; i++)
	{
		dice[i] = nDice[i];
	}
}

int main(void)
{
	int N, M;			// 가로 크기, 세로 크기
	int cy, cx;		// 주사위를 놓은 곳의 좌표
	int K;			// 명령의 개수

	cin >> N >> M >> cy >> cx >> K;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> nMap[y][x];
		}
	}

	int dir;

	for (int i = 0; i < K; i++)
	{
		cin >> dir;
		
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
		{
			continue;
		}

		move_dice(dir);

		if (nMap[ny][nx] == 0)
		{
			nMap[ny][nx] = dice[3];
		}
		else
		{
			dice[3] = nMap[ny][nx];
			nMap[ny][nx] = 0;
		}

		cy = ny;
		cx = nx;

		cout << dice[1] << endl;
	}
	return 0;
}