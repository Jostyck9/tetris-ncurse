/*
** EPITECH PROJECT, 2017
** my_strupcase.c
** File description:
** put the strings in uppercase
*/

int	if_letter_lowercase(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		return (1);
	else
		return (0);
}

char	*my_strupcase(char *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0') {
		change = if_letter_lowercase(str, i);
		if (change == 1)
			str[i] = str[i] - 32;
		i += 1;
	}
	return (str);
}
