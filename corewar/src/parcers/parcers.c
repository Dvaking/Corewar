/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** create_champ
*/

#include <unistd.h>
#include <stdio.h>


#include "macro.h"
#include "corewar.h"
#include "linked_list.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

static int condition(base_vm_s_t *base_vm, char const *const *av,
need_parcers_s_t *need_parcers, int *i)
{
    if (!need_parcers || !base_vm)
        return KO;
    if (need_parcers->new_champ == 1){
        base_vm->champ = add_node_in_list(base_vm->champ);
        need_parcers->new_champ = 0;
        need_parcers->last_flag = 0;
        need_parcers->champ_create = 0;
    }
    if (check_flags_and_create_champ(av, base_vm, need_parcers, i) != OK)
        return KO;
    return OK;
}

int parcers(base_vm_s_t *base_vm, char const *const *av)
{
    int len_list = 0;
    need_parcers_s_t need_parcers = {.new_champ = 1, .id_champ = -1,
    .last_flag = 0, .champ_create = 0};
    if (!av || !base_vm)
        return KO;
    base_vm->game_info.dump = -1;
    base_vm->champ = NULL;
    for (int i = 1; av[i] != NULL; i ++){
        if (condition(base_vm, av, &need_parcers, &i) != OK)
            return KO;
    }
    if (need_parcers.champ_create != 1)
        return KO;
    if ((len_list = my_list_len(base_vm->champ)) == KO)
        return KO;
    if (len_list < 2 || len_list > 4)
        return KO;
    base_vm->game_info.champ_live = len_list;
    return OK;
}
