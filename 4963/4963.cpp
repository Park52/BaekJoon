#define SEA	0
#define LAND	1

#define NON_VISITED 0
#define VISITED	1


#include <iostream>

using namespace std;

int nResult;

int W, H;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };


int nMap[50][50];
int nChecked[50][50];

void DFS(int nStartY, int nStartX)
{
	nChecked[nStartY][nStartX] = true;

	for (int i = 0; i < 8; i++)
	{
		int ny = nStartY + dy[i];
		int nx = nStartX + dx[i];

		if (ny >= 0 && ny < H &&
			nx >= 0 && nx < W)
		{
			if (NON_VISITED == nChecked[ny][nx] &&
				LAND == nMap[ny][nx])
			{
				DFS(ny, nx);
			}
		}
	}
}


int main()
{
	
	while (1)
	{
		// 사이즈 입력
		cin >> W >> H;
		
		// 0, 0 이면 입력 종료
		if (0 == W && 0 == H)
		{
			break;
		}

		// 초기화 과정
		nResult = 0;
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				nMap[y][x] = 0;
				nChecked[y][x] = 0;
			}
		}
		
		// 입력 과정
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				cin >> nMap[y][x];
			}
		}

		// DFS과정
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				if ( LAND == nMap[y][x] && 
					NON_VISITED == nChecked[y][x])
				{
					DFS(y, x);
					nResult++;
				}
			}
		}


		cout << nResult << endl;
	}
	
	return 0;
	
}