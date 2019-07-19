#define NON_VISITED		false
#define VISITED			true

#include <iostream>
#include <queue>

using namespace std;

int N;
char cMap[101][101];
bool bVisited[100][100];

int dy[4] = { 0, 1,  0, -1};
int dx[4] = { -1, 0, 1, 0 };
 
int nResult1 = 0, nResult2= 0;

void DFS(int StartY, int StartX)
{
	bVisited[StartY][StartX] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = StartY + dy[i];
		int nx = StartX + dx[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < N)
		{
			if ( NON_VISITED == bVisited[ny][nx] && 
				 cMap[ny][nx] == cMap[StartY][StartX])
			{
				DFS(ny, nx);
			}
		}
	}

}


int main(void)
{
	cin >> N;
	// 초기화 과정
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			bVisited[y][x] = NON_VISITED;
		}
	}

	// 입력 과정
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> cMap[y][x];
		}
	}

	// 적록색약이 아닌 사람 DFS
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (NON_VISITED == bVisited[y][x])
			{
				DFS(y, x);
				nResult1++;
			}
		}
	}

	// 다시 초기화
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			bVisited[y][x] = NON_VISITED;
			if (cMap[y][x] == 'G')
			{
				cMap[y][x] = 'R';
			}
		}
	}
	
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (	bVisited[y][x] == NON_VISITED )
			{
				DFS(y, x);
				nResult2++;
			}
		}
	}

	cout << nResult1 << " " << nResult2 << endl;
	return 0;
}