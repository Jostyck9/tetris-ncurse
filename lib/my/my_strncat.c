/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** concatenates two strings from n bytes
*/

char	*my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int n = 0;

	while (dest[i] != '\0') {
		i += 1;
	}
	while (n < nb && src[n] != '\0') {
		dest[i] = src[n];
		i += 1;
		n += 1;
	}
	dest[i] = '\0';
	return (dest);
}
