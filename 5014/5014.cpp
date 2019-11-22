#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int F, G, S, U, D;
int elevator[2];
bool bResult = false;
bool* bVisit;
int nResult = 1000000;

void BFS()
{
	queue<pair<int, int>> q;

	q.push(make_pair(S, 0));
	bVisit[S] = true;

	while (!q.empty())
	{
		int nPos = q.front().first;
		int nCnt = q.front().second;

		q.pop();

		if (nPos == G)
		{
			bResult = true;
			nResult = min(nResult, nCnt);
		}

		
		for (int i = 0; i < 2; i++)
		{
			int Next = nPos + elevator[i];

			if ((Next <= F) &&( Next > 0) && (false == bVisit[Next]))
			{
				q.push(make_pair(Next, nCnt+1));
				bVisit[Next] = true;
			}
		}
		
	}
}
int main(void)
{
	
	cin >> F >> S >> G >> U >> D;

	elevator[0] = U;
	elevator[1] = D * -1;

	bVisit = (bool*)malloc(sizeof(bool) * F);
	memset(bVisit, false, sizeof(bool) * F);
	BFS();

	if (false == bResult)
	{
		cout << "use the stairs" << '\n';
	}
	else
	{
		cout << nResult << '\n';
	}

	free(bVisit);

	return 0;
}