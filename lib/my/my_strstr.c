/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** find a string in another string
*/

int	compare(char *str, char const *to_find, int i)
{
	int n = 0;
	int result = 1;

	while (to_find[n] != '\0' && result == 1) {
		if (str[i] == to_find[n]) {
			i = i + 1;
			n = n + 1;
		} else {
			result = 0;
		}
	}
	return (result);
}

char	*my_strstr(char *str, char const *to_find)
{
	int i = 0;
	int end = 0;
	char *pointeur;

	while (str[i] != '\0' && end != 1) {
		if (str[i] == to_find[0]) {
			end = compare(str, to_find, i);
		}
		i += 1;
	}
	pointeur = &str[i - 1];
	return (pointeur);
}
