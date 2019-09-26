#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int narr[1000001];
bool bVisited[1000001];
bool bBelong[1000001];

int T, n;
int nMember;

void DFS(int nStart)
{
	bVisited[nStart] = true;

	int next = narr[nStart];

	if (bVisited[next])
	{
		if (!bBelong[next])
		{
			for (int i = next; nStart != i; i = narr[i])
			{
				nMember++;
			}
			nMember++;
		}
	}
	else
	{
		DFS(next);
	}

	bBelong[nStart] = true;
}
int main(void)
{
	cin >> T;

	// Test Case 수 만큼 증가
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		// 초기화 과정
		memset(bVisited, false, sizeof(bVisited));
		memset(bBelong, false, sizeof(bBelong));
		memset(narr, 0, sizeof(narr));
		nMember = 0;

		// n 입력
		for (int j = 1; j <= n; j++)
		{
			cin >> narr[j];
		}

		for (int j = 1; j <= n; j++)
		{
			if (!bVisited[j])
			{
				DFS(j);
			}
		}
		
 		cout << n - nMember <<endl;
	}
	
	return 0;
}