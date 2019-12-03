#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int N;
int Answer = 100000;
int Map[100][100];
bool Visit[100][100];

vector<pair<int, int>> v;

void Make_Number(int y, int x, int Label)
{
	queue<pair<int, int>> q;

	q.push(make_pair(y, x));
	Visit[y][x] = true;
	Map[y][x] = Label;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (Visit[ny][nx] == false && Map[ny][nx] == -1)
				{
					Visit[ny][nx] = true;
					Map[ny][nx] = Label;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

}

int BFS(int islandNum)
{
	int Result = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == islandNum)
			{
				q.push(make_pair(i, j));
				Visit[i][j] = true;
				//육지이기때문에, 방문표시
			}
		}
	}

	while (!q.empty())
	{
		int S = q.size();

		for (int i = 0; i < S; i++)
		{
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny >= 0 && ny < N && nx >= 0 && nx < N)
				{
					if (Map[ny][nx] != 0 && Map[ny][nx] != islandNum)
					{
						return Result;
					}
					else if (Map[ny][nx] == 0 && Visit[ny][nx] == false)
					{
						q.push(make_pair(ny, nx));
						Visit[ny][nx] = true;
					}
				}
			}
		}
		Result++;
	}
}

int main(void)
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 1)
			{
				Map[i][j] = -1;
				v.push_back(make_pair(i, j));
			}
		}
	}

	// 육지 서로 다른 번호 매기기.

	int LabelNum = 1;
	for (int i = 0; i < v.size(); i++)
	{
		int y = v[i].first;
		int x = v[i].second;

		if (Visit[y][x] == false)
		{
			Make_Number(y, x, LabelNum);
			LabelNum++;
		}
	}

	memset(Visit, false, sizeof(Visit));
	
	for (int i = 1; i < LabelNum; i++)
	{
		Answer = min(Answer, BFS(i));
		memset(Visit, false, sizeof(Visit));
	}

	cout << Answer << endl;
	
	
	return 0;
}