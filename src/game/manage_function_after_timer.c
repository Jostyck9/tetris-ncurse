/*
** EPITECH PROJECT, 2017
** manage_function_after_timer.c
** File description:
** fonction display
*/

#include "tetris.h"

game_t init_first_tetra(game_t game)
{
	game.tetras = add_new_tetrimino(game.pieces, game, 0);
	game.tetras[0] = random_position(game.tetras[0], game.screen);
	game.tetras = add_new_tetrimino(game.pieces, game, 1);
	return (game);
}

game_t manage_function_after_timer(game_t game)
{
	static double limit = 0;
	double my_clock = clock() * 10 / CLOCKS_PER_SEC;

	if (limit == 0) {
		game = init_first_tetra(game);
		limit = clock() * 10 / CLOCKS_PER_SEC + (LIMIT / game.level);
	}
	if (my_clock > limit) {
		if (check_if_can_fall(game.screen, game.tetras, \
game.current_piece) == 0) {
			game = check_line_complete(game.screen, game);
			game.current_piece += 1;
			game.tetras[game.current_piece] = random_position(\
game.tetras[game.current_piece], game.screen);
			game.tetras = add_new_tetrimino(game.pieces, game, \
game.current_piece + 1);
		}
		limit = clock() * 10 / CLOCKS_PER_SEC + (LIMIT / game.level);
	}
	return (game);
}
