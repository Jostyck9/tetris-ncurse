/*
** EPITECH PROJECT, 2017
** options_game.c
** File description:
** recup_options function
*/

#include "tetris.h"

int activ_help(my_option_t *options, char *arg)
{
	options->help = 1;
	arg = arg;
	return (0);
}

int activ_without_next(my_option_t *options, char *arg)
{
	options->hide = 1;
	arg = arg;
	return (0);
}

int activ_debug(my_option_t *options, char *arg)
{
	options->debug = 1;
	arg = arg;
	return (0);
}

int change_level(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -l / --level\n", 43);
		return (84);
	}
	if (my_str_isnum(arg) == 0) {
		write(2, "Error: level needs to be a number\n", 34);
		return (84);
	}
	options->level = my_getnbr(arg);
	if (options->level <= 0) {
		write(2, "Error: level needs to be greater than 0\n", 40);
		return (84);
	}
	return (0);
}
