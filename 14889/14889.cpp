#include <iostream>
#include <algorithm>
using namespace std;

int n;

int S[20][20];
int pick[20];
int team1[10], team2[10];
int ret_min = 0x7fffffff;

void update()
{
	int team1_size = 0, team2_size = 0;

	for (int i = 0; i < n; i++)
	{
		if (pick[i] == 0)
		{
			team1[team1_size++] = i;
		}
		else
		{
			team2[team2_size++] = i;
		}
	}

	int sum_1 = 0, sum_2 = 0;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i + 1; j < n / 2; j++) 
		{
			sum_1 += (S[team1[i]][team1[j]] + S[team1[j]][team1[i]]);
			sum_2 += (S[team2[i]][team2[j]] + S[team2[j]][team2[i]]);
		}
	}

	if (ret_min > abs(sum_1 - sum_2))
	{
		ret_min = abs(sum_1 - sum_2);
	}
}

void dfs(int cur, int pick_count)
{
	if (pick_count == (n / 2))
	{
		update();
		return;
	}

	for (int i = cur; i < n; i++)
	{
		pick[i] = 1;
		dfs(i + 1, pick_count + 1);
		pick[i] = 0;
	}
}

int main(void)
{
	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> S[y][x];
		}
	}

	dfs(0, 0);

	cout << ret_min << endl;

	return 0;
}