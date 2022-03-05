/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** swap pntr
*/

void	my_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
