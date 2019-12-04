#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define INF            10000000
int n, m;
int Map[101][101] = { 0, };

void Floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (Map[i][j] > Map[i][k] + Map[k][j])
				{
					Map[i][j] = Map[i][k] + Map[k][j];
				}
			}
		}
	}
}

int main(void)
{
	int Temp1, Temp2, Temp3;

	scanf("%d", &n);
	scanf("%d", &m);
	// 초기화 과정
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				Map[i][j] = 0;
			}
			else
			{
				Map[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &Temp1, &Temp2, &Temp3);
		if (Map[Temp1][Temp2] != INF)
		{
			if (Map[Temp1][Temp2] > Temp3)
			{
				Map[Temp1][Temp2] = Temp3;
			}
		}
		else
		{
			Map[Temp1][Temp2] = Temp3;
		}
	}

	Floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (Map[i][j] == INF)
			{
				printf("%d ", 0);
			}
			else
			{
				printf("%d ", Map[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}