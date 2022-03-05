/*
** EPITECH PROJECT, 2017
** random_position.c
** File description:
** put the tetrimino at a random position
*/

#include "tetris.h"

int check_line_place(int *piece, int *screen, int x)
{
	for (int j = 0; piece[j] != -1; j++) {
		if (piece[j] != 0 && screen[x + j] != 0)
			return (84);
	}
	return (0);
}

int check_if_got_place(tetra_game_t *tetra, int **screen)
{
	for (int i = 0; tetra->piece[i] != NULL; i++) {
		if (check_line_place(\
tetra->piece[i], screen[i], tetra->x) == 84) {
			tetra->x += 1;
			return (84);
		}
	}
	return (0);
}

int found_empty_position(int **screen, int x)
{
	for (int i = x; screen[0][i] != -1; i++) {
		if (screen[0][i] == 0)
			return (i);
	}
	return (-1);
}

tetra_game_t random_position(tetra_game_t tetra, int **screen)
{
	int size = 0;

	tetra.y = 0;
	for (; screen[0][size] != -1; size++);
	tetra.x = size / 2 - tetra.height / 2;
	if (tetra.x < 0)
		tetra.x = 0;
	if (check_if_got_place(&tetra, screen) == 84)
		tetra.x = -1;
	return (tetra);
}
