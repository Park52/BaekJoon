#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int X;
int Y;

void DFS(int x, int y)
{

}
int main(void)
{
	char map[51][51] = { 0, };
	int Distance[51][51] = { 0, };
	cin >> X >> Y;

	queue<pair<int, int>> StartP;

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cin >> map [i][j];
			if (map[i][j] == 'L')
			{
				StartP.push(make_pair(i, j));
			}
		}
	}

	int nResult = 0;

	while (!StartP.empty())
	{
		int Start_x = StartP.front().first;
		int Start_y = StartP.front().second;

		StartP.pop();

		memset(Distance, 0, sizeof(Distance));

		queue<pair<int, int>> q;
		q.push(make_pair(Start_x, Start_y));

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
				{
					continue;
				}

				if (map[nx][ny] == 'W' || (Start_x == nx && Start_y == ny))
				{
					continue;
				}

				if (!Distance[nx][ny] || Distance[nx][ny] > Distance[x][y] + 1)
				{
					Distance[nx][ny] = Distance[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}

		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (Distance[i][j])
				{
					nResult = max(nResult, Distance[i][j]);
				}
			}
		}
	}

	cout << nResult << endl;

	return 0;
}