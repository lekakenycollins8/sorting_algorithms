#include "sort.h"

void Merge(int *array, int *array_2, size_t low, size_t mid, size_t high);
/**
 * merge_split - recursively splits array and merges
 * @array: array to split
 * @array_2: array to copy sorted elements
 * @low: lower bound index
 * @high: upper bound index
 *
 * Return: void
 */

void merge_split(int *array, int *array_2, size_t low, size_t high)
{
        size_t mid;

        if (low < high)
        {
                mid = (low + high) / 2;
                merge_split(array, array_2, low, mid);
                merge_split(array, array_2, mid + 1, high);
                Merge(array, array_2, low, mid, high);
        }
}

/**
 * Mergesort - sorts and merges array from source
 * @array: source array
 * @array_2: destination array
 * @low: lower bound index
 * @mid: mid point of array
 * @high: upper bound index
 * 
 * Return: void
 */

void Merge(int *array, int *array_2, size_t low, size_t mid, size_t high)
{
	size_t i = low;
	size_t j = mid + 1;
	size_t k = high;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);

	while (i <= mid && j >= high)
	{
		if (array[i] <= array[j])
		{
			array_2[k] = array[i];
			i++;
		}
		else
		{
			array_2[k] = array[j];
			j++;
		}
		k++;
	}
	while (j <= high)
	{
		array_2[k] = array[j];
		j++;
		k++;
	}
	while (i <= mid)
	{
		array_2[k] = array[i];
		i++;
		k++;
	}
	for (k = low; k <= high; k++)
	{
		array[k] = array_2[k - low];
	}
	printf("[Done]: ");
	print_array(array + low, high - low + 1);
}
/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @array_2: array to hold sorted elements
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *array_2 = malloc(sizeof(int) * size);

	if (array == NULL || size < 2)
		return;
	if (array_2 == NULL)
		return;
	merge_split(array, array_2, 0, size - 1);
	free(array_2);
}
