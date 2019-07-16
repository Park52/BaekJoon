#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int nResult = 0;
bool bChecked[2000];
vector<int> vConnected[2000];


bool DFS(int nStart, int nDepth)
{
	if (5 == nDepth)
	{
		return true;
	}

	bChecked[nStart] = true;

	for (int i = 0; i < vConnected[nStart].size(); i++)
	{
		int y = vConnected[nStart][i];
		if (!bChecked[y])
		{
			if (DFS(y, nDepth + 1))
			{
				return true;
			}
		}
	}

	bChecked[nStart] = false;
	return false;
}
int main(void)
{
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int nFriend1, nFriend2;
		cin >> nFriend1 >> nFriend2;

		vConnected[nFriend1].push_back(nFriend2);
		vConnected[nFriend2].push_back(nFriend1);
	}

	for (int i = 0; i < N; i++)
	{
		if (DFS(i, 1))
		{
			nResult = 1;
		}
	}

	cout << nResult << endl;

	return 0;
}