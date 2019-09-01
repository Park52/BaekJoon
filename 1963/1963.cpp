#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T;
int* pnArr;
int nCount[10000];

vector<int> v;

void InitPrime(void)
{
	pnArr = (int*)malloc(sizeof(int*) * 10000);
	
	for (int i = 2; i < 10000; i++)
	{
		pnArr[i] = i;
	}

	for (int i = 2; i < 10000; i++)
	{
		if (pnArr[i] == 0)
		{
			continue;
		}
		for (int j = i + i; j < 10000; j+= i)
		{
			pnArr[j] = 0;
		}
	}
}

void BFS(int nStart, int nDest, int nDepth)
{
	memset(nCount, 0, sizeof(nCount));

	queue<int> q;
	q.push(nStart);

	while (!q.empty())
	{
		int nSize = q.size();

		for (int i = 0; i < nSize; i++)
		{
			int nTemp = q.front();
			q.pop();

			if (nTemp == nDest)
			{
				return;
			}

			string strNum = to_string(nTemp);
			for (int j = 0; j < 4; j++)
			{
				string strTemp = string(strNum);
				for (int k = '0'; k <= '9'; k++)
				{
					strTemp[j] = k;
					int nTest = stoi(strTemp);
					if (pnArr[nTest] && !nCount[nTest] && nTest >= 1000)
					{
						nCount[nTest] = 1;
						q.push(nTest);
					}
				}
			}
		}

		v[nDepth]++;
	}
}
int main(void) 
{
	cin >> T;

	int nFrom, nTo;
	
	InitPrime();

	v.assign(T, 0);

	for (int i = 0; i < T; i++)
	{
		cin >> nFrom >> nTo;
		BFS(nFrom, nTo, i);
	}

	for (int i = 0; i < T; i++)
	{
		cout << v[i] << endl;
	}

	free(pnArr);

	return 0;
}