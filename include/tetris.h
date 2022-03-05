/*
** EPITECH PROJECT, 2017
** tetris.h
** File description:
** include for the tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <term.h>

#include "my.h"

#define LIMIT 5
#define LIMIT_KEY 3

struct verif_fall_s {
	int current;
	int **screen;
};
typedef struct verif_fall_s verif_fall_t;

struct my_option_s {
	int help;
	int level;
	char *my_key_left;
	char *my_key_right;
	char *my_key_turn;
	char *my_key_drop;
	char *my_key_quit;
	char *my_key_pause;
	int width;
	int height;
	int hide;
	int debug;
};
typedef struct my_option_s my_option_t;

struct piece_s {
	char *name;
	int height;
	int width;
	int color;
	char **piece;
};
typedef struct piece_s piece_t;

struct tetra_game_s {
	int end;
	int empty;
	int **piece;
	int color;
	int height;
	int width;
	int x;
	int y;
};
typedef struct tetra_game_s tetra_game_t;

struct game_s {
	int error;
	int score;
	int hight_score;
	int level;
	int nbr_lines;
	int **screen;
	int current_piece;
	tetra_game_t *tetras;
	piece_t **pieces;
	my_option_t options;
};
typedef struct game_s game_t;

int recup_options(my_option_t *options, int ac, char **av);

int change_key_left(my_option_t *options, char *arg);
int change_key_right(my_option_t *options, char *arg);
int change_key_turn(my_option_t *options, char *arg);
int change_key_drop(my_option_t *options, char *arg);
int change_key_pause(my_option_t *options, char *arg);
int change_key_quit(my_option_t *options, char *arg);
int change_map_size(my_option_t *options, char *arg);
int change_level(my_option_t *options, char *arg);
int activ_help(my_option_t *options, char *arg);
int activ_without_next(my_option_t *options, char *arg);
int activ_debug(my_option_t *options, char *arg);
char **recup_paths(void);
int debug_mode(my_option_t *options, piece_t **pieces);
char **sort_paths(char **paths);
piece_t **recup_piece(void);
piece_t **transform_into_piece(piece_t **pieces, char **file, char *path);
piece_t **store_piece(piece_t **pieces, piece_t *new);
int count_nbr_line(char **file);
int check_size_block(char **file, piece_t *piece);
void debug_piece(piece_t *piece);
int count_size_pieces(piece_t **pieces);
int my_strcmp_beg(char *str1, char *str2);
int manage_key(my_option_t options);
int verif_pieces(piece_t **pieces, my_option_t options);
void my_putstr_spc(char *str);
int my_canon_mode(int value);
piece_t **clean_empty_lines_pieces(piece_t **pieces);
int game_loop(piece_t **pieces, my_option_t options);
void print_option(my_option_t *options, char *name);
my_option_t *destroy_options(my_option_t *options);
void display_elements(my_option_t options, game_t game);
void my_putstr_error(char *str);
int **destroy_int_double_array(int **array);
tetra_game_t *destroy_all_tetras(tetra_game_t *tetras);
int **create_screen_game(int height, int width);
tetra_game_t *init_tetras(void);
tetra_game_t create_random_tetri(piece_t **pieces, int value_tetri);
tetra_game_t *add_new_tetrimino(piece_t **pieces, game_t game, int current);
tetra_game_t random_position(tetra_game_t tetra, int **screen);
tetra_game_t *destroy_tetra(tetra_game_t *piece);
int check_if_can_fall(int **screen, tetra_game_t *pieces, int current);
char *replace_chara(char *str, char from, char to);
int count_spaces_end(char *str, int size);
int count_size_array(char **array);
int verif_opt(my_option_t options);
piece_t **destroy_pieces(piece_t **pieces);
void check_size(game_t game);
game_t manage_function_after_timer(game_t game);
game_t move_tetriminos(game_t game, int cmd);
game_t manage_function_key(game_t game, int cmd);
game_t drop_the_piece(game_t game, int cmd);
game_t rotate(game_t game, int cmd);
void game_over(game_t game);
void display_tetris(void);
game_t check_line_complete(int **screen, game_t game);
game_t pause_game(game_t game, int cmd);
int init_screen(void);
void print_key(char *key, char *my_key_code);
void display_game_screen(int size_x, int size_y, int posi_x, int posi_y);
void display_all_tetra(int y, int x, game_t game, int piece);
void display_score_screen(my_option_t options, game_t game);
int display_top_array(int i, int p, int size);
void display_next_tetras(my_option_t options, game_t game, int current);

extern const struct option long_opt[];

#endif //TETRIS_H_