/*
** EPITECH PROJECT, 2017
** move_tetriminos.c
** File description:
** move the tetrimino right or left
*/

#include "tetris.h"

int check_tetra_on_left(int *screen, int current_piece)
{
	int i = 0;

	for (i = 0; screen[i] != current_piece + 1 && screen[i] != -1; i++);
	if (i == 0 && screen[i] == current_piece + 1)
		return (84);
	if (i != 0 && screen[i] == current_piece + 1 && screen[i - 1] != 0)
		return (84);
	return (0);
}

int check_can_move_left(game_t game, int current)
{
	int i = game.tetras[current].y;

	for (; game.screen[i] != NULL; i++) {
		if (check_tetra_on_left(game.screen[i], current) == 84)
			return (84);
	}
	return (0);
}

int check_tetra_on_right(int *screen, int i, int current_piece)
{
	for (; i != 0 && screen[i] != current_piece + 1; i--);
	if (screen[i] != current_piece + 1)
		return (0);
	if (screen[i + 1] != 0)
		return (84);
	return (0);
}

int check_can_move_right(game_t game, int current)
{
	int max_height = game.options.width - 1;
	int i = game.tetras[current].y;

	for (; game.screen[i] != NULL; i++) {
		if (check_tetra_on_right(\
game.screen[i], max_height, current) == 84)
			return (84);
	}
	return (0);
}

game_t move_tetriminos(game_t game, int cmd)
{
	if (cmd == 0) {
		if (check_can_move_left(game, game.current_piece) != 84)
			game.tetras[game.current_piece].x -= 1;
	} else {
		if (check_can_move_right(game, game.current_piece) != 84)
			game.tetras[game.current_piece].x += 1;
	}
	return (game);
}
