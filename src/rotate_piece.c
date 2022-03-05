/*
** EPITECH PROJECT, 2017
** rotate_piece.c
** File description:
** rotate a piece
*/

#include "tetris.h"

int get_size_piece(int **piece)
{
	int width = 0;
	int height = 0;

	for (int x = 0; piece[0][x] != -1; x++)
		width = x;
	for (int x = 0; piece[x] != NULL; x++)
		height = x;
	if (height < width)
		height = width;
	return (height);
}

int **get_array_piece(int size)
{
	int x = 0;
	int **piece = malloc(sizeof(int *) * (size + 3));

	if (piece == NULL)
		return (NULL);
	for (; x < size; x++) {
		piece[x] = malloc(sizeof(int) * (size + 3));
		if (piece[x] == NULL) {
			destroy_int_double_array(piece);
			return (NULL);
		}
	}
	return (piece);
}

int **get_rotate(int **piece, int **new_piece, int size)
{
	int y = 0;
	int x = 0;
	int sy = size;

	for (int x = 0; x <= size; x++)
		new_piece[x][size + 1] = -1;
	new_piece[size + 1] = NULL;
	while (piece[y] != NULL) {
		while (piece[y][x] != -1) {
			new_piece[x][sy] = piece[y][x];
			x++;
		}
		x = 0;
		y++;
		sy--;
	}
	return (new_piece);
}

int check_rotate_piece(tetra_game_t tetras, int **piece, int **screen)
{
	int w = 0;
	int pc = 0;
	int sc = 0;
	int x = tetras.x;
	int y = tetras.y;

	for (int h = 0; piece[h] != NULL;) {
		pc = piece[h][w];
		sc = screen[y][x];
		if (pc > 0 && sc > 0 && pc != sc)
			return (84);
		x++;
		w++;
		if (piece[h][w] == -1) {
			y++;
			h++;
			w = 0;
			x = tetras.x;
		}
	}
	return (0);
}

game_t rotate(game_t game, int cmd)
{
	int **piece = game.tetras[game.current_piece].piece;
	int size = get_size_piece(piece);
	int **new_piece = get_array_piece(size + 1);
	int x = game.tetras[game.current_piece].x;
	int y = game.tetras[game.current_piece].y;

	cmd = cmd;
	if (size + x >= game.options.width || size + y >= game.options.height)
		return (game);
	new_piece = get_rotate(piece, new_piece, size);
	if (check_rotate_piece(game.tetras\
[game.current_piece], new_piece, game.screen) == 84)
		return (game);
	destroy_int_double_array(piece);
	game.tetras[game.current_piece].piece = new_piece;
	return (game);
}