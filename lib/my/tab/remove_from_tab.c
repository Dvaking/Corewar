/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** copy_tab
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib_my.h"
#include "struct_str.h"

static char **modif_tab(char **src, char *str, int len_src)
{
    char **dest = NULL;
    int x = 0;
    int len_str = 0;
    if (src == NULL || str == NULL || (dest = malloc(sizeof(char *) *
    (len_src + 1))) == NULL)
        return NULL;
    dest[len_src] = NULL;
    if ((len_str = my_strlen(str)) == -1)
        return NULL;
    for (int y = 0; src[y] != NULL; y += 1){
        if (my_strncmp(str, src[y], len_str) == 0){
            continue;
        } else {
            dest[x] = my_strcpy(src[y]);
            x += 1;
        }
    }
    return dest;
}

char **reduce_tab(char **src, char *str)
{
    int len_src = 0;
    char **dest = NULL;
    if (!src || !str)
        return NULL;
    if ((len_src = my_tablen(src)) == -1)
        return NULL;
    if ((dest = modif_tab(src, str, len_src)) == NULL)
        return NULL;
    return dest;
}
