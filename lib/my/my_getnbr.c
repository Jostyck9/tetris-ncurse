/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** return a string nuber as an int
*/

int	put_in_opposite_value(int result, int n_neg)
{
	if (n_neg % 2 == 1) {
		result = result * - 1;
	}
	return (result);
}

int	my_getnbr(char const *str)
{
	int n_neg = 0;
	int n = 0;
	int result = 0;

	while (str[n] == '-' || str[n] == '+') {
		if (str[n] == '-') {
			n_neg += 1;
		}
		n += 1;
	}
	while (str[n] >= '0' && str[n] <= '9') {
		result = result * 10 + (str[n] - '0');
		if (result < 0)
			return (0);
		n += 1;
	}
	result = put_in_opposite_value(result, n_neg);
	return (result);
}
