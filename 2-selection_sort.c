#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, p;
	int tmp, swap = 0;

	if (array)
	{
		for (i = 0; i < size ; i++)
		{
			tmp = array[i];
			for (j = i; j < size; j++)
			{
				if (tmp > array[j])
				{
					tmp = array[j];
					p = j;
					swap = 1;
				}
				if (j + 1 == size && swap == 1)
				{
					array[p] = array[i];
					array[i] = tmp;
					print_array(array, size);
					swap = 0;
				}
			}
		}
	}
}
