#include <iostream>

using namespace std;

int main(void)
{
	int n, k;
	int Money[10];
	int Pivot = 0, result = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> Money[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (1 <= (k / Money[i]))
		{
			Pivot = i;
			break;
		}
	}

	for (int i = Pivot; i >= 0; i--)
	{
		if (k <= 0)
		{
			break;
		}
		result += k / Money[i];
		k %= Money[i];
	}

	cout << result;


}