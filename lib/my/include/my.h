/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#ifndef MY_H_
#define MY_H_

int my_compute_power_rec(int, int);
int error(int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int size(int);
int negative(int, char);
int my_isneg(int);
int my_is_prime(int);
void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int size_of(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
int if_letter(char *, int);
int if_space(char *, int);
int if_no_letter(char *, int, int);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int if_alpha(char *, int);
int my_str_islower(char const *);
int if_lower(char *, int);
int my_str_isnum(char const *);
int if_num(char *, int);
int my_str_isprintable(char const *);
int if_printable(char *, int);
int my_str_isupper(char const *);
int if_upper(char *, int);
int my_strlen(char const *);
char *my_strlowcase(char *);
int if_letter_uppercase(char *, int);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
int compare(char *, char const *, int);
char *my_strupcase(char *);
int if_letter_lowercase(char *, int);
void my_swap(int *, int *);
char **my_str_to_word_array(char const *, char separator);
int how_many_word(char const *);
int chara_in_word(char const *, int);
int char_alpha(char *);
char *my_strdup(char const *);
char *concat_params(int, char **);
char *my_strcat_double(char *, char const **, int);
char *replace_last_chara(char *);
int my_show_word_array(char * const *);
int print_word(char * const *, int);
char **destroy_array2d(char **str);
int	my_str_isalphanum(char const *str);

#endif /* MY_H_ */
