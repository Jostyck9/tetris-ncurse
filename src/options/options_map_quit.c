/*
** EPITECH PROJECT, 2017
** options_map_quit.c
** File description:
** recup_options function
*/

#include "tetris.h"

int change_map_size(my_option_t *options, char *arg)
{
	char **size;

	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after --map-size\n", 41);
		return (84);
	}
	size = my_str_to_word_array(arg, ',');
	if (size == NULL || size[0] == NULL || size[1] == NULL) {
		destroy_array2d(size);
		write(2, "Error: failed to recup arg --map-size\n", 38);
		return (84);
	}
	options->width = my_getnbr(size[0]);
	options->height = my_getnbr(size[1]);
	destroy_array2d(size);
	if (options->width <= 0 || options->height <= 0) {
		write(2, "Error: map size needs to be greater than 0\n", 43);
		return (84);
	}
	return (0);
}

int change_key_quit(my_option_t *options, char *arg)
{
	if (arg == NULL || arg[0] == '\0') {
		write(2, "Error: need an argument after -q / --key-quit\n", 46);
		return (84);
	}
	free(options->my_key_quit);
	options->my_key_quit = my_strdup(arg);
	if (options->my_key_quit== NULL) {
		write(2, "Error: failed to recup arg -q / --key_quit\n", 43);
		return (84);
	}
	return (0);
}

void print_option(my_option_t *options, char *name)
{
	my_putstr("Usage: ");
	my_putstr(name);
	my_putstr(" [options]\nOptions:\n ");
	my_putstr("--help\t\t\tDisplay this help\n ");
	my_putstr("-L --level={num}\tStart Tetris at level num (def: 1)\n ");
	my_putstr("-l --key-left={K]\tMove the tetrimino LEFT using the ");
	my_putstr("K key (def: left arrow)\n -r --key-right={K}\t");
	my_putstr("Move the tetrimino RIGHT using the K key ");
	my_putstr("(def: right arrow)\n -t --key-turn={K}\t");
	my_putstr("TURN the tetrimino clockwise 90d using the K key (def: ");
	my_putstr("top arrow)\n -d --key-drop={K}\tDROP the tetrimino using");
	my_putstr(" the K key (def: down arrow)\n -q --key-quit={K}\t");
	my_putstr("QUIT the game using the K key (def: 'q' key)\n ");
	my_putstr("-p --key-pause={K}\tPAUSE/RESTART the game using the K ");
	my_putstr("key (def: space bar)\n --map-size={row,col}\tSet the ");
	my_putstr("numbers of rows and columns of the map (def: 20,10)\n ");
	my_putstr("-w --without-next\tHide next tetrimino (def: false)\n ");
	my_putstr("-D --debug\t\tDebug mode (def: false)\n");
	destroy_options(options);
	exit(0);
}
