/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** lfork_command
*/

#include <unistd.h>

#include "macro.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int lfork_command(base_vm_s_t *base_vm, list_t *champ, int *map)
{
    if (!map || !champ || !base_vm)
        return KO;
    champ->champ_param.pc += 3;
    return OK;
}
