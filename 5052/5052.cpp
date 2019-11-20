/***********************************************
첫 번째 시도: 시간 초과
-> 이중 포문으로 인한 문자열 탐색이 원인인 듯
두 번째 시도: sort -> 사전순으로 전화번호가 정렬
-> 
***********************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t;
	int n;

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);

		vector<string> v(n);
		bool isPrefix = false;

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		
		sort(v.begin(), v.end());

		for (int i = 1; i < n; i++)
		{
			string foo = v[i-1];
			string foobar = v[i];

			if (foobar.find(foo) != string::npos)
			{
				isPrefix = true;
				break;
			}
		}


		if (true == isPrefix)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}

	return 0;
}