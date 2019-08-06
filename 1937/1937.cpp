#include <iostream>
#include <algorithm>

using namespace std;

int nMap[501][501];
int nDayMap[501][501];

int N;
int nResult;
int nTemp;


int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int DFS(int y, int x)
{
	if (nDayMap[y][x]) return nDayMap[y][x];
	nDayMap[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 1 && ny <= N && nx >= 1 && nx <= N)
		{
			if (nMap[y][x] < nMap[ny][nx])
			{
				nDayMap[y][x] = max(nDayMap[y][x], DFS(ny, nx)+1);
			}
		}
	}

	return nDayMap[y][x];
}

int main(void)
{
	cin >> N;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> nMap[y][x];
		}
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			nResult = max(nResult, DFS(y, x));
		}
	}

	cout << nResult << endl;



	return 0;
}