#include "sort.h"

/**
 * swap - swap two int's
 *
 * @a: first number
 * @b: second number
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - Partition the array as the pivot
 *
 * @arr: array of int
 * @low: the second argument
 * @high: the third argument
 * @size: size of array
 * Return: Nothing
*/
int partition(int *arr, int low, int high, int size)
{
	int pivot = arr[high];
	int i = low - 1;
	int j = low;

	(void) size;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
		j++;
	}

	if (i + 1 != high)
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}

	return (i + 1);
}

/**
 * quickSort - function that implements QuickSort
 *
 * @arr: array of int
 * @low: the second argument
 * @high: the third argument
 * @size: size of the array
 * Return: Nothing
*/
void quickSort(int *arr, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick
 * sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	quickSort(array, 0, size - 1, size);
}
