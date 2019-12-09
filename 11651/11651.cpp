#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct stPOS {
	int x;
	int y;
}POS;

bool cmp(const POS A, const POS B)
{
	if (A.y < B.y)
	{
		return true;
	}
	else if (A.y == B.y)
	{
		if (A.x < B.x)
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
	vector<POS> v;
	POS Temp;
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &Temp.x, &Temp.y);
		v.push_back(Temp);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		printf("%d %d\n", v[i].x, v[i].y);
	}

	return 0;
}
