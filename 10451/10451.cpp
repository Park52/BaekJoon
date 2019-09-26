#include <iostream>
#include <cstring>

using namespace std;

int T;				// Test case 저장할 변수
int N;				// 순열의 크기
int nArr[1001];		// 순열을 저장 할 배열
bool bVisit[1001];

void DFS(int nStart)
{
	bVisit[nStart] = true;

	int next = nArr[nStart];


	if(!bVisit[next])
	{
		DFS(next);
	}
	
}
int main(void)
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int nCount = 0;
		cin >> N;
		
		memset(bVisit, false, sizeof(bVisit));
		
		for (int j = 1; j <= N; j++)
		{
			cin >> nArr[j];
		}

		for (int j = 1; j <= N; j++)
		{
			if (!bVisit[j])
			{
				DFS(j);
				nCount++;
			}
			
		}
		cout << nCount << endl;
	}
	return 0;
}