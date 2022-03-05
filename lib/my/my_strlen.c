/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** return the number of character
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
	int nb_chara = 0;

	if (str == NULL) {
		return (0);
	}
	while (str[nb_chara] != '\0') {
		nb_chara += 1;
	}
	return (nb_chara);
}
