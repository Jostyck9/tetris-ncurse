/*
** EPITECH PROJECT, 2017
** my_showmem.c
** File description:
** print a memory dump
*/

#include "my.h"

int	my_showmem(char const *str, int size)
{
	my_putstr(str);
	my_put_nbr(size);
	return (0);
}
