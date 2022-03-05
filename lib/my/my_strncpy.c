/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copies n character into another string
*/

char	*my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i + 1 <= n) {
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}
