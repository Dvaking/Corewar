/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** live_command
*/

#include <unistd.h>

#include "macro.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int live_command(base_vm_s_t *base_vm, list_t *champ, int *map)
{
    if (!map || !champ || !base_vm)
        return KO;
    my_putstr("The player ");
    my_put_nbr(champ->info_champ.nbr_prog);
    my_putstr("(");
    my_putstr(champ->header.prog_name);
    my_putstr(")is alive.\n");
    base_vm->game_info.nbr_live += 1;
    champ->info_champ.cycle_to_die = base_vm->game_info.len_cycle_to_die;
    champ->champ_param.pc += 5;
    return OK;
}
