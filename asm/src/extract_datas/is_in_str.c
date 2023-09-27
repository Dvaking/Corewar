/*
** EPITECH PROJECT, 2023
** is_in_str
** File description:
** check if a char is a a str (both passed in the param)
*/
#include "asm.h"
#include <stddef.h>

int is_in_str(char const c, char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
