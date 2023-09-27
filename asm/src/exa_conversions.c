/*
** EPITECH PROJECT, 2023
** exa_conversions
** File description:
** exa_conversions
*/
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "asm.h"

int get_function_code(char *function)
{
    int i = 0;
    if (function == NULL)
        return KO;
    while (op_tab[i].mnemonique != NULL &&
    my_strcmp(function, op_tab[i].mnemonique) != 0)
        i++;
    if (op_tab[i].mnemonique == NULL)
        return KO;
    return i + 1;
}

int get_coding_byte(char **args)
{
    int byte = 0;
    if (args == NULL)
        return KO;
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == 'r' && args[i][1] > '0' && args[i][1] < '6')
            byte += 1 * my_compute_power_rec(100, 3 - i);
        if (is_in_str('%', args[i]) == 1)
            byte += 10 * my_compute_power_rec(100, 3 - i);
        if (my_str_isnum(args[i]) == 1)
            byte += 11 * my_compute_power_rec(100, 3 - i);
    }
    return binary_to_deci(byte);
}

void get_nb_size(int nb, FILE *file, int bytes)
{
    int none = 0;
    int size = 1;
    while (nb > 254)
        size++;
    fwrite(&none, bytes - size, 1, file);
    if (fseek(file, 0, SEEK_END) == -1)
        return;
    fwrite(&nb, size, 1, file);
    if (fseek(file, 0, SEEK_END) == -1)
        return;
}

int get_arg_bytes(char **args, int cap, FILE *file)
{
    int nb = 0;
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == 'r' && args[i][1] > '0' && args[i][1] < '6') {
            nb = args[i][1] - '0';
            get_nb_size(nb, file, 1);
        }
        if (is_in_str('%', args[i]) == 1 && is_in_str(':', args[i]) == 0) {
            nb = my_getnbr(args[i]);
            get_nb_size(nb, file, 4 - (2 * cap));

        }
        if (is_in_str(':', args[i]) == 1 || my_str_isnum(args[i]) == 1) {
            nb = my_getnbr(args[i]);
            get_nb_size(nb, file, 2);
        }
        nb = 0;
    }
    return OK;
}
