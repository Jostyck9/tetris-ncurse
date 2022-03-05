/*
** EPITECH PROJECT, 2017
** my_strcapitalize.c
** File description:
** put the strings in capitalize for the first words
*/

int	if_no_letter(char *str, int i, int result)
{
	if (str[i - 1] >= 'A' && str[i - 1] <= 'Z' && result != 0)
		result = 0;
	if (str[i - 1] >= '0' && str[i - 1] <= '9' && result != 0)
		result = 0;
	return (result);
}

int	if_space(char *str, int i)
{
	int int_return = 1;

	if (i == 0 || (str[i - 1] == ' ' && i != 0))
		int_return = 1;
	if (str[i - 1] >= 'a' && str[i - 1] <= 'z' && int_return != 0)
		int_return = 0;
	int_return = if_no_letter(str, i, int_return);
	return (int_return);
}

int	if_letter(char *str, int i)
{
	int space = if_space(str, i);

	if (str[i] >= 'A' && str[i] <= 'Z' && space == 0)
		return (1);
	else if (str[i] >= 'a' && str[i] <= 'z' && space == 1)
		return (-1);
	else
		return (0);
}

char	*my_strcapitalize(char *str)
{
	int i = 0;
	int change = 0;

	while (str[i] != '\0') {
		change = if_letter(str, i);
		if (change == 1)
			str[i] = str[i] + 32;
		else if (change == -1)
			str[i] = str[i] - 32;
		i += 1;
	}
	return (str);
}
