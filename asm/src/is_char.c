/*
** EPITECH PROJECT, 2023
** is_char
** File description:
** is_char
*/

#include <stdbool.h>

int is_char(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}
