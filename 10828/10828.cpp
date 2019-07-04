#include <stack>
#include <iostream>
#include <string>

using namespace std;

int N;
stack<int> s;

int main(void)
{
	cin >> N;
	int Num;
	for (int i = 0; i < N; i++)
	{
		//getline(cin, str);
		string str;
		cin >> str;

		if (str == "push")
		{
			int nData;
			cin >> nData;
			s.push(nData);
		}
		else if (str == "pop")
		{
			if (!s.empty())
			{
				Num = s.top();
				s.pop();
			}
			else
			{
				Num = -1;
			}
			cout << Num << endl;
		}
		else if (str == "size")
		{

			cout << s.size() << endl;

		}
		else if (str == "empty")
		{
			if (s.size() == 0) Num = 1;
			else Num = 0;
			cout << Num << endl;
		}
		else if (str == "top")
		{
			if (s.size() == 0)
			{
				Num = -1;
			}
			else
			{
				Num = s.top();
			}
			cout << Num << endl;
		}

	}


	return 0;
}