#include <iostream>
#include <algorithm>

using namespace std;

int copyarr[50];

bool GreaterThan(int a, int b)
{
	return a > b;
}

void merge(int list[], int left, int right, bool Ascending)
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if(false == Ascending)
		{
			if (list[i] <= list[j])
			{
				copyarr[k++] = list[j++];
			}
			else
			{
				copyarr[k++] = list[i++];
			}
		}
		else
		{
			if (list[i] <= list[j])
			{
				copyarr[k++] = list[i++];
			}
			else
			{
				copyarr[k++] = list[j++];
			}
		}
	}

	int temp = i > mid ? j : i;

	while (k <= right)
	{
		copyarr[k++] = list[temp++];
	}

	for (int i = left; i <= right; i++)
	{
		list[i] = copyarr[i];
	}
}
void Merge_sort(int list[], int left, int right, bool Ascending)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		Merge_sort(list, left, mid, Ascending);
		Merge_sort(list, mid + 1, right, Ascending);
		merge(list, left, right, Ascending);
	}
}


int main(void)
{
	int N = 0;
	int nResult = 0;
	int A[50] = { 0, };
	int B[50] = { 0, };
	int CopyB[50] = { 0, };
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
		CopyB[i] = B[i];
	}

	Merge_sort(A, 0, N - 1, false);

	Merge_sort(CopyB, 0, N - 1, true);

	//sort(A, A + N, GreaterThan);
	//sort(CopyB, CopyB + N);

	for (int i = 0; i < N; i++)
	{
		nResult += (A[i] * CopyB[i]);
	}

	cout << nResult << endl;
	
	return 0;
}