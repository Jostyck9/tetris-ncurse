/*
** EPITECH PROJECT, 2017
** options_key_game.c
** File description:
** recup_options function
*/

#include "tetris.h"

int change_key_left(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -l / --key-left\n", 46);
		return (84);
	}
	free(options->my_key_left);
	options->my_key_left = my_strdup(arg);
	if (options->my_key_left == NULL) {
		write(2, "Error: failed to recup arg -l / --key_left\n", 43);
		return (84);
	}
	return (0);
}

int change_key_right(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -r / --key-right\n", \
47);
		return (84);
	}
	free(options->my_key_right);
	options->my_key_right = my_strdup(arg);
	if (options->my_key_right == NULL) {
		write(2, "Error: failed to recup arg -r / --key_right\n", 44);
		return (84);
	}
	return (0);
}

int change_key_turn(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -t / --key-turn\n", 46);
		return (84);
	}
	free(options->my_key_turn);
	options->my_key_turn = my_strdup(arg);
	if (options->my_key_turn == NULL) {
		write(2, "Error: failed to recup arg -t / --key_turn\n", 43);
		return (84);
	}
	return (0);
}

int change_key_drop(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -d / --key-drop\n", 46);
		return (84);
	}
	free(options->my_key_drop);
	options->my_key_drop = my_strdup(arg);
	if (options->my_key_drop == NULL) {
		write(2, "Error: failed to recup arg -d / --key_drop\n", 43);
		return (84);
	}
	return (0);
}

int change_key_pause(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -p / --key-pause\n", \
47);
		return (84);
	}
	free(options->my_key_pause);
	options->my_key_pause = my_strdup(arg);
	if (options->my_key_pause == NULL) {
		write(2, "Error: failed to recup arg -p / --key_pause\n", 44);
		return (84);
	}
	return (0);
}
