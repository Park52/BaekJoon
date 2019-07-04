#include <iostream>
#include <algorithm>
#include <string.h>


using namespace std;

int T, M, N, K;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int nMap[50][50];
bool bChecked[50][50];

int nResult[50];

void dfs(int y, int x)
{
	bChecked[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= ny && ny < N &&
			0 <= nx && nx < M )
		{
			if (!bChecked[ny][nx] && nMap[ny][nx])
			{
				dfs(ny, nx);
			}
		}
	}
}

int main(void)
{
	int Loc1, Loc2;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		memset(nMap, 0, sizeof(nMap));
		memset(bChecked, 0, sizeof(bChecked));

		for (int j = 0; j < K; j++)
		{
			cin >> Loc1 >> Loc2;
			nMap[Loc2][Loc1] = 1;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if ((!bChecked[y][x]) && (nMap[y][x] == 1))
				{
					nResult[i]++;
					dfs(y, x);
				}
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		cout << nResult[i] << endl;
	}


	return 0;
}