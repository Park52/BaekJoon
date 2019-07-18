#define WHITE 0
#define BLACK 1

#include <iostream>

#include <algorithm>

using namespace std;

int nMap[101][101];
int nCheck[101][101];


int M, N, K;

int nResult = 0;
int nCntOfSector[101];


int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y, int Depth)
{
	nCheck[x][y] = 1;
	nCntOfSector[Depth]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (WHITE == nMap[nx][ny] && 0 == nCheck[nx][ny])
			{
				DFS(nx, ny, Depth);
			}
		}
	}

}
int main(void)
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int xMin, yMin, xMax, yMax;
		cin >> xMin >> yMin >> xMax >> yMax;
		for (int x = xMin; x < xMax; x++)
		{
			for (int y = yMin; y < yMax; y++)
			{
				nMap[x][y] = BLACK;
			}
		}
	}

	for (int x = N-1; x >= 0; x--)
	{
		for (int y = M-1; y >= 0; y--)
		{
			if (WHITE == nMap[x][y] && 0 == nCheck[x][y] )
			{
				DFS(x, y, nResult);
				nResult++;
			}
		}
	}

	cout << nResult << endl;

	sort(nCntOfSector, nCntOfSector + nResult);
	for (int i = 0; i < nResult; i++)
	{
		cout << nCntOfSector[i] << " ";
	}
	return 0;
}