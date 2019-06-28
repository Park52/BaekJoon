#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cChecked[101] ;

int bfs(int start, vector<int> a[])
{
	int nResult = 0;
	queue<int> q;
	q.push(start);
	cChecked[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (!cChecked[y])
			{
				nResult++;
				q.push(y);
				cChecked[y] = true;
			}
		}
	}

	return nResult;
}
int main(void)
{
	int nCountOfComputer = 0;
	int nCouple = 0;
	int nInfected = 0;

	
	vector<int> vNetwork[101];

	cin >> nCountOfComputer;

	cin >> nCouple;
	
	for (int i = 0; i < nCouple; i++)
	{
		int nTemp1, nTemp2;
		cin >> nTemp1 >> nTemp2;

		vNetwork[nTemp1].push_back(nTemp2);
		vNetwork[nTemp2].push_back(nTemp1);
	}

	nInfected = bfs(1, vNetwork);

	cout << nInfected;

	return 0;
}