#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char str[10];
char strcopy[10];

void merge(int left, int mid, int right)
{
	int i, j, k, l;

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (str[i] >= str[j])
		{
			strcopy[k++] = str[i++];
		}
		else
		{
			strcopy[k++] = str[j++];
		}
	}

	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			strcopy[k++] = str[l];
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			strcopy[k++] = str[l];
		}
	}

	for (l = left; l <= right; l++)
	{
		str[l] = strcopy[l];
	}
}

void merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main(void)
{
	int nSize = 0;
	
	scanf("%s", &str);

	nSize = sizeof(str) / sizeof(str[0]);
	merge_sort(0, nSize-1);
	

	printf("%s", str);
	return 0;
}