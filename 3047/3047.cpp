#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[3];
	char ABC[4];

	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}

	
	for (int i = 0; i < 3; i++)
	{
		scanf(" %c", &ABC[i]);
	}

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++)
	{
		switch (ABC[i])
		{
		case 'A':
			printf("%d ", arr[0]);
			break;
		case 'B':
			printf("%d ", arr[1]);
			break;
		case 'C':
			printf("%d ", arr[2]);
			break;
		}
	}

	printf("\n");
	return 0;
}