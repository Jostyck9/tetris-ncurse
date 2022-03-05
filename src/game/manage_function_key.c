/*
** EPITECH PROJECT, 2017
** manage_function_key.c
** File description:
** manage the functions for the keys
*/

#include "tetris.h"

game_t manage_function_key(game_t game, int cmd)
{
	game_t (*manage_cmd[])(game_t game, int cmd) = {
		&move_tetriminos,
		&move_tetriminos,
		&rotate,
		&drop_the_piece,
		NULL,
		&pause_game,
	};

	if (cmd == 0 || cmd == 1 || cmd == 2||cmd == 3 || cmd == 5) {
		game = manage_cmd[cmd](game, cmd);
	}
	return (game);
}
