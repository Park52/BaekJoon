/*
문제 번호: 12100
문제 링크: https://www.acmicpc.net/problem/12100
문제 이름: 2048(easy)

문제 풀이: DFS
참고 블로그 : https://na982.tistory.com/83?category=145346
*/

#include <iostream>

using namespace std;

int N;		// 보드의 크기
int nResult;	// 결과 값

typedef struct stBOARD {
	int nMap[20][20];

	void rotate()
	{
		int nTemp[20][20];

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				nTemp[y][x] = nMap[N - x - 1][y];
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				nMap[y][x] = nTemp[y][x];
			}
		}
	}

	int get_max()
	{
		int ret = 0;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (ret < nMap[y][x])
				{
					ret = nMap[y][x];
				}
			}
		}
		return ret;
	}

	void up()
	{
		int nTemp[20][20];

		for (int x = 0; x < N; x++)
		{
			int nFlag = 0, target = -1;
			for (int y = 0; y < N; y++)
			{
				if(nMap[y][x] == 0)
				{
					continue;
				}
				if (nFlag == 1 && nMap[y][x] == nTemp[target][x])
				{
					nTemp[target][x] *= 2, nFlag = 0;
				}
				else
				{
					nTemp[++target][x] = nMap[y][x], nFlag = 1;
				}
			}

			for (++target; target < N; ++target)
			{
				nTemp[target][x] = 0;
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				nMap[y][x] = nTemp[y][x];
			}
		}
	}
}BOARD;

void DFS(BOARD cur, int nCount)
{
	if (nCount == 5)
	{
		int nTemp = cur.get_max();
		if (nResult < nTemp)
		{
			nResult = nTemp;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		BOARD next = cur;
		next.up();
		DFS(next, nCount + 1);
		cur.rotate();
	}
}

int main(void)
{
	BOARD board;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board.nMap[i][j];
		}
	}

	nResult = 0;
	DFS(board, 0);

	cout << nResult << endl;

	return 0;
	
}