/*
문제번호 : 13460
문제링크 : https://www.acmicpc.net/problem/13460
문제이름 : 구슬탈출2

풀이방법 : 기울이기를 고려한 BFS

*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct stINFO {
	int ry;
	int rx;
	int by;
	int bx;
	int count;
}INFO;

int N, M;				// 세로, 가로 변수

INFO start;

char cMap[11][11];		// 구슬 맵

// 서, 북, 동, 남
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int Solve()
{
	queue<INFO> q;
	bool bVisit[10][10][10][10] = { false, };	// 방문기록
	q.push(start);

	bVisit[start.ry][start.rx][start.by][start.bx] = true;

	int nRet = -1;

	while (!q.empty())
	{
		INFO cur = q.front();
		q.pop();

		if (cur.count > 10) break;
		if (cMap[cur.ry][cur.rx] == 'O' && cMap[cur.by][cur.bx] != 'O')
		{
			nRet = cur.count;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			// 빨간 구슬 이동
			while (1)
			{
				if (cMap[next_ry][next_rx] != '#' && cMap[next_ry][next_rx] != 'O')
				{
					next_ry = next_ry + dy[i];
					next_rx = next_rx + dx[i];
				}
				else
				{
					if (cMap[next_ry][next_rx] == '#')
					{
						next_ry = next_ry - dy[i];
						next_rx = next_rx - dx[i];
					}
					break;
				}
			}
			// 파란 구슬 이동
			while (1)
			{
				if (cMap[next_by][next_bx] != '#' && cMap[next_by][next_bx] != 'O')
				{
					next_by = next_by + dy[i];
					next_bx = next_bx + dx[i];
				}
				else
				{
					if (cMap[next_by][next_bx] == '#')
					{
						next_by = next_by - dy[i];
						next_bx = next_bx - dx[i];
					}
					break;
				}
			}

			// 구멍은 아니지만, 기울여서 서로가 같은위치에 있을 때,
			if (next_ry == next_by && next_rx == next_bx)
			{
				if (cMap[next_ry][next_rx] != 'O')
				{
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);

					if (red_dist > blue_dist)
					{
						next_ry -= dy[i];
						next_rx -= dx[i];
					}
					else
					{
						next_by -= dy[i];
						next_bx -= dx[i];
					}
				}
			}

			if (bVisit[next_ry][next_rx][next_by][next_bx] == false)
			{
				bVisit[next_ry][next_rx][next_by][next_bx] = true;
				INFO next;

				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.count = cur.count + 1;
				q.push(next);
			}
		}
	}
	
	// 메모리 정리
	while (!q.empty())
	{
		q.pop();
	}

	return nRet;
}


int main(void)
{

	int nResult = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> cMap[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cMap[i][j] == 'R')
			{
				start.ry = i;
				start.rx = j;
			}
			if (cMap[i][j] == 'B')
			{
				start.by = i;
				start.bx = j;
			}
		}
	}

	start.count = 0;

	nResult = Solve();

	cout << nResult << endl;

	return 0;
}