/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** square of a whole number
*/

int	my_compute_square_root(int nb)
{
	int i;

	if (nb <= 0)
		return (0);
	while (i * i < nb) {
		i += 1;
	}
	if (i * i == nb) {
		return (i);
	} else {
		return (0);
	}
}
