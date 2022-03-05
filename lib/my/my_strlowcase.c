/*
** EPITECH PROJECT, 2017
** my_strlowcase.c
** File description:
** put the strings in lowercase
*/

int	if_letter_uppercase(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
		return (1);
	else
		return (0);
}

char	*my_strlowcase(char *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0') {
		change = if_letter_uppercase(str, i);
		if (change == 1)
			str[i] = str[i] + 32;
		i += 1;
	}
	return (str);
}
