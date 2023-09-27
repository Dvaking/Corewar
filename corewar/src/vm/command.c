/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** command
*/

#include <unistd.h>
#include <stdio.h>

#include "macro.h"
#include "corewar.h"
#include "linked_list.h"
#include "struct_corewar.h"

const struct command_function OPERATOR_FUNCTION[] = {
    {1, &live_command},
    {2, &ld_command},
    {3, &st_command},
    {4, &add_command},
    {5, &sub_command},
    {6, &and_command},
    {7, &or_command},
    {8, &xor_command},
    {9, &zjmp_command},
    {10, &ldi_command},
    {11, &sti_command},
    {12, &fork_command},
    {13, &lld_command},
    {14, &lldi_command},
    {15, &lfork_command},
    {16, &aff_command},
    {-1, NULL},
};

static int read_command(list_t *champ, int *map)
{
    int command_instruction = 0;
    if (!champ || !map)
        return KO;
    command_instruction = map[champ->champ_param.pc];
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (command_instruction == op_tab[i].code) {
            champ->champ_param.time_off = op_tab[i].nbr_cycles;
            champ->champ_param.command = op_tab[i].code;
            return OK;
        }
    }
    champ->champ_param.pc ++;
    return OK;
}

int execution_command(base_vm_s_t *base_vm, list_t *champ, int *map)
{
    if (champ->champ_param.command == -1){
        if (read_command(champ, map) != OK)
            return KO;
        return OK;
    }
    for (int i = 0; OPERATOR_FUNCTION[i].command != -1; i ++){
        if (OPERATOR_FUNCTION[i].command == champ->champ_param.command){
            champ->champ_param.command = -1;
            return OPERATOR_FUNCTION[i].proto(base_vm, champ, map);
        }
    }
    return OK;
}
