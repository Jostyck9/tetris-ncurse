/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** return 1 if only num
*/

int	if_num(char const *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	else
		return (1);
}

int	my_str_isnum(char const *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0' && change == 0) {
		change = if_num(str, i);
		i += 1;
	}
	if (change == 0 || str[0] == '\0')
		return (1);
	else
		return (0);
}
