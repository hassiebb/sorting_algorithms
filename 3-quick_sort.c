#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int head, int tail);
void lomuto_sort(int *array, size_t size, int head, int tail);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @head: The starting index of the subset to order.
 * @tail: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int head, int tail)
{
	int *pivot, top, bottom;

	pivot = array + tail;
	for (top = bottom = head; bottom < tail; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap_ints(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @head: The starting index of the array partition to order.
 * @tail: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int head, int tail)
{
	int part;

	if (tail - head > 0)
	{
		part = lomuto_partition(array, size, head, tail);
		lomuto_sort(array, size, head, part - 1);
		lomuto_sort(array, size, part + 1, tail);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
