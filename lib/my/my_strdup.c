/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** duplicate a string
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char const *src)
{
	char *str;
	int size_src;
	int inc = 0;

	size_src = my_strlen(src);
	str = malloc(sizeof(*str) * (size_src + 1));
	while (src[inc] != '\0') {
		str[inc] = src[inc];
		inc += 1;
	}
	str[inc] = '\0';
	return (str);
}
