/*
** EPITECH PROJECT, 2017
** sort_paths.c
** File description:
** function that sort all the path of the folder tetriminos
*/

#include "tetris.h"

char **switch_array(char **paths, int posi1, int posi2)
{
	char *save = paths[posi2];

	paths[posi2] = paths[posi1];
	paths[posi1] = save;
	return (paths);
}

char **check_inverse_path(char **paths, int i, int j)
{
	int letter = 0;

	while (paths[i][letter] == paths[j][letter]) {
		if (paths[i][letter] == '\0' && paths[j][letter] == '\0')
			break;
		letter += 1;
	}
	if (paths[i][letter] > paths[j][letter])
		paths = switch_array(paths, i, j);
	letter = 0;
	return (paths);
}

char **sort_paths(char **paths)
{
	for (int i = 0; paths[i + 1] != NULL; i++) {
		for (int j = i + 1; paths[j] != NULL; j++) {
			paths = check_inverse_path(paths, i, j);
		}
	}
	return (paths);
}
