#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N = 0, S = 0, A[50] = { 0, };

	while (~scanf("%d", &N))
	{
		for(int i = 0; i < N; i++)
		{
			cin >> A[i];
		}

		cin >> S;

		for (int i = 0; i < N && S > 0; i++)
		{
			int nIndex = -1, nMax = -1;
			// k의 목적은 최대한 가까운 요소를 사전순으로 옮기기 위해, 남은 S와 비교
			// 이로인해 O(N^2) 나올 것으로 예상.
			for (int j = i, k = 0; j < N && k <= S; j++, k++)
			{
				if (nMax < A[j])
				{
					nMax = A[j];
					nIndex = j;
				}
			}

			for (int j = nIndex; j > i && S > 0; j--)
			{
				int nTemp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = nTemp;
				S--;
			}
		}

		for (int i = 0; i < N; i++)
		{
			printf("%d ", A[i]);
		}
		cout << endl;
	}

	return 0;
}