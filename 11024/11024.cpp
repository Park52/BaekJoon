#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(void)
{
	int T = 0;

	cin >> T;

	cin.ignore();

	while (T--)
	{
		string str;
		int nSize = 0;
		int nResult = 0;
		int nTemp = 0;

		getline(cin, str);
		str += '\n';
		nSize = str.size();

		int nStartIdx = 0;
		char cTemp[5] = { 0, };
		for(int i = 0; i < nSize; i++)
		{
			if (str[i] == ' ' || str[i] == '\n')
			{
				for (int k = 0, j = nStartIdx; k < 5 && j < i; j++, k++)
				{
					cTemp[k] = str[j];
				}

				nTemp = atoi(cTemp);

				nResult += nTemp;
				memset(cTemp, 0, 5);
				nStartIdx = i + 1;
			}
		}

		cout << nResult << endl;
	}

	
	return 0;
}

