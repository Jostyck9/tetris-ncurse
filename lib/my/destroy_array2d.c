/*
** EPITECH PROJECT, 2017
** destroy_array2d.c
** File description:
** destroy double array
*/

#include <stdlib.h>
#include "my.h"

char **destroy_array2d(char **array)
{
	int i = 0;

	if (array != NULL) {
		while (array[i] != NULL) {
			free(array[i]);
			i += 1;
		}
		free(array);
	}
	return (NULL);
}
