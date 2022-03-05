/*
** EPITECH PROJECT, 2017
** canon_mode.c
** File description:
** pass th eterminal in canonique or no canonique mode
*/

#include "tetris.h"

int my_canon_mode(int value)
{
	static struct termios old;
	static struct termios new;

	if (value == 0) {
		if (ioctl(0, TCGETS, &old) < 0)
			return (84);
		new.c_lflag &= ~(ICANON|ECHO);
		new.c_cc[VMIN] = 1;
		new.c_cc[VTIME] = 0;
		if (ioctl(0, TCSETS, &new) < 0)
			return (84);
	} else {
		if (ioctl(0, TCSETS, &old) < 0)
			return (84);
	}
	return (0);
}
