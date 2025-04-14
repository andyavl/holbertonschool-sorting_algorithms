#include "sort.h"

/**
 * partition - Sorts part of the array and print changes
 * @array: Array to sort
 * @first: Lowest element of current array partition
 * @last: Highest element of current array partition
 * @size: Size of the array
 * Return: New index to sort other parts of the array
 */
int partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last];
	int i = first - 1;
	int j, tmp;

	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (tmp != array[i])
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[last];
	array[last] = tmp;
	if (tmp != array[i + 1])
		print_array(array, size);

	return (i + 1);
}

/**
 * sort_recursion - Calls itself to sort array in parts
 * @array: Array to sort
 * @first: First element of the array
 * @last: Last element of the array
 * @size: Size of the array
 */
void sort_recursion(int *array, int first, int last, size_t size)
{
	if (first < last)
	{
		int returnedindex = partition(array, first, last, size);

		sort_recursion(array, first, returnedindex - 1, size);
		sort_recursion(array, returnedindex + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick sort Algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array)
		sort_recursion(array, 0, size - 1, size);
}
