/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** my_tabcpy
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib_my.h"

char **my_tabcpy(char **src)
{
    int len_tab = 0;
    char **dest = NULL;
    if (src == NULL)
        return NULL;
    if ((len_tab = my_tablen(src)) == -1)
        return NULL;
    if ((dest = malloc(sizeof(char *)* (len_tab + 1))) == NULL)
        return NULL;
    dest[len_tab] = NULL;
    for (int y = 0; src[y] != NULL; y += 1){
        if ((dest[y] = my_strcpy(src[y])) == NULL)
            return NULL;
    }
    return dest;
}
