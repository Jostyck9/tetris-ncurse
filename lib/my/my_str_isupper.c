/*
** EPITECH PROJECT, 2017
** my_str_isupper.c
** File description:
** return 1 if only chararcter alpha in lowercase
*/

int	if_upper(char const *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		return (0);
	else
		return (1);
}

int	my_str_isupper(char const *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0' && change == 0) {
		change = if_upper(str, i);
		i += 1;
	}
	if (change == 0 || str[0] == '\0')
		return (1);
	else
		return (0);
}
