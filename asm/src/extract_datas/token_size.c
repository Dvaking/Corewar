/*
** EPITECH PROJECT, 2023
** token_size
** File description:
** return token size
*/
#include "asm.h"

int tok_size(char const *str, char const *tok)
{
    int size = 0;
    while (str[size] != '\0' && is_in_str(str[size], tok) == 0)
        size++;
    return (size);
}
