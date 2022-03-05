/*
** EPITECH PROJECT, 2017
** my_sort_int_array.c
** File description:
** sort integers in ascending order
*/

void	my_sort_int_array(int *array, int size)
{
	int beg = 0;
	int nb = 0;
	int c;

	while (beg < size) {
		if (array[beg] >= array[nb]) {
			c = array[beg];
			array[beg] = array[nb];
			array[nb] = c;
		}
		nb += 1;
		if (nb >= size) {
			beg += 1;
			nb = beg;
		}
	}
}
