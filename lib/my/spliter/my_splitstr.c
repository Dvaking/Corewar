/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** my_splitstr
*/

#include <stddef.h>
#include <stdlib.h>

#include "proto_lib_my.h"

static char *malloc_and_create_str(char const *str, int i, int j)
{
    int count;
    char *word = malloc(sizeof(char) * (j + 1));
    if (str == NULL || word == NULL)
        return NULL;
    for (count = 0; count < j; count += 1)
        word[count] = str[i + count];
    word[j] = '\0';
    return word;
}

static char **malloc_tab(char const *str, int separator, int len_word)
{
    int count_word = 0;
    int j = 0;
    char **tab;
    if (str == NULL)
        return NULL;
    for (int i = 0; i < len_word && str[i] != '\0'; i += 1) {
        if (str[i] == separator)
            continue;
        count_word += 1;
        for (j = i; j < len_word && str[j] != '\0' && str[j] != separator; j++);
        i = j;
    }
    tab = malloc(sizeof(char *) * (count_word + 1));
    if (tab == NULL)
        return NULL;
    tab[count_word] = NULL;
    return tab;
}

char **my_splitstr(char const *str, int separator)
{
    int j = 0;
    int k = 0;
    int len_word;
    if (str == NULL)
        return NULL;
    if ((len_word = my_strlen(str)) == -1)
        return NULL;
    char **tab = malloc_tab(str, separator, len_word);
    for (int i = 0; i < len_word && str[i] != '\0'; i += 1){
        if (str[i] == separator)
            continue;
        for (j = 0; str[j + i] != '\0' && str[j + i] != separator &&
        (i + j) < len_word; j += 1);
        tab[k] = malloc_and_create_str(str, i, j);
        tab[k][j] = '\0';
        k += 1;
        i += j;
    }
    tab[k] = NULL;
    return tab;
}
