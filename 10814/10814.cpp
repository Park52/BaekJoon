#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct stInfo {
	int age;
	string name;
}INFO;

bool cmp(const INFO& A, const INFO& B)
{
	return A.age < B.age;
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	INFO temp;

	cin >> N;

	vector<INFO> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].age >> v[i].name;
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].age << ' ' << v[i].name << '\n';
	}
	return 0;
}