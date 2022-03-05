/*
** EPITECH PROJECT, 2017
** recup_paths.c
** File description:
** function that recup all the path of the folder tetriminos
*/

#include "tetris.h"

char *create_new_path(char *file)
{
	char *new = NULL;
	int size = 0;

	if (file == NULL)
		return (NULL);
	size = my_strlen(file);
	new = malloc(sizeof(*new) * (size + 14));
	my_strcpy(new, "./tetriminos/");
	my_strcat(new, file);
	return (new);
}

char **put_new_path(char **paths, char *file)
{
	static int size_paths = 0;
	char *new_path = create_new_path(file);
	char **realloc_path = NULL;

	if (file == NULL || new_path == NULL)
		return (NULL);
	realloc_path = malloc(sizeof(*realloc_path) * (size_paths + 2));
	if (realloc_path == NULL)
		return (paths);
	for (int i = 0; i < size_paths; i++)
		realloc_path[i] = paths[i];
	realloc_path[size_paths] = new_path;
	realloc_path[size_paths + 1] = NULL;
	free(paths);
	size_paths += 1;
	realloc_path = sort_paths(realloc_path);
	return (realloc_path);
}

char **found_paths(struct dirent *file, char **paths)
{
	int i = 0;

	if (file == NULL || file->d_type != DT_REG)
		return (paths);
	i = my_strlen(file->d_name);
	if (i < 10 || my_strcmp(&file->d_name[i - 10], ".tetrimino") != 0) {
		return (paths);
	}
	paths = put_new_path(paths, file->d_name);
	return (paths);
}

char **recup_paths(void)
{
	DIR *folder = opendir("./tetriminos/");
	char **paths = NULL;
	struct dirent *file = NULL;

	if (folder == NULL) {
		perror("Error ./tetriminos");
		return (NULL);
	}
	paths = malloc(sizeof(*paths));
	if (paths == NULL) {
		closedir(folder);
		return (NULL);
	}
	paths[0] = NULL;
	file = readdir(folder);
	while (file != NULL && paths != NULL) {
		paths = found_paths(file, paths);
		file = readdir(folder);
	}
	closedir(folder);
	return (paths);
}
