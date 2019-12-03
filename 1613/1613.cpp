#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int n, k, s;

int nMap[401][401];

void Floyd()
{
	
	/*
		플로이드 와샬 구현
	*/
	for (int a = 1; a <= n; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			for (int c = 1; c <= n; c++)
			{
				if (nMap[b][c] == 0)
				{
					if (nMap[b][a] == 0 && nMap[a][c] == 0)
					{
						nMap[b][c] = 0;
					}
					else if (nMap[b][a] == -1 && nMap[a][c] == -1)
					{
						nMap[b][c] = -1;
					}
					else if (nMap[b][a] == 1 && nMap[a][c] == 1)
					{
						nMap[b][c] = 1;
					}
				}
			}
		}
	}
	
}
int main(void)
{
	int nTemp1, nTemp2;

	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &nTemp1, &nTemp2);
		nMap[nTemp1][nTemp2] = -1;
		nMap[nTemp2][nTemp1] = 1;
	}

	scanf("%d", &s);
	Floyd();

	for (int i = 0; i < s; i++)
	{
		
		scanf("%d %d",&nTemp1, &nTemp2);
		printf("%d\n", nMap[nTemp1][nTemp2]);
	}
	return 0;
}