/*
** EPITECH PROJECT, 2023
** get_nb_bytes_from_body
** File description:
** get_nb_bytes_from_body
*/

#include <stddef.h>

#include "asm.h"

static void get_nb_bytes_inner(char **args, int *start, int cap)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == 'r' && args[i][1] > '0' && args[i][1] < '6')
            *start += 2;
        if (is_in_str('%', args[i]) == 1 && is_in_str(':', args[i]) == 0)
            *start += (4 - 2 * cap) * 2;
        if (is_in_str(':', args[i]) == 1 || my_str_isnum(args[i]) == 1)
            *start += 4;
    }
}

int get_nb_bytes(body_t *body, int command)
{
    int start = 0;
    body_t *tempo = body;
    int cap = need_cap(command);
    while (tempo != NULL) {
        start++;
        get_nb_bytes_inner(body->args, &start, cap);
        tempo = tempo->next;
    }
    return start;
}
