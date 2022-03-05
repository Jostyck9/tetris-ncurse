/*
** EPITECH PROJECT, 2017
** debug_piece.c
** File description:
** debug mode function
*/

#include "tetris.h"

void print_key(char *key, char *my_key_code)
{
	my_putstr("Key ");
	my_putstr(key);
	my_putstr(" :  ");
	if (my_key_code[0] == ' ' && my_key_code[1] == '\0')
		my_putstr("(space)");
	else
		my_putstr_spc(my_key_code);
	my_putchar('\n');
}

void my_putstr_spc(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 27 && str[i + 1] == '[') {
			my_putstr("^EO");
			i += 1;
		} else if (str[i] == ' ') {
			my_putstr("(space)");
		} else
			my_putchar(str[i]);
	}
}

int debug_color(piece_t *piece)
{
	if (piece->color == -1) {
		my_putstr("Error\n");
		return (-1);
	}
	my_putstr("Color ");
	my_put_nbr(piece->color);
	my_putstr(" :\n");
	return (0);
}

int debug_size(piece_t *piece)
{
	if (piece->width == -1 || piece->height == -1) {
		my_putstr("Error\n");
		return (-1);
	}
	my_putstr("Size ");
	my_put_nbr(piece->width);
	my_putchar('*');
	my_put_nbr(piece->height);
	my_putstr(" : ");
	return (0);
}

void debug_piece(piece_t *piece)
{
	my_putstr("Tetriminos : Name ");
	my_putstr(piece->name);
	my_putstr(" : ");
	if (debug_size(piece) == -1)
		return;
	if (debug_color(piece) == -1)
		return;
	my_show_word_array(piece->piece);
}
