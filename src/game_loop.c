/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** fonction game loop
*/

#include "tetris.h"

game_t destroy_game(game_t game)
{
	if (game.screen != NULL) {
		destroy_int_double_array(game.screen);
		game.screen = NULL;
	}
	if (game.tetras != NULL) {
		destroy_all_tetras(game.tetras);
		game.tetras = NULL;
	}
	game.error = 84;
	return (game);
}

game_t init_game(piece_t **pieces, my_option_t options)
{
	game_t game;

	game.score = 0;
	game.hight_score = 0;
	game.level = options.level;
	game.screen = NULL;
	game.tetras = NULL;
	game.nbr_lines = 0;
	game.current_piece = 0;
	game.options = options;
	game.screen = create_screen_game(options.height, options.width);
	if (game.screen == NULL)
		return (destroy_game(game));
	game.tetras = init_tetras();
	if (game.tetras == NULL)
		return (destroy_game(game));
	game.pieces = pieces;
	game.error = 0;
	return (game);
}

int ini_all(game_t game)
{
	if (game.error == 84)
		return (84);
	if (init_screen() == 84) {
		destroy_game(game);
		return (84);
	}
	return (0);
}

int game_loop(piece_t **pieces, my_option_t options)
{
	int cmd = 0;
	game_t game = init_game(pieces, options);

	if (ini_all(game) == 84)
		return (84);
	do {
		game = manage_function_after_timer(game);
		cmd = manage_key(options);
		if (cmd != -1)
			game = manage_function_key(game, cmd);
		if (cmd == 4 || game.error == 1)
			break;
		display_elements(options, game);
	} while (game.tetras[game.current_piece].x != -1);
	game_over(game);
	destroy_tetra(game.tetras);
	endwin();
	return (0);
}
