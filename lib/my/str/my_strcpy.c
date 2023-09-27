/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** sauvegarder un mot dans une autre variable
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib_my.h"

char *my_strcpy(char const *src)
{
    int count = 0;
    char *dest = NULL;
    if (src == NULL)
        return NULL;
    if ((count = my_strlen(src)) == -1)
        return NULL;
    dest = malloc(sizeof(char) * (count + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0' && src[i] != '\n'; i += 1 )
        dest[i] = src[i];
    dest[count] = '\0';
    return dest;
}
