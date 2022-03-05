/*
** EPITECH PROJECT, 2017
** check_if_can_fall.c
** File description:
** check_all_tetriminos if they can fall and drop them
*/

#include "tetris.h"

int check_line_fall(verif_fall_t check, tetra_game_t tetra, int line, int i)
{
	int **screen = check.screen;
	int current = check.current;

	if (tetra.piece[line][i] != 0) {
		if (screen[tetra.y + line + 1] == NULL)
			return (0);
		if (screen[tetra.y + line + 1][tetra.x + i] != 0 && \
screen[tetra.y + line + 1][tetra.x + i] != current + 1)
			return (0);
	}
	return (84);
}

int line_can_fall(int **screen, tetra_game_t tetra, int line, int current)
{
	verif_fall_t check;

	check.screen = screen;
	check.current = current;
	for (int i = 0; tetra.piece[line][i] != -1; i++) {
		if (check_line_fall(check, tetra, line, i) == 0)
			return (0);
	}
	return (1);
}

int check_piece_can_fall(int **screen, tetra_game_t *tetra, int current)
{
	for (int i = 0; tetra[current].piece[i] != NULL; i++) {
		if (line_can_fall(screen, tetra[current], i, current) == 0)
			return (0);
	}
	tetra[current].y += 1;
	return (1);
}

int check_if_can_fall(int **screen, tetra_game_t *pieces, int current)
{
	int can_fall = 0;

	if (screen == NULL || pieces == NULL)
		return (0);
	if (pieces[current].empty != 1)
		can_fall = check_piece_can_fall(screen, pieces, current);
	return (can_fall);
}
