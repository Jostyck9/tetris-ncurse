/*
** EPITECH PROJECT, 2017
** check_size.c
** File description:
** check the size of the terminal
*/

#include "tetris.h"

int count_y_max(game_t game)
{
	int y_max = 0;

	if (game.options.height + 2 > 35)
		y_max = game.options.height + 2;
	else
		y_max = 35;
	return (y_max);
}

int count_x_max(game_t game)
{
	int x_max = 0;

	x_max = game.options.width + 8 + 24;
	return (x_max);
}

void check_size(game_t game)
{
	int y_max = count_y_max(game);
	int x_max = count_x_max(game);

	while (y_max + 1 > LINES || x_max + 1 > COLS) {
		clear();
		mvprintw(LINES / 2, (COLS / 2) - 10, "Enlarge the terminal");
		refresh();
	}
}
