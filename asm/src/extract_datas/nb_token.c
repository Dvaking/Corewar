/*
** EPITECH PROJECT, 2023
** nb_token
** File description:
** reurn the number of token from a str
*/
#include "asm.h"

int nb_tok(char const *str, char const *tok)
{
    int i = 1;
    int nb_toks = 0;
    while (str[i] != '\0') {
        if (is_in_str(str[i], tok) == 1 && is_in_str(str[i - 1], tok) == 0)
            nb_toks++;
        i++;
    }
    if (is_in_str(str[i - 1], tok) == 0)
        nb_toks++;
    return (nb_toks);
}
