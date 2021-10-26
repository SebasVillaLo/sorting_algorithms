#include "sort.h"

/**
 * bubble_sort - Sort
 * @array: int
 * @size: Size_t
 * Return: Always 0
 */

void bubble_sort(int *array, size_t size)
{
    size_t aux, i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}
