/*
** EPITECH PROJECT, 2017
** drop_the_piece.c
** File description:
** drop the current piece
*/

#include "tetris.h"

game_t drop_the_piece(game_t game, int cmd)
{
	cmd = cmd;

	check_if_can_fall(game.screen, game.tetras, game.current_piece);
	return (game);
}
