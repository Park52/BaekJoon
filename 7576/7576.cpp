#include <iostream>
#include <queue>
#include <vector>
#include <string.h>


using namespace std;

const int dy[4] = { -1, 1, 0, 0, };
const int dx[4] = { 0, 0, -1, 1 };

int N, M;

int Map[1000][1000];
int arrDistance[1000][1000];

int main(void)
{
	queue<pair<int, int>> StartP;
	
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			arrDistance[i][j] = -1;

			if (Map[i][j] == 1)
			{
				StartP.push(make_pair(i, j));
				arrDistance[i][j] = 0;
			}
		}
	}

	while (!StartP.empty())
	{
		int y = StartP.front().first;
		int x = StartP.front().second;

		StartP.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (Map[ny][nx] == 0 && arrDistance[ny][nx] == -1)
				{
					arrDistance[ny][nx] = arrDistance[y][x] + 1;
					StartP.push(make_pair(ny, nx));
				}
			}
		}
	}

	int nResult = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			nResult = max(nResult, arrDistance[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 0 && arrDistance[i][j] == -1)
			{
				nResult = -1;
			}
		}
	}

	cout << nResult;

	return 0;
}