/*
** EPITECH PROJECT, 2017
** recup_file.c
** File description:
** function that recup the pieces
*/

#include "tetris.h"

int count_nbr_line(char **file)
{
	int size = 0;

	if (file == NULL)
		return (0);
	while (file[size] != NULL)
		size += 1;
	return (size);
}

char **put_str_in_file(char *str, char **lines_file)
{
	int i = 0;
	char **new_file = NULL;
	int size = 0;

	if (str == NULL || lines_file == NULL)
		return (destroy_array2d(lines_file));
	for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
	str[i] = '\0';
	size = count_nbr_line(lines_file) + 2;
	new_file = malloc(sizeof(*new_file) *size);
	if (new_file == NULL)
		return (destroy_array2d(lines_file));
	for (i = 0; lines_file[i] != NULL; i++)
		new_file[i] = lines_file[i];
	new_file[i] = my_strdup(str);
	new_file[i + 1] = NULL;
	free(lines_file);
	return (new_file);
}

piece_t **open_and_recup_file(char *path, piece_t **pieces)
{
	FILE *file = NULL;
	char *str = NULL;
	char **lines_file = malloc(sizeof(*lines_file));
	size_t size = 0;

	if (path == NULL || lines_file == NULL) {
		free(lines_file);
		return (pieces);
	}
	lines_file[0] = NULL;
	file = fopen(path, "r");
	if (file == NULL) {
		free(lines_file);
		return (pieces);
	}
	while (getline(&str, &size, file) > 0 && lines_file != NULL)
		lines_file = put_str_in_file(str, lines_file);
	free(str);
	fclose(file);
	pieces = transform_into_piece(pieces, lines_file, path);
	return (pieces);
}

piece_t **recup_piece(void)
{
	char **paths = NULL;
	piece_t **pieces = NULL;

	paths = recup_paths();
	if (paths == NULL)
		return (NULL);
	pieces = malloc(sizeof(*pieces));
	if (pieces == NULL) {
		destroy_array2d(paths);
		return (NULL);
	}
	pieces[0] = NULL;
	for (int i = 0; paths[i] != NULL; i++) {
		pieces = open_and_recup_file(paths[i], pieces);
		if (pieces == NULL) {
			destroy_array2d(paths);
			return (NULL);
		}
	}
	destroy_array2d(paths);
	return (pieces);
}
