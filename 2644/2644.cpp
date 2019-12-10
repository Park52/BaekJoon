#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF	100000
using namespace std;

vector<int> v[100];
bool Visit[100];

int BFS(int start, int Dest)
{
	int Result = INF;
	queue<pair<int,int>> q;

	Visit[start] = true;

	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int CURIdx = q.front().first;
		int CURVal = q.front().second;

		q.pop();

		if (CURIdx == Dest) 
		{
			Result = min(CURVal, Result);
		}

		for (int i = 0; i < v[CURIdx].size(); i++)
		{
			int NEXTIdx = v[CURIdx][i];

			if (Visit[NEXTIdx] == false)
			{
				q.push(make_pair(NEXTIdx, CURVal+1));
				Visit[NEXTIdx] = true;
			}
		}
	}

	return Result;
}
int main(void)
{
	int n, Target1, Target2, m;
	int Temp1, Temp2;
	int Result = 0;

	scanf("%d", &n);

	scanf("%d%d", &Target1, &Target2);

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &Temp1, &Temp2);
		v[Temp1].push_back(Temp2);
		v[Temp2].push_back(Temp1);
	}

	Result = BFS(Target1, Target2);

	if (Result == INF)
	{
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", Result);
	}
	
	
	return 0;

}