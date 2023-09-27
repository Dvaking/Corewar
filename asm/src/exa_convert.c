/*
** EPITECH PROJECT, 2023
** exa_convert
** File description:
** convert int to exa
*/
#include <stddef.h>
#include <stdlib.h>
#include "asm.h"

int binary_to_deci(int binary)
{
    int x = 0;
    int res = 0;
    while (binary / my_compute_power_rec(10, x) != 0)
        x++;
    while (x > 0) {
        res += (binary / my_compute_power_rec(10, x - 1) *
        my_compute_power_rec(2, x - 1));
        x--;
        binary = binary % my_compute_power_rec(10, x);
    }
    return res;
}

char *exa_convert(int c, int byte_nb)
{
    char str[] = "0123456789abcdef";
    char *dest = malloc(sizeof(char) * (byte_nb * 2 + 1));
    int start = byte_nb * 2 - 1;
    if (dest == NULL)
        return NULL;
    while (c >= 16) {
        start--;
        c = c / 16;
    }
    for (int y = 0; y < start; y++)
        dest[y] = '0';
    for (int i = start; i >= 0 && i < byte_nb * 2; i++) {
        c = c * 16;
        dest[i] = str[c / 16];
        c = c % 10;
    }
    dest[byte_nb * 2] = '\0';
    return (dest);
}
