#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int head, int tail);
void hoare_sort(int *array, size_t size, int head, int tail);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @head: The starting index of the subset to order.
 * @tail: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int head, int tail)
{
	int pivot, top, bottom;

	pivot = array[tail];
	for (top = head - 1, bottom = tail + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < pivot);
		do {
			bottom--;
		} while (array[bottom] > pivot);

		if (top < bottom)
		{
			swap_ints(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @head: The starting index of the array partition to order.
 * @tail: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int head, int tail)
{
	int part;

	if (tail - head > 0)
	{
		part = hoare_partition(array, size, head, tail);
		hoare_sort(array, size, head, part - 1);
		hoare_sort(array, size, part, tail);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
