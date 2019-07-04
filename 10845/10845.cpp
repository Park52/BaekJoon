#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N;
queue<int> q;

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
			q.push(nData);
		}
		else if (str == "pop")
		{
			if (!q.empty())
			{
				Num = q.front();
				q.pop();
			}
			else
			{
				Num = -1;
			}
			cout << Num << endl;
		}
		else if (str == "size")
		{

			cout << q.size() << endl;

		}
		else if (str == "empty")
		{
			if (q.size() == 0) Num = 1;
			else Num = 0;
			cout << Num << endl;
		}
		else if (str == "front")
		{
			if (q.size() == 0)
			{
				Num = -1;
			}
			else
			{
				Num = q.front();
			}
			cout << Num << endl;
		}
		else if (str == "back")
		{
			if (q.size() == 0)
			{
				Num = -1;
			}
			else
			{
				Num = q.back();
			}
			cout << Num << endl;
		}

	}


	return 0;
}