/*
** EPITECH PROJECT, 2017
** pause_game.c
** File description:
** fonction that pause the game
*/

#include "tetris.h"

game_t pause_game(game_t game, int cmd)
{
	cmd = -1;
	while (cmd == -1) {
		clear();
		mvprintw(LINES / 2, (COLS / 2) - 2, "PAUSE");
		refresh();
		cmd = manage_key(game.options);
		if (cmd != 4 && cmd != 5)
			cmd = -1;
	}
	if (cmd == 4)
		game.error = 1;
	return (game);
}
