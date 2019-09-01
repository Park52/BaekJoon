#define MAX_INF 100000

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nGraph[101][101];

int N, M;

void FloydWarshall()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (nGraph[i][k] != 0 && nGraph[k][j] != 0 && i != j)
				{
					if (nGraph[i][j] == 0)
					{
						nGraph[i][j] = nGraph[i][k] + nGraph[k][j];
					}
					else
					{
						nGraph[i][j] = min(nGraph[i][j], nGraph[i][k] + nGraph[k][j]);
					}
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	
	int nFriend1, nFriend2;


	for (int i = 1; i <= M; i++)
	{
		cin >> nFriend1 >> nFriend2;

		nGraph[nFriend2][nFriend1] = 1;
		nGraph[nFriend1][nFriend2] = 1;
	}

	FloydWarshall();

	int min = MAX_INF;
	int sum = 0;
	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sum += nGraph[i][j];
		}
		if (min > sum)
		{
			min = sum;
			ans = i;
		}
		sum = 0;
	}

	cout << ans << endl;
}