/*******************
첫번째 시도 : 시간 초과
두번째 시도 : 통과

********************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v_b, v_t, vResult;

int main(void)
{
	int N, H;
	int tempA, tempB;
	
	cin >> N >> H;
	
	for (int i = 0; i < N / 2; i++)
	{
		cin >> tempA >> tempB;
		
		v_b.push_back(H - tempA);
		v_t.push_back(tempB);
	}
	sort(v_b.begin(), v_b.end());
	sort(v_t.begin(), v_t.end());

	for (int i = 1; i <= H; i++)
	{
		int nCnt = 0;

		vector<int>::iterator low = lower_bound(v_b.begin(), v_b.end(), i);
		nCnt = low - v_b.begin();

		vector<int>::iterator high = lower_bound(v_t.begin(), v_t.end(), i);
		
		nCnt += v_t.size() - (high - v_t.begin());
		vResult.push_back(nCnt);
	}

	sort(vResult.begin(), vResult.end());

	int nResult = 1;
	for (int i = 1; i < vResult.size(); i++)
	{
		if (vResult[0] == vResult[i])
		{
			nResult++;
		}
	}

	printf("%d %d\n", vResult[0], nResult);
	
	return 0;
}