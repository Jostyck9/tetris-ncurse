/*
** EPITECH PROJECT, 2017
** random_tetrimino.c
** File description:
** create a ramdom tetrimino
*/

#include "tetris.h"

int **create_array_and_init(int size)
{
	int **array = malloc(sizeof(*array) * (size + 1));
	int i = 0;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++) {
		array[i] = malloc(sizeof(*array[i]) * (size + 1));
		if (array[i] == NULL)
			return (destroy_int_double_array(array));
		for (int j = 0; j < size; j++)
			array[i][j] = 0;
		array[i][size] = -1;
	}
	array[i] = NULL;
	return (array);
}

int compare_empty_or_not(char value, int tetri)
{
	if (value != ' ')
		return (tetri);
	return (0);
}

int **cvt_pieces_in_int_array(char **piece, int size, int tetri)
{
	int **new = create_array_and_init(size);

	if (new == NULL)
		return (NULL);
	for (int i = 0; piece[i] != NULL; i++) {
		for (int j = 0; piece[i][j] != '\0'; j++) {
			new[i][j] = compare_empty_or_not(piece[i][j], tetri);
		}
	}
	return (new);
}

tetra_game_t cpy_piece(piece_t *piece, int tetri)
{
	tetra_game_t new;
	int size_array = 0;

	new.end = 0;
	new.color = piece->color;
	if (piece->width > piece->height)
		size_array = piece->width;
	else
		size_array = piece->height;
	new.piece = cvt_pieces_in_int_array(piece->piece, size_array, tetri);
	if (new.piece == NULL)
		new.end = 1;
	new.x = 0;
	new.y = 0;
	new.height = piece->height;
	new.width = piece->width;
	new.empty = 0;
	return (new);
}

tetra_game_t create_random_tetri(piece_t **pieces, int value_tetri)
{
	static int size = 0;
	int ramdom_tetri = 0;
	tetra_game_t new;

	if (size == 0) {
		srand((int)(long)&ramdom_tetri);
		for (; pieces[size] != NULL; size++);
	}
	ramdom_tetri = rand() % size;
	new = cpy_piece(pieces[ramdom_tetri], value_tetri);
	return (new);
}
