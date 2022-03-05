/*
** EPITECH PROJECT, 2017
** my_isneg.c
** File description:
** fonction that tell us if the integer is positive or negative made by Hugo B
*/

#include "my.h"

int	my_isneg(int n)
{
	if (n >= 0) {
		my_putchar('P');
	} else {
		my_putchar('N');
	}
	return (0);
}
