/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse a string
*/

int	size_of(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i += 1;
	}
	return (i);
}

char	*my_revstr(char *str)
{
	char c;
	int i = 0;
	int size_str = size_of(str) - 1;

	while (i < size_str) {
		c = str[i];
		str[i] = str[size_str];
		str[size_str] = c;
		i += 1;
		size_str -= 1;
	}
	return (str);
}
