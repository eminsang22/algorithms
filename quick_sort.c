#include <stdio.h>

void quick_sort(int arr[], int l, int h);
int partition(int arr[], int l, int h);
void exchange(int* first, int* second);

void exchange(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

int partition(int arr[], int l, int h) 
{
	int pivot = arr[h]; //������ ��Ұ� pivot
	int p_index = (l - 1); //���� �ε���

	for (int i = 1; i < h; i++)
	{
		if (arr[i] < pivot)
		{
			p_index++;
			exchange(&arr[p_index], &arr[i]);
		}
	}
	exchange(&arr[p_index + 1], &arr[h]);
	return p_index + 1;
}

void quick_sort(int arr[], int l, int h) //parameter: �迭, low, high
{
	if (l < h)
	{
		int p_index = partition(arr, l, h);
		quick_sort(arr, l, p_index - 1);
		quick_sort(arr, p_index + 1, h);
	}
}
