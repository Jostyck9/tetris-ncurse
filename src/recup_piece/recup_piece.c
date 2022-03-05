/*
** EPITECH PROJECT, 2017
** recup_piece.c
** File description:
** function that recup the pieces
*/

#include "tetris.h"

piece_t *recup_map_piece(char **file, piece_t *piece)
{
	int size_map = count_nbr_line(&file[1]);

	piece->piece = malloc(sizeof(*piece->piece) * (size_map + 1));
	for (int i = 0; file[i + 1] != NULL; i++) {
		piece->piece[i] = my_strdup(file[i + 1]);
	}
	piece->piece[size_map] = NULL;
	return (piece);
}

int check_color(char *line, piece_t *piece)
{
	char **params = my_str_to_word_array(line, ' ');

	if (params == NULL || params[2] == NULL) {
		return (84);
	}
	if (my_str_isnum(params[2]) == 0) {
		destroy_array2d(params);
		return (84);
	}
	piece->color = my_getnbr(params[2]);
	if (piece->color < 0 || piece->color > 256) {
		piece->color = -1;
		destroy_array2d(params);
		return (84);
	}
	destroy_array2d(params);
	return (0);
}

piece_t *recup_size_color(char **file, piece_t *piece)
{
	if (file[0] == NULL) {
		piece->height = -1;
		piece->width = -1;
		return (piece);
	}
	file[0] = replace_chara(file[0], '\t', ' ');
	if (check_size_block(file, piece) == 84) {
		piece->height = -1;
		piece->width = -1;
		piece->color = -1;
		return (piece);
	}
	if (check_color(file[0], piece) == 84)
		return (piece);
	piece = recup_map_piece(file, piece);
	return (piece);
}

piece_t *recup_name(piece_t *piece, char *path)
{
	char *cpy = my_strdup(path);
	int position_point = my_strlen(path) - 10;

	cpy[position_point] = '\0';
	piece->name = my_strdup(&cpy[13]);
	free(cpy);
	return (piece);
}

piece_t **transform_into_piece(piece_t **pieces, char **file, char *path)
{
	piece_t *new_piece = malloc(sizeof(*new_piece));

	if (file == NULL || pieces == NULL || new_piece == NULL) {
		free(new_piece);
		return (NULL);
	}
	new_piece->name = NULL;
	new_piece->piece = NULL;
	new_piece->color = -1;
	new_piece = recup_name(new_piece, path);
	new_piece = recup_size_color(file, new_piece);
	pieces = store_piece(pieces, new_piece);
	destroy_array2d(file);
	return (pieces);
}
