/*
** EPITECH PROJECT, 2017
** concat_params.c
** File description:
** turn the command lines parameter into a sigle string
*/

#include <stdlib.h>

void	replace_last_chara(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i += 1;
	}
	str[i - 1] = '\0';
}

char	*my_strcat_double(char *dest, char const **src, int num)
{
	int i = 0;
	int n = 0;

	while (dest[i] != '\0') {
		i += 1;
	}
	while (src[num][n] != '\0') {
		dest[i] = src[num][n];
		i += 1;
		n += 1;
	}
	dest[i] = '\n';
	return (dest);
}

char	*concat_params(int argc, char **argv)
{
	char *str;
	int nbr_chara = 0;
	int num = 0;

	while (num < argc) {
		nbr_chara = nbr_chara + my_strlen(argv[num]) + 1;
		num += 1;
	}
	str = malloc(sizeof(char) * (nbr_chara + 1));
	num = 0;
	while (num < argc) {
		my_strcat_double(str, argv, num);
		num += 1;
	}
	replace_last_chara(str);
	return (str);
}
