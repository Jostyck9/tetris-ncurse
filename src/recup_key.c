/*
** EPITECH PROJECT, 2017
** recup_key.c
** File description:
** main function
*/

#include "tetris.h"

char *init_key_buff(char **keys_mem, int *size)
{
	int current_size = 0;
	char *buffer = NULL;

	if (keys_mem == NULL)
		return (0);
	for (int i = 0; keys_mem[i] != NULL; i++) {
		current_size = my_strlen(keys_mem[i]);
		if (current_size > size[0])
			size[0] = current_size;
	}
	buffer = malloc(sizeof(*buffer) * (size[0] + 2));
	if (buffer != NULL)
		for (int j = 0; j <= size[0]; buffer[j] = '\0', j++);
	return (buffer);
}

int check_cmd_end_clock(char *buffer, char **keys_mem, int clear, int *posi)
{
	int cmd = -1;

	for (int i = 0; keys_mem[i] != NULL; i++) {
		if (my_strcmp(buffer, keys_mem[i]) == 0) {
			cmd = i;
			break;
		}
	}
	if (clear == 1 && cmd != -1) {
		posi[0] = -1;
		for (int j = 0; buffer[j] != '\0'; j++) {
			buffer[j] = '\0';
		}
	}
	return (cmd);
}

int check_cmd_buffer(char *buffer, char **keys_mem, int *i)
{
	int cmd = -1;
	int found = 0;

	for (int i = 0; keys_mem[i] != NULL; i++) {
		if (my_strcmp_beg(buffer, keys_mem[i]) == 0) {
			found += 1;
		}
	}
	if (found == 1) {
		cmd = check_cmd_end_clock(buffer, keys_mem, 1, i);
	}
	if (found == 0) {
		for (int j = 0; buffer[j] != '\0'; j++) {
			buffer[j] = '\0';
		}
		i[0] = -1;
		return (-1);
	}
	return (cmd);
}

int recup_key(char *buffer, char **keys_mem, char key, int size)
{
	static double limit = 0;
	static int i = 0;
	double my_clock = clock() * 10 / CLOCKS_PER_SEC;
	int cmd = -1;

	if (limit <= 0)
		limit = clock() * 10 / CLOCKS_PER_SEC + LIMIT_KEY;
	if (my_clock > limit || my_strlen(buffer) == size) {
		cmd = check_cmd_end_clock(buffer, keys_mem, 1, &i);
		limit = clock() * 10 / CLOCKS_PER_SEC + LIMIT_KEY;
		i = 0;
	} else if (key != -1) {
		buffer[i] = key;
		cmd = check_cmd_buffer(buffer, keys_mem, &i);
		limit = clock() * 10 / CLOCKS_PER_SEC + LIMIT_KEY;
		i += 1;
	}
	return (cmd);
}

int manage_key(my_option_t options)
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
	static char *keys_buff = NULL;
	static int size_max = 0;
	int cmd = -1;
	char key = -1;

	if (keys_buff == NULL)
		keys_buff = init_key_buff(keys_mem, &size_max);
	if (keys_buff == NULL)
		return (84);
	key = getch();
	cmd = recup_key(keys_buff, keys_mem, key, size_max);
	return (cmd);
}
