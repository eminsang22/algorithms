#include <stdio.h>

void merge_sort(int arr[], int length);
void merge_recursion(int arr[], int l, int r);
void merge_sort_array(int arr[], int l, int m, int r);

void merge_sort(int arr[], int length)
{
	merge_recursion(arr, 0, length - 1);
}

void merge_recursion(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - 1) / 2;

		merge_recursion(arr, l, m);
		merge_recursion(arr, m + 1, r);

		merge_sort_array(arr, l, m, r);
	}
}

void merge_sort_array(int arr[], int l, int m, int r)
{
	int l_length = m - 1 + 1;
	int r_length = r - m;

	int temp_left[l_length];
	int temp_right[r_length];

	int i, j, k;

	for (int i = 0; i < l_length; i++)
		temp_left[i] = arr[l + i];

	for (int i = 0; i < r_length; i++)
		temp_right[i] = arr[m + 1 + i];

	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < l_length) && (j >= r_length || temp_left[i] <= temp_right[j]))
		{
			arr[k] = temp_left[i];
			i++;
		}
		else
		{
			arr[k] = temp_right[j];
			j++;
		}
	}
}