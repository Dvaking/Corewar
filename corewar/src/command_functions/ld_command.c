/*
** EPITECH PROJECT, 2023
** ld_command
** File description:
** takes 2 parameters. It loads the value of the first parameter into the
** second parameter, which must be a register (not the PC). This operation
** modifies the carry. ld 34,r3 loads the REG_SIZE bytes starting at the
** address PC + 34 % IDX_MOD into r3
*/

#include <unistd.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int ld_command(base_vm_s_t *base_vm, list_t *champ, int *map)
{
    coding_byte_s_t coding_byte = {.opt1 = "\0\0\0", .opt2 = "\0\0\0",
    .opt3 = "\0\0\0", .opt4 = "\0\0\0"};
    if (!map || !champ || !base_vm)
        return KO;
    champ->champ_param.carry = 1;
    if (coding_byte_function(map[champ->champ_param.pc + 1], &coding_byte)
    != OK)
        return KO;
    if ((champ->champ_param.pc += move_byte(&coding_byte, 0) % MEM_SIZE) == KO)
        return KO;
    return OK;
}
