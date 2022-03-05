/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** recursive fonction power
*/

int	error(int p)
{
	if (p == 0)
		return (1);
	else
		return (0);
}

int	my_compute_power_rec(int nb, int p)
{
	int result;

	if (p > 1) {
		result = nb * my_compute_power_rec(nb, p-1);
	}
	else
		result = error(p);
	return (result);
}
