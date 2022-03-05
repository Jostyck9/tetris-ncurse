/*
** EPITECH PROJECT, 2017
** display_all_array.c
** File description:
** fonction display all array
*/

#include "tetris.h"

void display_game_screen(int size_x, int size_y, int posi_x, int posi_y)
{
	int x = 0;

	posi_x = display_top_array(posi_y, posi_x, size_x);
	posi_y++;
	for (int t = 0; t < size_y; posi_y++) {
		mvprintw(posi_y, posi_x - 1, "|");
		for (; x < size_x; x++) {
			mvprintw(posi_y, posi_x + x, " ");
		}
		mvprintw(posi_y, posi_x + x, "|");
		t++;
	}
	display_top_array(posi_y, posi_x, size_x);
}

void display_time_screen(int save, int p)
{
	static int time_game = 0;
	static double limit = 0;

	if (limit == 0)
		limit = clock() / CLOCKS_PER_SEC + 1;
	if (clock() / CLOCKS_PER_SEC >= limit) {
		time_game += 1;
		limit = clock() / CLOCKS_PER_SEC + 1;
	}
	mvprintw(save + 9, p, "Timer :      %d:%d", \
time_game / 60, time_game % 60);
}

void display_score_screen(my_option_t options, game_t game)
{
	int save = options.height * 0.25 + 1;
	int p = 12 + options.width;

	if (save > 20)
		save = 15;
	display_game_screen(22, 9, p, save);
	mvprintw(save + 4, p, "High Score : %i", game.hight_score);
	mvprintw(save + 2, p, "Score :  %i", game.score);
	mvprintw(save + 6, p, "Lines :  %i", game.nbr_lines);
	mvprintw(save + 7, p, "Level :  %i", game.level);
	display_time_screen(save, p);
}

void display_next_tetras(my_option_t options, game_t game, int current)
{
	int save = options.height * 0.25 + 12;
	int p = 19 + options.width;
	int x = game.tetras[current + 1].height + 1;
	int y = game.tetras[current + 1].width;

	if (save > 20)
		save = 15;
	for (int y = 0; game.tetras[current + 1].piece[y] \
!= NULL; y++) {
		for (int x = 0; game.tetras[current + 1].\
piece[y][x] != -1; x++) {
			display_all_tetra(save + y + 2, p + x + 1, game, \
game.tetras[current + 1].piece[y][x]);
		}
	}
	display_game_screen(y + my_strlen("next"), x, p, save);
	mvprintw(save, p + 1, "next");
}

void display_all_tetra(int y, int x, game_t game, int piece)
{
	int color = 0;

	if (piece == 0)
		return;
	color = game.tetras[piece - 1].color;
	init_pair(color + 9, COLOR_BLACK, color);
	attron(COLOR_PAIR(color + 9));
	if (piece != 0)
		mvprintw(y, x, " ");
	attron(COLOR_PAIR(1));
}