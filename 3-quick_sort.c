#include "sort.h"
/**
 * partition - finds
 * @array: array
 * @start: lowest
 * @end: highest
 * @size: size
 * Return: index
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start - 1;
	int pivot = array[end];
	int check = start;
	int temp;

	while (check < end)
	{
		if (array[check] <= pivot)
		{
			i++;
			if (check != i)
			{
				temp = array[i];
				array[i] = array[check];
				array[check] = temp;
				print_array(array, size);
			}
		}
		check++;
	}
	i++;
	if (end != i)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}
/**
 * quicksort - sorts
 * @array: array
 * @start: lowest
 * @end: highest
 * @size: size
 * Return: void
 */
void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quicksort(array, start, pivot - 1, size);
		quicksort(array, pivot + 1, end, size);
	}
}
/**
 * quick_sort - sorts
 * @array: array
 * @size: size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
