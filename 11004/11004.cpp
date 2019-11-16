/*
첫 번째 시도: 시간 초과 
sort 함수는 quickosrt 정렬
두 번째 시도: cin, cout >> scanf, printf 변경 --> 성공

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, K;
int* arr;
int* copyarr;

void Merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			copyarr[k++] = arr[i++];
		}
		else
		{
			copyarr[k++] = arr[j++];
		}
	}

	if (i > mid)
	{
		for (int l = j; l <= right; l++)
		{
			copyarr[k++] = arr[l];
		}
	}
	else
	{
		for (int l = i; l <= mid; l++)
		{
			copyarr[k++] = arr[l];
		}
	}

	for (int l = left; l <= right; l++)
	{
		arr[l] = copyarr[l];
	}
}

void Merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		Merge_sort(left, mid);
		Merge_sort(mid+1, right);
		Merge(left, mid, right);
	}
}
int main(void)
{
	int nTemp;
	

	scanf("%d %d", &N, &K);

	arr = (int*)malloc(sizeof(int) * N);
	copyarr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &nTemp);
		arr[i] = nTemp;
	}

	// sort(arr, arr+N);
	Merge_sort(0, N - 1);

	printf("%d\n", arr[K - 1]);

	free(arr);
	free(copyarr);

	return 0;
}