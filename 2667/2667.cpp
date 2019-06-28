#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>


using namespace std;


const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

int N;

int nHome[25][25] = { 0, };
bool cChecked[25][25] = { false, };

int nCnt;
int nNumofSection[25 * 25] = { 0, };

void DFS(int x, int y)
{
	cChecked[x][y] = true;
	nNumofSection[nCnt]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N &&
			0 <= ny && ny < N)
		{
			if (!cChecked[nx][ny] && nHome[nx][ny])
			{
				DFS(nx, ny);
			}
		}
	}

	return;
}
int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &nHome[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((!cChecked[i][j]) && (nHome[i][j] == 1))
			{
				DFS(i, j);
				nCnt++;
			}
		}
	}

	cout << nCnt << endl;

	sort(nNumofSection, nNumofSection + nCnt);

	for (int i = 0; i < nCnt; i++)
	{
		cout << nNumofSection[i] << endl;
	}
	return 0;
}