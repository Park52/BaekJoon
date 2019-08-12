#include <iostream>
#include <vector>

using namespace std;

int k, S, nLast;

vector<int> v;
vector<int> vVisited;

void DFS(int nIndex, int nCount)
{
	if (nIndex == k && nCount == 6)
	{
		for (int i = 0; i < k; i++)
		{
			if (vVisited[i] == 1)
			{
				cout << v[i] << " ";
			}
		}
		cout << endl;
	}

	if (nIndex == k)
	{
		return;
	}

	vVisited[nIndex] = 1;
	DFS(nIndex + 1, nCount + 1);

	vVisited[nIndex] = 0;
	DFS(nIndex + 1, nCount);

}

int main(void)
{
	while (true)
	{
		cin >> k;
		if (0 == k)
		{
			break;
		}

		v = vector<int>(k, 0);
		vVisited = vector<int>(k, 0);

		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}

		DFS(0, 0);
		cout << endl;
	}


	return 0;
}