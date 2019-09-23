#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10001];
bool bVisited[10001];
int nHackingCount[10001] = { 0, };

int N, M;

void DFS(int nStart)
{
	nHackingCount[nStart]++;
	
	for (int i = 0; i < v[nStart].size(); i++)
	{
		int nNextStart = v[nStart][i];
		if (false == bVisited[nNextStart])
		{
			bVisited[nNextStart] = true;
			DFS(nNextStart);
		}
	}
}
int main(void)
{
	cin >> N >> M;
	int nComputer1, nComputer2;

	for (int i = 0; i < M; i++)
	{
		cin >> nComputer1 >> nComputer2;
		v[nComputer1].push_back(nComputer2);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(bVisited, false, sizeof(bVisited));
		bVisited[i] = true;
		DFS(i);
	}

	int nTempMax = 0;

	for (int i = 1; i <= N; i++)
	{
		nTempMax = max(nTempMax, nHackingCount[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (nTempMax == nHackingCount[i])
		{
			printf("%d ",i);
		}
	}
	cout << endl;

	return 0;
}