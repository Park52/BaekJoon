#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> v[1001];
int cdfs[1001];
int cbfs[1001];
void dfs(int start)
{
	if (cdfs[start]) return;
	cdfs[start] = true;

	cout << start << ' ';

	for (int i = 0; i < v[start].size(); i++)
	{
		int y = v[start][i];
		dfs(y);
	}

}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	cbfs[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (!cbfs[y])
			{
				q.push(y);
				cbfs[y] = true;
			}
		}
	}
}
int main(void)
{
	cin >> N >> M >> V;
	int num1, num2;

	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	cout << endl;
	bfs(V);

	return 0;
}