#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int nCnt = 1;

int nMap[100][100];
int nChecked[100][100];

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void bfs(int y,int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	nChecked[y][x] = 1;

	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < N && 
				0 <= nx && nx < M )
			{
				if ((nChecked[ny][nx] == 0) && (nMap[ny][nx] == 1))
				{
					q.push(make_pair(ny, nx));
					nChecked[ny][nx] = nChecked[y][x] + 1;
				}
				else if (nChecked[ny][nx] == 0)
				{
					nChecked[ny][nx] = -1;
				}
			}
		}
	}

}
int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//cin >> nMap[i][j];
			scanf("%1d", &nMap[i][j]);
		}
	}

	bfs(0, 0);

	cout << nChecked[N-1][M-1] << endl;

	return 0;
}