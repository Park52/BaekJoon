#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;

	scanf("%d", &N);

	vector<long long> v(N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &v[i]);
	}

	sort(v.begin(), v.end());

	int nCount = 0;
	int nMax = 0;
	long long nMaxVal = v[0];

	for (int i = 1; i < N; i++)
	{
		if (v[i] == v[i - 1])
		{
			nCount++;
		}
		else
		{
			nCount = 0;
		}

		if (nMax < nCount)
		{
			nMax = nCount;
			nMaxVal = v[i];
		}
	}

	printf("%lld\n", nMaxVal);

	return 0;
}