#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(void)
{
	int X, Stick = 0;
	
	int Seperated[7] = { 32, 16, 8, 4, 2, 1, 1 };

	int Count = 1;
	int i = 0;

	scanf("%d", &X);

	while (1)
	{
		
		// 원래 길이
		if (X == 64)
		{
			break;
		}
		Stick += Seperated[i];

		if (X == Stick)
		{
			break;
		}
		else if (Stick > X)
		{
			Stick -= Seperated[i];
		}
		else if (Stick < X)
		{
			Count++;
		}
		i++;
		
	}

	printf("%d\n", Count);
	return 0;
}