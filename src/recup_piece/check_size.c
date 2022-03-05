/*
** EPITECH PROJECT, 2017
** check_size.c
** File description:
** parsing function
*/

#include "tetris.h"

int check_chara(char *str)
{
	if (str == NULL)
		return (84);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '*' && str[i] != ' ')
			return (84);
	}
	return (0);
}

int check_block_x(int x, char **file)
{
	int size_x = 0;
	int i = 1;
	int size_str = 0;
	int size_spaces = 0;
	int current_size = 0;

	for (; file[i] != NULL; i++) {
		if (check_chara(file[i]) == 84)
			return (84);
		size_str = my_strlen(file[i]);
		size_spaces = count_spaces_end(file[i], size_str);
		current_size = size_str - size_spaces;
		if (current_size > size_x)
			size_x = current_size;
	}
	if (size_x != x)
		return (84);
	return (0);
}

int check_block_y(int y, char **file)
{
	int size_y = 0;
	int empty = 0;
	int i = 1;

	for (; file[i] != NULL; i++) {
		if (file[i][0] == '\0')
			empty += 1;
		else {
			size_y = size_y + empty + 1;
			empty = 0;
		}
	}
	if (y != size_y)
		return (84);
	return (0);
}

int check_block(int x, int y, char **file)
{
	if (check_block_y(y, file) == 84)
		return (84);
	if (check_block_x(x, file) == 84)
		return (84);
	return (0);
}

int check_size_block(char **file, piece_t *piece)
{
	char **params = my_str_to_word_array(file[0], ' ');

	if (count_size_array(params) != 3) {
		destroy_array2d(params);
		return (84);
	}
	if (my_str_isnum(params[0]) == 0 && my_str_isnum(params[0]) == 0) {
		destroy_array2d(params);
		return (84);
	}
	piece->width = my_getnbr(params[0]);
	piece->height = my_getnbr(params[1]);
	destroy_array2d(params);
	if (check_block(piece->width, piece->height, file) == 84)
		return (84);
	return (0);
}
