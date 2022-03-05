/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/

#include "tetris.h"

my_option_t *destroy_options(my_option_t *options)
{
	free(options->my_key_left);
	free(options->my_key_right);
	free(options->my_key_turn);
	free(options->my_key_drop);
	free(options->my_key_quit);
	free(options->my_key_pause);
	options->my_key_left = NULL;
	options->my_key_right = NULL;
	options->my_key_turn = NULL;
	options->my_key_drop = NULL;
	options->my_key_quit = NULL;
	options->my_key_pause = NULL;
	return (options);
}

my_option_t initialise_spec_opt(my_option_t option)
{
	option.my_key_left[0] = 27;
	option.my_key_left[1] = '[';
	option.my_key_left[2] = 'D';
	option.my_key_right[0] = 27;
	option.my_key_right[1] = '[';
	option.my_key_right[2] = 'C';
	option.my_key_turn[0] = 27;
	option.my_key_turn[1] = '[';
	option.my_key_turn[2] = 'A';
	option.my_key_drop[0] = 27;
	option.my_key_drop[1] = '[';
	option.my_key_drop[2] = 'B';
	return (option);
}

my_option_t initialise_options(void)
{
	my_option_t options;

	options.help = 0;
	options.level = 1;
	options.my_key_left = my_strdup("^ED");
	options.my_key_right = my_strdup("^EC");
	options.my_key_turn = my_strdup("^EA");
	options.my_key_drop = my_strdup("^EB");
	options.my_key_quit = my_strdup("q");
	options.my_key_pause = my_strdup(" ");
	options.width = 20;
	options.height = 10;
	options.hide = 0;
	options.debug = 0;
	if (options.my_key_left == NULL || options.my_key_right == NULL || \
options.my_key_turn == NULL || options.my_key_drop == NULL || \
options.my_key_quit == NULL || options.my_key_pause == NULL)
		destroy_options(&options);
	options = initialise_spec_opt(options);
	return (options);
}

piece_t **destroy_pieces(piece_t **pieces)
{
	if (pieces == NULL)
		return (NULL);
	for (int i = 0; pieces[i] != NULL; i++) {
		free(pieces[i]->name);
		destroy_array2d(pieces[i]->piece);
		free(pieces[i]);
	}
	free(pieces);
	return (NULL);
}

int main(int ac, char **av)
{
	my_option_t opt = initialise_options();
	piece_t **pieces = NULL;
	int game = 0;

	if (opt.my_key_left == NULL)
		return (84);
	if (recup_options(&opt, ac, av) == 84 || verif_opt(opt) == 84) {
		destroy_options(&opt);
		return (84);
	}
	pieces = recup_piece();
	pieces = clean_empty_lines_pieces(pieces);
	if (debug_mode(&opt, pieces) == 84 || \
verif_pieces(pieces, opt) == 84) {
		destroy_options(&opt);
		return (84);
	}
	game = game_loop(pieces, opt);
	destroy_options(&opt);
	destroy_pieces(pieces);
	return (game);
}
