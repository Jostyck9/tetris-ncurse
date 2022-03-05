/*
** EPITECH PROJECT, 2017
** count_size.c
** File description:
** parsing function
*/

#include "tetris.h"

int count_spaces_end(char *str, int size)
{
	int i = size - 1;
	int spaces = 0;

	for (; i >= 0 && str[i] == ' '; i--, spaces++);
	return (spaces);
}

int count_size_array(char **array)
{
	int size = 0;

	if (array == NULL)
		return (-1);
	for (; array[size] != NULL; size++);
	return (size);
}
