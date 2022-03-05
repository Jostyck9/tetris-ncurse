/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** putchard for numbers by hugo berthomé
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	int puissance = 1;
	int nb2;

	if (nb >= 0) {
		nb = nb * -1;
	} else {
		my_putchar('-');
	}
	nb2 = nb;
	while (nb2 < -9) {
		puissance = puissance * 10;
		nb2 = nb2 /10;
	}
	puissance = puissance * -1;
	while (puissance < 0) {
		my_putchar(nb / puissance + '0');
		nb = nb % puissance;
		puissance = puissance / 10;
	}
	return (0);
}
