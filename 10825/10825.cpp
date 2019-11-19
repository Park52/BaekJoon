#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct stGRADE {
	string name;
	int kor;
	int eng;
	int math;
}GRADE;

bool cmp(const GRADE &A, const GRADE &B)
{
	if (A.kor > B.kor)
	{
		return true;
	}
	else if (A.kor == B.kor)
	{
		if (A.eng < B.eng)
		{
			return true;
		}
		else if (A.eng == B.eng)
		{
			if (A.math > B.math)
			{
				return true;
			}
			else if (A.math == B.math)
			{
				if (A.name < B.name)
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

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	vector<GRADE> v(N);

	for (int i = 0; i < N; i++)
	{
		//scanf("%s %d %d %d", &v[i].name, &v[i].kor, &v[i].eng, &v[i].math);
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

 	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].name << '\n';
	}
	return 0;
}