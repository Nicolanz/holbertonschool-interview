#include "sort.h"
/**
 * get_max - Function to get the max value
 * @a: Array
 * @n: Number
 * Return: Max number
 */
int get_max(int a[], int n)
{
	int max = a[0];
	int i = 0;

	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return (max);
}

/**
 * radix_sort - Function to radix sort an array
 * @array: Array
 * @size: Size of the array
 *
 */
void radix_sort(int *array, size_t size)
{
	int bucket[10][10], bucket_cnt[10];
	size_t i, k, r, NOP = 0, divisor = 1, lar, pass;
	int j = 0;

	lar = get_max(array, size);

	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}

	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}

		i = 0;

		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}

		divisor *= 10;
		print_array(array, size);
	}
}
