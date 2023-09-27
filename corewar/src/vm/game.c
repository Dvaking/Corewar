/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** game
*/

#include <unistd.h>
#include <stdio.h>

#include "macro.h"
#include "corewar.h"
#include "linked_list.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"
#include "corewar.h"

static int initialisation_value_list(base_vm_s_t *base_vm)
{
    list_t *list_tmp = base_vm->champ;
    if (!base_vm)
        return KO;
    if (REG_NUMBER < 9)
        return KO;
    base_vm->game_info.len_cycle_to_die = CYCLE_TO_DIE;
    base_vm->game_info.nbr_live = 0;
    for (; list_tmp != NULL; list_tmp = list_tmp->next){
        list_tmp->champ_param.pc = list_tmp->info_champ.load_mem;
        list_tmp->champ_param.regist[0] = list_tmp->info_champ.nbr_prog;
        for (int i = 1; i < REG_NUMBER; i ++)
            list_tmp->champ_param.regist[i] = 0;
    }
    return OK;
}

static list_t *find_champ(list_t *champ, int id)
{
    if (!champ)
        return NULL;
    for (list_t *current = champ; current != NULL; current = current->next){
        if (current->info_champ.nbr_prog == id)
            return current;
    }
    return NULL;
}

static int condition_pass_champion(list_t *champ, int *map)
{
    if (!champ || !map)
        return KO;
    if (champ->info_champ.is_alive != true)
        return KO;
    champ->info_champ.cycle_to_die -= 1;
    if (champ->champ_param.time_off > 0){
        champ->champ_param.time_off -= 1;
        return KO;
    }
    for (list_t *list_tmp = champ; list_tmp != NULL; list_tmp = list_tmp->next){
        if ((list_tmp->champ_param.pc - list_tmp->info_champ.load_mem)
        > list_tmp->header.prog_size){
            return KO;
        }
    }
    return OK;
}

static int game_sub(base_vm_s_t *base_vm, int *map)
{
    list_t * champ = NULL;
    if (!base_vm || !map)
        return KO;
    for (int i = 1; i < 4; i ++){
        if ((champ = find_champ(base_vm->champ, i)) == NULL)
            continue;
        if (champ->champ_param.time_off > 0){
            champ->champ_param.time_off -= 1;
            continue;
        }
        if (condition_pass_champion(champ, map) != OK)
            continue;
        if (execution_command(base_vm, champ, map) != OK)
            return KO;
    }
    return OK;
}

int game(base_vm_s_t *base_vm, int *map)
{
    if (!base_vm || !map)
        return KO;
    if (initialisation_value_list(base_vm) != OK)
        return KO;
    while (base_vm->game_info.champ_live > 1){
        update_cycle_to_die(base_vm, map);
        if (game_sub(base_vm, map) != OK)
            return KO;
    }
    win_case(base_vm);
    return OK;
}
