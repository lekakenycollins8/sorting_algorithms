#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array into 2 parts for
 * using in the Quick sort algorithm
 *
 * @array: array to sort
 * @low: lower bound(first element) of the array
 * @high: upper bound(last element) of the array
 * @size: size of the array
 *
 * Return: partition index
 */

int partition(int *array, int low, int high, size_t size)
{
	int j;
	int pivot = array[high];
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
