/*
문제 링크 : https://www.acmicpc.net/problem/13458

문제 풀이 : 그리디? 브루트포스?
문제 풀이 참고 블로그 : https://na982.tistory.com/85?category=145346

*/

#include <iostream>

using namespace std;

int nTestPeople[1000001];

int main(void)
{
	int N;		// 시험장의 개수
	int B, C;
	long long nResult = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{	
		cin >> nTestPeople[i];
	}

	cin >> B >> C;

	for (int i = 1; i <= N; i++)
	{
		nTestPeople[i] -= B;
		nResult++;
		if (nTestPeople[i] > 0)
		{
			nResult += nTestPeople[i] / C;
			if (nTestPeople[i] % C != 0)
			{
				nResult++;
			}
		}
	}

	cout << nResult << endl;

	return 0;
}