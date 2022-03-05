/*
** EPITECH PROJECT, 2017
** my_strcmp_beg.c
** File description:
** find a string in another string
*/

#include <tetris.h>

int my_strcmp_beg(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
		i++;
	}
	if (str1[i] == '\0')
		return (0);
	return (str1[i] - str2[i]);
}
