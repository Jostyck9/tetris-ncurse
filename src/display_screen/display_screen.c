/*
** EPITECH PROJECT, 2017
** display_screen.c
** File description:
** fonction display
*/

#include "tetris.h"

int *take_line_tetra(int *tetras, int *screen, int x)
{
	int u = 0;

	while (screen != NULL && tetras[u] != -1) {
		if (screen[x] == 0)
			screen[x] = tetras[u];
		x++;
		u++;
	}
	return (screen);
}

int **add_tetras_current(int **screen, tetra_game_t tetras, int piece)
{
	int x = tetras.x;
	int y = tetras.y;
	int sx = 0;
	int sy = 0;

	while (screen[sy] != NULL) {
		if (screen[sy][sx] == piece + 1) {
			screen[sy][sx] = 0;
		}
		sx++;
		if (screen[sy][sx] == -1) {
			sy++;
			sx = 0;
		}
	}
	for (int t = 0; screen[y] != NULL && tetras.piece[t] != NULL; t++) {
		screen[y] = take_line_tetra(tetras.piece[t], screen[y], x);
		y++;
	}
	return (screen);
}

void display_all_game(my_option_t options, game_t game)
{
	int x = 0;
	int y = 0;
	int current = game.current_piece;

	display_game_screen(options.width, options.height, 8, 0);
	game.screen = add_tetras_current(game.screen, \
game.tetras[current], current);
	while (game.screen[y] != NULL) {
		if (game.screen[y][x] > 0)
			display_all_tetra(y + 1, x + 8, \
game, game.screen[y][x]);
		x++;
		if (game.screen[y][x] == -1) {
			y++;
			x = 0;
		}
	}
	attron(COLOR_PAIR(1));
}

void display_elements(my_option_t options, game_t game)
{
	if (game.tetras[game.current_piece].x == -1)
		return;
	check_size(game);
	clear();
	display_tetris();
	display_score_screen(options, game);
	if (game.options.hide == 0)
		display_next_tetras(options, game, game.current_piece);
	display_all_game(options, game);
	refresh();
}
