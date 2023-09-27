/*
** EPITECH PROJECT, 2023
** get_len_empty
** File description:
** get the size of empty place in memory
*/

#include "op.h"

int get_len_empty(int *map, int i)
{
    int j = 0;
    for (; i + j < MEM_SIZE; j++) {
        if (map[j + i] == -1) {
            continue;
        } else {
            break;
        }
    }
    return j;
}
