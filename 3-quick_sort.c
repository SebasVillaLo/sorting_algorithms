#include "sort.h"
/**
  * quick_sort - quick sort function
  * @array: array to be sorte
  * @size: size of the array
  */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    qs(array, 0, size - 1, size);
}

/**
  * qs - quick sort function
  * @array: array to be sorted
  * @left: left edge of the array
  * @right: right edge of the array
  * @size: size of the array
  */

void qs(int *array, int left, int right, size_t size)
{
    size_t pivot = 0;

    if (left < right)
    {
        pivot = partition(array, left, right, size);
        if (pivot > 0)
            qs(array, left, pivot - 1, size);
        if (pivot != size)
            qs(array, pivot + 1, right, size);
    }
}

/**
  * partition - fix the position of the elements
  * @array: array to be sorted
  * @left: left edge of the array
  * @right: right edge of the array
  * @size: size of the array
  * Return: the index of the pivot
  */

int partition(int *array, int left, int right, size_t size)
{
    int pivot = array[right];
    int i = left - 1, j, temp;

    for (j = left; j < right; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (j != i)
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                print_array(array, size);
            }
        }
    }
    if (pivot < array[i + 1])
    {
        temp = array[i + 1];
        array[i + 1] = array[right];
        array[right] = temp;
        print_array(array, size);
    }
    return (i + 1);
}
