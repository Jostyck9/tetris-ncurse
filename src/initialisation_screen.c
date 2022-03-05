/*
** EPITECH PROJECT, 2017
** initialisation.c
** File description:
** main function
*/

#include "tetris.h"

int **create_screen_game(int height, int width)
{
	int x = 0;
	int y = 0;
	int **screen = malloc(sizeof(int *) * (height + 1));

	if (screen == NULL)
		return (NULL);
	while (x < height) {
		screen[x] = malloc(sizeof(int) * (width + 1));
		if (screen[x] == NULL)
			return (destroy_int_double_array(screen));
		while (y < width) {
			screen[x][y] = 0;
			y++;
		}
		screen[x][y] = -1;
		x++;
		y = 0;
	}
	screen[x] = NULL;
	return (screen);
}