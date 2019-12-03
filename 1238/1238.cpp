#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

#define INF 10000000

int N, M, X;

int nMap[1001][1001];

void Floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (nMap[i][k] + nMap[k][j] < nMap[i][j])
				{
					nMap[i][j] = nMap[i][k] + nMap[k][j];
				}
			}
		}
	}
}

int main(void)
{
	int nTemp1, nTemp2, nTemp3;
	int nResult = 0;
	scanf("%d%d%d", &N, &M, &X);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				nMap[i][j] = 0;
			}
			else
			{
				nMap[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d%d", &nTemp1, &nTemp2, &nTemp3);
		nMap[nTemp1][nTemp2] = nTemp3;
	}

	Floyd();

	for (int i = 1; i <= N; i++)
	{
		nResult = std::max(nResult, nMap[i][X] + nMap[X][i]);
	}

	printf("%d\n", nResult);
	return 0;
}