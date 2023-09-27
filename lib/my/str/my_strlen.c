/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** task03
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    if (str == NULL)
        return -1;
    int i = 0;
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i += 1);
    return i;
}
