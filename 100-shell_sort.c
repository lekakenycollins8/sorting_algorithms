#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i;

	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			int temp = array[i];
			size_t j = i;

			while (j >= gap && array [j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
