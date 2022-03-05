/*
** EPITECH PROJECT, 2017
** game_over.c
** File description:
** fonction game over
*/

#include "tetris.h"

void display_score_end(int score)
{
	attron(COLOR_PAIR(2));
	mvprintw(LINES / 2, (COLS / 2) - 6, "GAME OVER");
	mvprintw(LINES / 2 + 1, (COLS / 2) - 5, "Score %i", score);
	attron(COLOR_PAIR(3));
	mvprintw(LINES / 2 + 3, (COLS / 2) - 7, "PRESS SPACE");
}

void game_over(game_t game)
{
	if (game.tetras[game.current_piece].x != -1)
		return;
	nodelay(stdscr, FALSE);
	do {
		clear();
		display_tetris();
		display_score_end(game.score);
		refresh();
	} while (getch() != ' ');
}
