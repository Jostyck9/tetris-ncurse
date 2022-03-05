/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** put a single str into word array
*/

#include <stdlib.h>
#include "my.h"

int position_after_space(char *str, int i, char separator)
{
	while (str[i] == separator)
		i += 1;
	return (i);
}

int count_size_word(char *str, int i, char separator)
{
	int size = 0;

	while (str[i] != separator && str[i] != '\0') {
		i += 1;
		size += 1;
	}
	return (size);
}

char *put_word_array(char *str, int position, char separator)
{
	char *array = NULL;
	int size = 0;
	int i = 0;

	position = position_after_space(str, position, separator);
	size = count_size_word(str, position, separator);
	if (size == 0)
		return (NULL);
	array = malloc(sizeof(*array) * (size + 1));
	if (array == NULL)
		return (array);
	while (str[position] != separator && str[position] != '\0') {
		array[i] = str[position];
		position += 1;
		i += 1;
	}
	array[size] = '\0';
	return (array);
}

int count_words(char const *str, char separator)
{
	int i = 0;
	int size = 0;

	while (str[i] != '\0') {
		while (str[i] == separator)
			i += 1;
		while (str[i] != separator && str[i] != '\0')
			i += 1;
		while (str[i] == separator)
			i += 1;
		size += 1;
	}
	return (size);
}

char **my_str_to_word_array(char const *str, char separator)
{
	char **array = NULL;
	char *current_position = (char *)str;
	int size_array = count_words(str, separator);
	int b = 0;
	int i = 0;

	array = malloc(sizeof(*array) * (size_array + 1));
	if (array == NULL || size_array == 0) {
		free(array);
		return (NULL);
	}
	for (i = 0; i < size_array; i += 1) {
		b = position_after_space(current_position, b, separator);
		array[i] = put_word_array(current_position, b, separator);
		while (str[b] != separator && str[b] != '\0')
			b += 1;
		if (array[i] == NULL)
			return (destroy_array2d(array));
	}
	array[i] = NULL;
	return (array);
}
