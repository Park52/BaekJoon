#include <iostream>

using namespace std;

// N극 0, S극 1
char t[4][9];
int k;

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		cin >> t[i];
	}

	cin >> k;
	while (k--)
	{
		int target, cmd;

		cin >> target >> cmd;
		--target;
		int move_cmd[4] = { 0, };
		move_cmd[target] = cmd;
		for (int left = target - 1; left >= 0; left--)
		{
			int right = left + 1;
			if (t[left][2] == t[right][6])
			{
				break;
			}
			else
			{
				move_cmd[left] = move_cmd[right] * -1;
			}
		}

		for (int right = target + 1; right < 4; right++)
		{
			int left = right - 1;
			if (t[left][2] == t[right][6])
			{
				break;
			}
			else
			{
				move_cmd[right] = move_cmd[left] * -1;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (move_cmd[i] == 1)
			{
				char temp = t[i][7];
				for (int j = 7; j >= 1; j--)
				{
					t[i][j] = t[i][j - 1];
				}
				t[i][0] = temp;
			}
			else if (move_cmd[i] == -1)
			{
				char temp = t[i][0];
				for (int j = 0; j < 7; j++)
				{
					t[i][j] = t[i][j + 1];
				}
				t[i][7] = temp;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (t[i][0] == '1') 
		{
			ret += (1 << i);
		}
	}

	cout << ret << endl;
	return 0;
}