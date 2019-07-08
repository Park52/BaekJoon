#define NOTVALID 0
#define VALID 1

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int IsValid(string str)
{
	int nLength = str.length();
	stack<char> s;

	for (int i = 0; i < nLength; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (!s.empty())
			{
				s.pop();
			}
			else
			{
				return NOTVALID;
			}
		}
	}

	if (!s.empty())
	{
		return NOTVALID;
	}
	else
	{
		return VALID;
	}
}
int main(void)
{
	int T;
	vector<string> stv;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string str;
		stack<char> s1, s2;
		
		cin >> str;
		if (VALID == IsValid(str))
		{
			stv.push_back("YES");
		}
		else
		{
			stv.push_back("NO");
		}
	}

	for (int i = 0; i < T; i++)
	{
		cout << stv[i] << endl;
	}
	return 0;
}