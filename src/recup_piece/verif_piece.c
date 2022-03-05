/*
** EPITECH PROJECT, 2017
** verif_piece.c
** File description:
** verif_piece function
*/

#include "tetris.h"

piece_t **remove_piece(piece_t **pieces, int i)
{
	free(pieces[i]->name);
	destroy_array2d(pieces[i]->piece);
	free(pieces[i]);
	for (; pieces[i] != NULL; i++)
		pieces[i] = pieces[i + 1];
	pieces[i] = NULL;
	return (pieces);
}

int check_piece_ok(piece_t *piece)
{
	if (piece->width == -1 || piece->height == -1)
		return (84);
	if (piece->color == -1)
		return (84);
	return (0);
}

int cmp_size_map_pieces(piece_t **pieces, my_option_t opt)
{
	for (int i = 0; pieces[i] != NULL; i++) {
		if (pieces[i]->height > opt.height)
			return (84);
		if (pieces[i]->width > opt.width)
			return (84);
	}
	return (0);
}

int verif_pieces(piece_t **pieces, my_option_t options)
{
	if (pieces == NULL)
		return (84);
	for (int i = 0; pieces[i] != NULL; i++) {
		if (check_piece_ok(pieces[i]) == 84) {
			pieces = remove_piece(pieces, i);
			i--;
		}
	}
	if (pieces[0] == NULL) {
		free(pieces);
		return (84);
	}
	if (cmp_size_map_pieces(pieces, options) == 84) {
		my_putstr_error("Error: tetrimino size superior to map size\n");
		destroy_pieces(pieces);
		return (84);
	}
	return (0);
}
