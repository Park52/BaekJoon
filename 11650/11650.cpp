#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct stPOS {
	int x;
	int y;
}POS;

bool cmp(const POS& A, const POS& B)
{
	if (A.x < B.x)
	{
		return true;
	}
	else if (A.x == B.x)
	{
		if (A.y < B.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main(void)
{
	int N;

	cin >> N;
	
	vector<POS> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].x >> v[i].y;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
	return 0;
}