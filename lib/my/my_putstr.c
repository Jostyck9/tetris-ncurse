/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** print a string
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (84);
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i ++;
	}
	return (0);
}
