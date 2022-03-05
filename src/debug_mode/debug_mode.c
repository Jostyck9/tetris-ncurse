/*
** EPITECH PROJECT, 2017
** debug_mode.c
** File description:
** debug mode function
*/

#include "tetris.h"

void print_hide(my_option_t *options)
{
	my_putstr("Next :  ");
	if (options->hide == 1)
		my_putstr("No\n");
	else
		my_putstr("Yes\n");
}

void print_level(my_option_t *options)
{
	my_putstr("Level :  ");
	my_put_nbr(options->level);
	my_putchar('\n');
}

void print_size_map(my_option_t *options)
{
	my_putstr("Size :  ");
	my_put_nbr(options->width);
	my_putchar('*');
	my_put_nbr(options->height);
	my_putchar('\n');
}

void print_options(my_option_t *options)
{
	print_key("Left", options->my_key_left);
	print_key("Right", options->my_key_right);
	print_key("Turn", options->my_key_turn);
	print_key("Drop", options->my_key_drop);
	print_key("Quit", options->my_key_quit);
	print_key("Pause", options->my_key_pause);
	print_hide(options);
	print_level(options);
	print_size_map(options);
}

int debug_mode(my_option_t *options, piece_t **pieces)
{
	int size = 0;
	char buffer;

	if (options->debug == 0)
		return (0);
	my_putstr("*** DEBUG MODE ***\n");
	print_options(options);
	my_putstr("Tetriminos : ");
	size = count_size_pieces(pieces);
	my_put_nbr(size);
	my_putchar('\n');
	for (int i = 0; pieces != NULL && pieces[i] != NULL; i++)
		debug_piece(pieces[i]);
	if (my_canon_mode(0) == 84)
		return (84);
	my_putstr("Press any key to start Tetris\n");
	read(0, &buffer, 1);
	if (my_canon_mode(1) == 84)
		return (84);
	return (0);
}
