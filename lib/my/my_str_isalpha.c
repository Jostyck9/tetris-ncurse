/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** return 1 if only chararcter alpha
*/

int	if_alpha(char const *str, int i)
{
	if ((str[i] >= 65 && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		return (0);
	else
		return (1);
}

int	my_str_isalpha(char const *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0' && change == 0) {
		change = if_alpha(str, i);
		i += 1;
	}
	if (change == 0 || str[0] == '\0')
		return (1);
	else
		return (0);
}
