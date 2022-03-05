/*
** EPITECH PROJECT, 2017
** recup_option.c
** File description:
** recup_options function
*/

#include "tetris.h"

const struct option long_opt[] = {
	{.name = "help", .has_arg = 0, .flag = 0, .val = 0},
	{.name = "level", .has_arg = 1, .flag = 0, .val = 1},
	{.name = "key-left", .has_arg = 1, .flag = 0, .val = 2},
	{.name = "key-right", .has_arg = 1, .flag = 0, .val = 3},
	{.name = "key-turn", .has_arg = 1, .flag = 0, .val = 4},
	{.name = "key-drop", .has_arg = 1, .flag = 0, .val = 5},
	{.name = "key-quit", .has_arg = 1, .flag = 0, .val = 6},
	{.name = "key-pause", .has_arg = 1, .flag = 0, .val = 7},
	{.name = "map-size", .has_arg = 1, .flag = 0, .val = 8},
	{.name = "without-next", .has_arg = 0, .flag = 0, .val = 9},
	{.name = "debug", .has_arg = 0, .flag = 0, .val = 10},
	{.name = 0, .has_arg = 0, .flag = 0, .val = 0}
};

int check_arg(char end)
{
	if (optarg != NULL)
		if (optarg[0] == '-' || optarg[0] == '=') {
			write(2, "Error: invalid arg : ", 21);
			write(2, optarg, my_strlen(optarg));
			write(2, "\n", 1);
			return (84);
		}
	return (end);
}

char transform_end(char end)
{
	char *optstr = "aLlrtdqpawD";
	int i = 0;

	end = check_arg(end);
	if (end <= '?')
		return (end);
	if (end == ':' || end == 84)
		return (84);
	for (; optstr[i] != '\0'; i++) {
		if (end == optstr[i])
			return ((char)i);
	}
	return (end);
}

int manage_result_get_opt(my_option_t *options, char end)
{
	int (*manage_opt[])(my_option_t *options, char *arg) = {
		&activ_help,
		&change_level,
		&change_key_left,
		&change_key_right,
		&change_key_turn,
		&change_key_drop,
		&change_key_quit,
		&change_key_pause,
		&change_map_size,
		&activ_without_next,
		&activ_debug,
	};

	if (end == -1)
		return (-1);
	if (end == 84)
		return (84);
	if (end > 10 || manage_opt[(int)end](options, optarg) == 84)
		return (84);
	return (0);
}

int recup_options(my_option_t *options, int ac, char **av)
{
	char end = 0;
	char *optstr = "+L:l:r:t:d:q:p:wD";

	end = getopt_long(ac, av, optstr, long_opt, NULL);
	end = transform_end(end);
	end = manage_result_get_opt(options, end);
	if (end == 84)
		return (84);
	while (end != -1 && end != 84) {
		end = getopt_long(ac, av, optstr, long_opt, NULL);
		end = transform_end(end);
		end = manage_result_get_opt(options, end);
		if (options->help == 1)
			print_option(options, av[0]);
	}
	if (end == 84 || optind != ac) {
		if (optind != ac)
			my_putstr("Error: invalid args\n");
		return (84);
	}
	return (0);
}
