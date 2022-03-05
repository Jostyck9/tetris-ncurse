/*
** EPITECH PROJECT, 2017
** store_piece.c
** File description:
** function that recup the pieces
*/

#include "tetris.h"

int count_size_pieces(piece_t **pieces)
{
	int size = 0;

	if (pieces == NULL)
		return (0);
	for (; pieces[size] != NULL; size++);
	return (size);
}

piece_t **store_piece(piece_t **pieces, piece_t *new)
{
	int size_pieces = count_size_pieces(pieces) + 2;
	piece_t **realloc_pieces = malloc(\
sizeof(*realloc_pieces) * (size_pieces));

	if (realloc_pieces == NULL || new == NULL) {
		free(realloc_pieces);
		return (pieces);
	}
	for (int i = 0; pieces[i] != NULL; i++)
		realloc_pieces[i] = pieces[i];
	realloc_pieces[size_pieces - 2] = new;
	realloc_pieces[size_pieces - 1] = NULL;
	free(pieces);
	return (realloc_pieces);
}
