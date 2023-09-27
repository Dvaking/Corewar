/*
** EPITECH PROJECT, 2023
** free_strcpy
** File description:
** free_strcpy
*/
#include <stddef.h>
#include <stdlib.h>
#include "asm.h"
char *my_free_strcpy (char *dest, char *src)
{
    if (src == NULL)
        return NULL;
    int len = my_strlen(src);
    for (int i = 0; i < len; i += 1) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    free(src);
    return dest;
}
