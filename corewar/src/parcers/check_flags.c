/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** flags
*/

#include <unistd.h>
#include <stdio.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

const struct function OPERATOR_FUNCS[] = {
    {"-a", &check_flag_a},
    {"-n", &check_flag_n},
    {"-dump", &check_flag_dump},
    {"NULL", NULL}
};

int move_to_end(list_t **list_tmp)
{
    if (!*list_tmp)
        return KO;
    while ((*list_tmp)->next != NULL){
        (*list_tmp) = (*list_tmp)->next;
    }
    return OK;
}

int check_flags_and_create_champ(char const *const *av, base_vm_s_t *base_vm,
need_parcers_s_t *need_parcers, int *i)
{
    if (!av || !base_vm)
        return KO;
    for (int y = 0; my_strcmp("NULL", OPERATOR_FUNCS[y].str) != OK; y ++){
        if (my_strcmp(av[*i], OPERATOR_FUNCS[y].str) == OK){
            *i += 1;
            return OPERATOR_FUNCS[y].proto(base_vm, need_parcers, av, i);
        }
    }
    if (create_champ(base_vm, av, i, need_parcers) != OK)
        return KO;
    return OK;
}
