#include "sort.h"
/**
 * partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @start: lowest index of the partition to sort
 * @end: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
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
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @start: lowest index of the partition to sort
 * @end: highest index of the partition to sort
 * @size: size of the array
 *
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
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
