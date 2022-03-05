/*
** EPITECH PROJECT, 2017
** init_screen.c
** File description:
** fonction that initialise the screen
*/

#include "tetris.h"

int init_screen_caract(void)
{
	if (has_colors() == FALSE) {
		my_putstr_error("Error: failed to start_color\n");
		endwin();
		return (84);
	}
	start_color();
	if (noecho() == ERR) {
		my_putstr_error\
("Error: failed to disable the echo on screen\n");
		endwin();
		return (84);
	}
	if (nodelay(stdscr, TRUE) == ERR) {
		my_putstr_error("Error: failed to enable the nodelay\n");
		endwin();
		return (84);
	}
	return (0);
}

int init_screen(void)
{
	if (initscr() == NULL) {
		my_putstr_error("Error: failed to start screen\n");
		return (84);
	}
	if (init_screen_caract() == 84)
		return (84);
	if (curs_set(FALSE) == ERR) {
		my_putstr_error("Error: failed to disable cursor\n");
		endwin();
		return (84);
	}
	return (0);
}
