#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int nTest;
int l;

int nDestY, nDestX;
int nCurY, nCurX;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void BFS(int y, int x)
{
	queue<pair<int, pair<int, int>>> q;
	int nChecked[300][300] = { false, };

	q.push(make_pair(0, make_pair(y, x)));
	nChecked[y][x] = true;

	while(!q.empty())
	{
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		int cnt = q.front().first;

		q.pop();
		if (cy == nDestY && cx == nDestX)
		{
			cout << cnt << endl;
			break;
		}

		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < l && nx >= 0 && nx < l)
			{
				if (false == nChecked[ny][nx])
				{
					nChecked[ny][nx] = true;
					q.push(make_pair(cnt + 1, make_pair(ny, nx)));
				}
			}
		}
	}
}

int main(void)
{
	cin >> nTest;

	for (int i = 0; i < nTest; i++)
	{
		cin >> l;
		cin >> nCurX >> nCurY;
		cin >> nDestX >> nDestY;

		BFS(nCurY, nCurX);
	}

	return 0;

}