#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N, M;
int nResult;
vector<int> v;

void DFS(int Index, int Cnt, int Sum)
{
	if (3 == Cnt && M >= Sum)
	{
		nResult = max(Sum, nResult);
		return;
	}
	if (3 < Cnt || Index >= N || M < Sum)
	{
		return;
	}

	DFS(Index + 1, Cnt + 1, Sum + v[Index]);
	DFS(Index + 1, Cnt, Sum);
}

int main(void)
{

	cin >> N >> M;

	v = vector<int>(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	DFS(0, 0, 0);
	
	cout << nResult << endl;

	return 0;

}