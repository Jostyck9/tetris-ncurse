/*
** EPITECH PROJECT, 2017
** my_putstr_error.c
** File description:
** print a text on the error output
*/

#include "tetris.h"

void my_putstr_error(char *str)
{
	int size = 0;

	if (str == NULL)
		return;
	for (; str[size] != '\0'; size++);
	write(2, str, size);
}
