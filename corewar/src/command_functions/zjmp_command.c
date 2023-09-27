/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** zjmp_command
*/

#include <unistd.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int zjmp_command(base_vm_s_t *base_vm, list_t *champ, int *map)
{
    coding_byte_s_t coding_byte = {.opt1 = "\0\0\0", .opt2 = "\0\0\0",
    .opt3 = "\0\0\0", .opt4 = "\0\0\0"};
    if (!map || !champ || !base_vm)
        return KO;
    coding_byte_function(map[champ->champ_param.pc + 1], &coding_byte);
    if (my_strcmp(coding_byte.opt1, "01") != 0 &&
    champ->champ_param.carry == 1) {
        champ->champ_param.pc = champ->info_champ.load_mem;
    }
    champ->champ_param.pc += move_byte(&coding_byte, 1) % MEM_SIZE;
    return OK;
}
