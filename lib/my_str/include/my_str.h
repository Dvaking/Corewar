/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#ifndef HEADER
    #define HEADER
    void my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    int my_showstr(char const *str);
    int my_showmem(char const *str, int size);
    int my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_show_word_array(char *const *tab);
    char **my_str_to_word_array(char const * str);
    int exponancial(int nb);
    int build_nb(char const *str, int *start, int *end, int *signe);
    int exponancial_2(int nb);
    int find_count(int nb);
    void final(int * array, int * i, int * j);
    int add_str(char const * str, int start, int end, char **array);
    int count_special_char(char const *str);
    char *creat_word_from_array(int start,char const * str, int end,
    char *temp);
    int my_strlen_3(char const *str);
#endif /* HEADER */
