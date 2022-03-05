/*
** EPITECH PROJECT, 2017
** check_line_complete.c
** File description:
** check_all_tetriminos if a line is complete
*/

#include "tetris.h"

int check_line_tetris(int *screen)
{
	int x = 0;

	while (screen[x] > 0)
		x++;
	if (screen[x] == -1)
		return (1);
	return (0);
}

int *delete_line_tetris(int *screen)
{
	int x = 0;

	while (screen[x] != -1) {
		screen[x] = 0;
		x++;
	}
	return (screen);
}

int **move_line(int **screen, int y)
{
	for (int i = y; i > 1; i--) {
		for (int col = 0; screen[i][col] != -1; col++) {
			screen[i][col] = screen[i - 1][col];
		}
	}
	for (int j = 0; screen[0][j] != -1; j++)
		screen[0][j] = 0;
	return (screen);
}

game_t update_lvl(game_t game)
{
	if (game.nbr_lines % 10 == 0)
		game.level += 1;
	return (game);
}

game_t check_line_complete(int **screen, game_t game)
{
	int y = 0;
	int save = 0;
	int line = 0;

	for (; screen[0][line] != -1; line++);
	while (screen[y] != NULL) {
		save = check_line_tetris(screen[y]);
		if (save == 1) {
			game.score += 10;
			game.nbr_lines += 1;
			screen[y] = delete_line_tetris(screen[y]);
			screen = move_line(screen, y);
			game = update_lvl(game);
		}
		y++;
	}
	return (game);
}
