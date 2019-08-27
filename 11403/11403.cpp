#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int N;

int nMap[101][101];
int nAns[101][101];
int nChecked[101][101];

queue<int> q;

void BFS(int y)
{
	q.push(y);
	while (!q.empty())
	{
		int cy = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (nMap[cy][i] == 1 && nChecked[cy][i] == 0)
			{
				nAns[y][i] = 1;
				nChecked[cy][i] = 1;
				q.push(i);
			}
		}
	}

}
int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> nMap[i][j];
		}
	}

	for (int y = 1; y <= N; y++)
	{
		BFS(y);

		memset(nChecked, 0, sizeof(nChecked));
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << nAns[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}