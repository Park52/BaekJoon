#include <iostream>
#include <algorithm>
#include <queue>
#define visited true
#define Non_visited false

using namespace std;

queue<int> idx;
int ans = 0;

void Check(bool* check, int* arry2, int num) 
{
	for (int i = 0; i < num; i++)
	{
		int TempVal = arry2[i];
		int TempIdx = i;

		if (check[i] == visited)
		{
			TempVal = -1;
			TempIdx = -1;
		}

		for (int j = 0; j < num; j++)
		{
			if (check[j] == visited)
			{
				continue;
			}
			if (TempVal < arry2[j])
			{
				TempVal = arry2[j];
				TempIdx = j;
			}
		}

		idx.push(TempIdx);
		check[TempIdx] = visited;
	}
}


int main() {
	int num, j = 0;
	cin >> num;

	int* arry = new int[num];
	int* arry2 = new int[num];
	bool* check = new bool[num];

	for (int i = 0; i < num; i++) {
		cin >> arry[i];
	}

	for (int i = 0; i < num; i++) {
		check[i] = Non_visited;
	}

	for (int i = 0; i < num; i++) {
		cin >> arry2[i];
	}

	sort(arry, arry + num);

	Check(check, arry2, num);

	while (!idx.empty()) {
		int i = idx.front();
		idx.pop();

		ans += arry[j] * arry2[i];
		j++;
	}

	cout << ans << endl;

	delete[] arry;
	delete[] arry2;
	delete[] check;

	return 0;
}