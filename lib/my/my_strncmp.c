/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** return if string one is greater, less or egual to str2 for the n first bits
*/

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[2] != '\0')\
&& i <= n - 1) {
		i += 1;
	}
	return (s1[i] - s2[i]);
}
