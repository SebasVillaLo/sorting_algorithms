#include "sort.h"
/**
 * selection_sort - Sort
 * @array: int
 * @size: Size_t
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, aux;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			aux = array[i];
			array[i] = array[min_idx];
			array[min_idx] = aux;
			print_array(array, size);
		}
	}
}
