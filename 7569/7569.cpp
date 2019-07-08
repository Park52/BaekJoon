#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, H;

int nMap[100][100][100];
int nCheck[100][100][100];

int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };

int nResult;



int main(void)
{
	queue < pair<int, pair<int, int>>> q;

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> nMap[k][i][j];
				nCheck[k][i][j] = -1;

				if (nMap[k][i][j] == 1)
				{
					q.push(make_pair(k, make_pair(i, j)));
					nCheck[k][i][j] = 0;
				}
			}
		}
	}

	while (!q.empty())
	{
		int z = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= nz && nz < H &&
				0 <= ny && ny < N &&
				0 <= nx && nx < M)
			{
				if ((nMap[nz][ny][nx] == 0) && (nCheck[nz][ny][nx] == -1))
				{
					nCheck[nz][ny][nx] = nCheck[z][y][x] + 1;
					q.push(make_pair(nz, make_pair(ny, nx)));
				}
			}
		}
	}

	int nResult = 0;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				nResult = max(nResult, nCheck[k][i][j]);
			}
		}
	}

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if ((nMap[k][i][j] == 0) && (nCheck[k][i][j] == -1))
				{
					nResult = -1;
					break;
				}
			}
		}
	}

	cout << nResult << endl;
	return 0;
}