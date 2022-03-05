/*
** EPITECH PROJECT, 2017
** my_str_isalphanum.c
** File description:
** return 1 if only chararcter alpha_num
*/

#include "my.h"

int	if_alphanum(char a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (0);
	if (a >= '0' && a <= '9')
		return (0);
	return (1);
}

int	my_str_isalphanum(char const *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0' && change == 0) {
		change = if_alphanum(str[i]);
		i += 1;
	}
	if (change == 0 || str[0] == '\0')
		return (1);
	else
		return (0);
}
