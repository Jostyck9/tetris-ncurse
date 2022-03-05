/*
** EPITECH PROJECT, 2017
** display_tetris.c
** File description:
** display the tetris
*/

#include "tetris.h"

void initalisation_color_tetris(void)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_CYAN);
	init_pair(6, COLOR_BLACK, COLOR_RED);
}

int display_letter(char *str, int color, int x, int y)
{
	attron(COLOR_PAIR(color));
	if (y == 8) {
		mvprintw(x, 0, str);
		mvprintw(x, 3, str);
	} else
		mvprintw(x, y, str);
	attron(COLOR_PAIR(1));
	x++;
	return (x);
}

void display_letter_next_step(int x)
{
	for (int i = 0; i < 4; i++)
		x = display_letter(" ", 3, x, 2);
	x = display_letter("    ", 4, x + 1, 0);
	x = display_letter(" ", 4, x, 8);
	x = display_letter("   ", 4, x, 0);
	x = display_letter(" ", 4, x, 8);
	x = display_letter(" ", 4, x, 8);
	x = display_letter(" ", 5, x + 1, 2) + 1;
	for (int i = 0; i < 3; i++)
		x = display_letter(" ", 5, x, 2);
	x = display_letter("     ", 6, x + 1, 0);
	x = display_letter(" ", 6, x, 0);
	x = display_letter("     ", 6, x, 0);
	x = display_letter(" ", 6, x, 4);
	x = display_letter("     ", 6, x, 0);
}

void display_tetris(void)
{
	int x = 0;

	initalisation_color_tetris();
	x = display_letter("     ", 6, x, 0);
	for (int i = 0; i < 4; ++i)
		x = display_letter(" ", 6, x, 2);
	x = display_letter("     ", 2, x + 1, 0);
	x = display_letter(" ", 2, x, 0);
	x = display_letter("   ", 2, x, 0);
	x = display_letter(" ", 2, x, 0);
	x = display_letter("     ", 2, x, 0);
	x = display_letter("     ", 3, x + 1, 0);
	display_letter_next_step(x);
}

int display_top_array(int i, int p, int size)
{
	int x = 0;

	mvprintw(i, p - 1, "<");
	for (; x < size; x++) {
		mvprintw(i, x + p, "-");
	}
	mvprintw(i, x + p, ">");
	return (p);
}