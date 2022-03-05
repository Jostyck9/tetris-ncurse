/*
** EPITECH PROJECT, 2017
** clean_empty_lines_pieces.c
** File description:
** clean the empty line pieces
*/

#include "tetris.h"

int check_empty_line(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
	if (str[i] == '\0') {
		return (1);
	}
	return (0);
}

char **remove_empty_lines(char **piece)
{
	int i = 0;

	for (; piece[i] != NULL; i++);
	for (i -= 1; i >= 0; i--) {
		if (check_empty_line(piece[i]) == 0) {
			return (piece);
		}
		free(piece[i]);
		piece[i] = NULL;
	}
	return (piece);
}

piece_t **clean_empty_lines_pieces(piece_t **pieces)
{
	if (pieces == NULL)
		return (pieces);
	for (int i = 0; pieces[i] != NULL; i++) {
		if (pieces[i]->piece && pieces[i]->piece != NULL) {
			pieces[i]->piece = remove_empty_lines(pieces[i]->piece);
		}
	}
	return (pieces);
}
