/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>

int my_str_isalpha_num(char const *str, int i);
int my_strlen(char const *str);

static char *malloc_and_create_str(char const *str, int i, int j)
{
    if (str == NULL)
        return NULL;
    char *word = malloc(sizeof(char) * (j + 1));
    if (str == NULL || word == NULL)
        return NULL;
    word[j] = '\0';
    for (int count = 0; count != j; count += 1)
        word[count] = str[i + count];
    return word;
}

static char **malloc_tab(char const *str, int len_word)
{
    if (str == NULL)
        return NULL;
    int count_word = 0;
    int j = 0;
    char **tab = NULL;
    for (int i = 0; str[i] != '\0' && i < len_word; i += 1){
        if (my_str_isalpha_num(str, i) == 1)
            continue;
        count_word += 1;
        for (j = i; str[j] != '\0' && my_str_isalpha_num(str, j) == 0; j += 1);
        i = j;
    }
    tab = malloc(sizeof(char *) * (count_word + 1));
    if (tab == NULL)
        return NULL;
    tab[count_word] = NULL;
    return tab;
}

char **my_str_to_word_array(char const *str)
{
    if (str == NULL)
        return NULL;
    int j = 0;
    int k = 0;
    int len_word = my_strlen(str);
    if (len_word == -1)
        return NULL;
    char **tab = malloc_tab(str, len_word);
    for (int i = 0; str[i] != '\0' && i < len_word; i += 1){
        if (my_str_isalpha_num(str, i) == 1)
            continue;
        for (j = 0; str[j + i] != '\0' && my_str_isalpha_num(str, (j + i)) == 0;
        j += 1);
        tab[k] = malloc_and_create_str(str, i, j);
        k += 1;
        i += j;
    }
    return tab;
}
