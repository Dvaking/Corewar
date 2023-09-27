/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** spliter_tab
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);
int my_tablen(char **tab);

static int condition_separator(char const *str, int letter, char *separator)
{
    if (separator == NULL || str == NULL)
        return -1;
    for (int b = 0; separator[b] != '\0'; b += 1){
        if (str[letter] == separator[b])
            return 1;
    }
    return 0;
}

static char *malloc_condition(char const *str, int *i, char *separator)
{
    int b;
    int x;
    char *rts = NULL;
    if (str == NULL)
        return NULL;
    for (b = *i; condition_separator(str, b, separator) == 1 &&
    str[b] != '\0'; b += 1);
    rts = malloc(sizeof(char) * (b - *i) + 1);
    for (x = 0; *i != b; *i += 1){
        rts[x] = str[*i];
        x += 1;
    }
    rts[x] = '\0';
    return rts;
}

static char *malloc_str(char const *str, int *i, char *separator)
{
    int b;
    int x;
    char *rts = NULL;
    if (str == NULL)
        return NULL;
    for (b = *i; condition_separator(str, b, separator) != 1 &&
    str[b] != '\0'; b += 1);
    rts = malloc(sizeof(char) * (b - *i) + 1);
    for (x = 0; *i != b; *i += 1){
        rts[x] = str[*i];
        x += 1;
    }
    rts[x] = '\0';
    return rts;
}

static char **malloc_tab(char const *str, char *separator, int len_word,
int nbr_parameter)
{
    int count_word = 0;
    int j = 0;
    char **tab;
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0' && i < len_word;  i += 1){
        if (condition_separator(str, i, separator) == 1)
            continue;
        count_word += 1;
        for (j = i; str[j] != '\0' &&
        condition_separator(str, j, separator) != 1 && len_word > j &&
        str[j] != '\0'; j += 1);
        i = j;
    }
    count_word += nbr_parameter;
    tab = malloc(sizeof(char *) * (count_word + 1));
    if (tab == NULL)
        return NULL;
    tab[count_word] = NULL;
    return tab;
}

char **my_complexspliter(char const *str, char *separator, int nbr_parameter)
{
    int k = 0;
    int len_word;
    char **tab = NULL;
    if (str == NULL || separator == NULL)
        return NULL;
    if ((len_word = my_strlen(str)) == -1)
        return NULL;
    tab = malloc_tab(str, separator, len_word, nbr_parameter);
    for (int i = 0; str[i] != '\0' && i < len_word;){
        if (condition_separator(str, i, separator) == 1){
            tab[k] = malloc_condition(str, &i, separator);
            k += 1;
        } else {
            tab[k] = malloc_str(str, &i, separator);
            k += 1;
        }
    }
    tab[k] = NULL;
    return tab;
}
