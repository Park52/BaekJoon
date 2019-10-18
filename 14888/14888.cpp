#include <iostream>

using namespace std;

int n, ret_min = 0x7fffffff, ret_max = ret_min * -1;
int A[11];
int op[4];

void dfs(int result, int count)
{
	if (count == n - 1)
	{
		if (ret_min > result)
		{
			ret_min = result;
		}
		if (ret_max < result)
		{
			ret_max = result;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i] != 0)
		{
			op[i]--;
			if (i == 0)
			{
				dfs(result + A[count + 1], count + 1);
			}
			else if (i == 1)
			{
				dfs(result - A[count + 1], count + 1);
			}
			else if (i == 2)
			{
				dfs(result * A[count + 1], count + 1);
			}
			else if (i == 3)
			{
				dfs(result / A[count + 1], count + 1);
			}
			++op[i];
		}
	}
}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	dfs(A[0], 0);
	

	cout << ret_max << endl << ret_min << endl;


	return 0;
}