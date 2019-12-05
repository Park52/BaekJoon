#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int Temp1, Temp2;
	int Result[4] = { 0 };
	int TempRes = 0;

	for (int i = 0; i < 4; i++)
	{
		scanf("%d%d",&Temp1, &Temp2);
		TempRes += (Temp2 - Temp1);
		Result[i] = TempRes;
	}

	sort(Result, Result+4);

	printf("%d\n", Result[3]);

	return 0;
}
