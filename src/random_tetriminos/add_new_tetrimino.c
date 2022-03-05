/*
** EPITECH PROJECT, 2017
** add_new_tetrimino.c
** File description:
** adding a ramdom tetrimino
*/

#include "tetris.h"

tetra_game_t *destroy_tetra(tetra_game_t *piece)
{
	if (piece == NULL)
		return (NULL);
	for (int i = 0; piece[i].end != 1; i++) {
		destroy_int_double_array(piece[i].piece);
	}
	free(piece);
	return (NULL);
}

tetra_game_t *my_realloc_tetra(tetra_game_t *array, int new_size)
{
	tetra_game_t *new = malloc(sizeof(*new) * (new_size + 1));

	if (new == NULL) {
		free(array);
		return (NULL);
	}
	for (int i = 0; i < new_size; i++)
		new[i] = array[i];
	new[new_size] = new[new_size - 1];
	free(array);
	return (new);
}

tetra_game_t *add_new_tetrimino(piece_t **pieces, game_t game, int current)
{
	int size = 0;

	for (size = 0; game.tetras[size].end != 1; size++);
	game.tetras = my_realloc_tetra(game.tetras, size + 1);
	if (game.tetras == NULL)
		return (NULL);
	game.tetras[size] = create_random_tetri(pieces, current + 1);
	if (game.tetras[size].piece == NULL) {
		free(game.tetras);
		return (NULL);
	}
	return (game.tetras);
}
