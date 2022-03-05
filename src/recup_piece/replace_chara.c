/*
** EPITECH PROJECT, 2017
** replace_chara.c
** File description:
** function that replace a chara by another
*/

#include "tetris.h"

char *replace_chara(char *str, char from, char to)
{
	if (str == NULL || from == '\0')
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == from)
			str[i] = to;
	}
	return (str);
}
