/*
** EPITECH PROJECT, 2017
** init_tetras.c
** File description:
** init game_tetras
*/

#include "tetris.h"

tetra_game_t *init_tetras(void)
{
	tetra_game_t *tetras = malloc(sizeof(*tetras));

	if (tetras == NULL)
		return (NULL);
	tetras->end = 1;
	tetras->color = 0;
	tetras->piece = NULL;
	return (tetras);
}

int **destroy_int_double_array(int **array)
{
	if (array == NULL)
		return (NULL);
	for (int i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
	return (NULL);
}

tetra_game_t *destroy_all_tetras(tetra_game_t *tetras)
{
	if (tetras == NULL)
		return (NULL);
	for (int i = 0; tetras[i].end != 1; i++) {
		tetras[i].piece = destroy_int_double_array(tetras[i].piece);
		tetras[i].end = 1;
	}
	free(tetras);
	return (NULL);
}
