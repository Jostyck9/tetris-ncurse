/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** say if it is prime number
*/

int	my_is_prime(int nb)
{
	int divs = nb - 1;
	int rst = 1;

	while (rst > 0 && divs != 1 && nb > 1) {
		rst = nb % divs;
		divs = divs - 1;
	}
	if (rst == 0 || nb <= 1) {
		return (0);
	} else
		return (1);
}
