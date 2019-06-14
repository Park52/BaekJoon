#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int time[1001] = { 0 };
	int n;
	int result = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];
	}


	sort(time+1, time + n +1);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			result += time[j];
		}
	}
	
	cout << result;
	
	return 0;
}