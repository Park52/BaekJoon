#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{

	return a > b;
}
int main(void)
{
	int T, N, M, Temp;

	scanf("%d", &T);

	while (T--)
	{
		bool bFinishFlag = false;
		int  Result = 0;

		vector<pair<int, bool>> v;
		vector<int> vCopy;

		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &Temp);
			if (Temp < 1 || Temp > 9)
			{
				continue;
			}
			if (i == M)
			{
				v.push_back(make_pair(Temp, true));
			}
			else
			{
				v.push_back(make_pair(Temp, false));
			}
			vCopy.push_back(Temp);
		}

		sort(vCopy.begin(), vCopy.end(), comp);

		while (1)
		{
			int SaveINT = 0;
			bool SaveBOOL = false;
			int Top = 0;

			int Size = v.size();
			if (!v.empty())
			{
				Top = vCopy[0];
				vCopy.erase(vCopy.begin());
			}

			for (int i = 0; i < Size; i++)
			{
				if (v[i].first == Top)
				{
					if (v[i].second == true)
					{
						bFinishFlag = true;
					}

					while(v[0].first != Top)
					{
						SaveINT = (v.begin())->first;
						SaveBOOL = (v.begin())->second;
						v.push_back(make_pair(SaveINT, SaveBOOL));
						v.erase(v.begin());
					}
					v.erase(v.begin());
					Result++;
					break;
				}

			}

			if (bFinishFlag)
			{
				break;
			}

		}

		printf("%d\n", Result);

	}
	return 0;
}