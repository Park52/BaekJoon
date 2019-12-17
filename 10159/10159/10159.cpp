#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M;
int Map[101][101] = { 0, };

void Floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (Map[i][j] == 0)
				{
					if (Map[i][k] == 0 && Map[k][j] == 0)
					{
						Map[i][j] = 0;
					}
					else if (Map[i][k] == -1 && Map[k][j] == -1)
					{
						Map[i][j] = -1;
					}
					else if (Map[i][k] == 1 && Map[k][j] == 1)
					{
						Map[i][j] = 1;
					}
				}
			}
		}
	}
}

int main(void)
{
	int Temp1, Temp2;

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &Temp1, &Temp2);
		Map[Temp1][Temp2] = 1;
		Map[Temp2][Temp1] = -1;
	}

	Floyd();

	for (int i = 1; i <= N; i++)
	{
		int Result = 0;

		for (int j = 1; j <= N; j++)
		{
			if (Map[i][j] == 0 && i != j)
			{
				Result++;
			}
		}
		printf("%d\n", Result);
	}
	return 0;
}