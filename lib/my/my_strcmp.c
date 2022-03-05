/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** return if string1 one is greater, less or egual to str2
*/

int	my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0')) {
		i += 1;
	}
	return (s1[i] - s2[i]);
}
