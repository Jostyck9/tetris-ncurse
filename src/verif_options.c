/*
** EPITECH PROJECT, 2017
** verif_options.c
** File description:
** check_if options are identicals
*/

#include "tetris.h"

int check_option_identical(char **keys_mem, int current)
{
	for (int i = current + 1; keys_mem[i] != NULL; i++) {
		if (my_strcmp(keys_mem[current], keys_mem[i]) == 0) {
			my_putstr_error(\
"Error: key sequences must be differents\n");
			return (84);
		}
	}
	return (0);
}

int testing_terminal(void)
{
	int error = 0;

	if (setupterm(NULL, 0, &error) == -1) {
		my_putstr_error("Error: No terminal\n");
		return (84);
	}
	if (tigetstr("cup") == NULL) {
		my_putstr_error("Error: wrong type of terminal\n");
		return (84);
	}
	if (tigetstr("ic") == NULL) {
		my_putstr_error("Error: cannot enter key combinations\n");
		return (84);
	}
	return (0);
}

int verif_opt(my_option_t options)
{
	char *keys_mem[] = {
		options.my_key_left,
		options.my_key_right,
		options.my_key_turn,
		options.my_key_drop,
		options.my_key_quit,
		options.my_key_pause,
		NULL,
	};

	for (int i = 0; keys_mem[i + 1] != NULL; i++) {
		if (check_option_identical(keys_mem, i) == 84)
			return (84);
	}
	if (testing_terminal() == 84)
		return (84);
	return (0);
}
