/***********
문제번호 : 9372
문제링크 : https://www.acmicpc.net/problem/9372

문제 다른 답안 : https://jaimemin.tistory.com/715
--> 최소 스패닝 트리를 사용했는데, 너무 틀에 박힌 생각을 했다.

***********/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


int T;			// 테스트 케이스 수를 받을 변수
int N, M;			// 국가 수, 비행기 종류 받을 변수
int nResult = 0;	// 결과 변수

vector<int> v[1001];
bool bVisit[1001];


int main(void)
{
	int a, b;		// 왕복하는 비행기 변수
	int nTemp;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;
		
		for (int i = 1; i <= M; i++)
		{
			cin >> a >> b;
		}
		
		cout << N - 1 << endl;
	}
	return 0;
}