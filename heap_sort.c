#include <stdio.h>

void exchange(int* first, int* second);
void heap_sort(int arr[], int n);
void make_heap(int arr[], int n, int i);

void exchange(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void make_heap(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
        
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
 
    if (largest != i) 
    {
        exchange(&arr[i], &arr[largest]);
        make_heap(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        make_heap(arr, n, i);
    }
        
    for (int i = n - 1; i >= 0; i--) 
    {
        exchange(&arr[0], &arr[i]);
        make_heap(arr, i, 0);
    }
}