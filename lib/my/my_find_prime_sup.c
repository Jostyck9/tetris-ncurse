/*
** EPITECH PROJECT, 2017
** my_find_prime_sup.c
** File description:
** primary nb sup of the int given
*/

int	my_find_prime_sup(int nb)
{
	int divs = nb - 1;
	int rst = 1;

	while (rst > 0 && divs != 1 && nb > 1 ) {
		rst = nb % divs;
		divs = divs - 1;
	}
	if (rst == 0 || nb <= 1) {
		nb = my_find_prime_sup(nb + 1);
	}
	return (nb);
}
