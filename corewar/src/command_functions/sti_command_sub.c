/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** sti_command_sub
*/

#include <unistd.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int replace_value(list_t *champ, int *map, int move, int register_pos)
{
    int value = 0;
    if (!champ || !map)
        return KO;
    value = champ->champ_param.regist[register_pos];
    map[move + 3] = value;
    return OK;
}
