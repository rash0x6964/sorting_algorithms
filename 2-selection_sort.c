#include "sort.h"

/**
 * swap - swap two int's
 *
 * @a: first number
 * @b: second number
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection
 * sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, minId;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minId = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minId])
				minId = j;
		}

		if (minId != i)
		{
			swap(&array[minId], &array[i]);
			print_array(array, size);
		}
	}
}
