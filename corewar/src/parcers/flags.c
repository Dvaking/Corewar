/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** flags
*/

#include <unistd.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

static int check_already_exit_sub(list_t *list_tmp, int value, int nbr_or_place)
{
    if (!list_tmp)
        return KO;
    if (nbr_or_place == 0){
        if (list_tmp->info_champ.nbr_prog == value)
            return KO;
    }
    if (nbr_or_place == 1){
        if (list_tmp->info_champ.load_mem == value)
            return KO;
    }
    return OK;
}

int check_already_exit(list_t *list, int value, int nbr_or_place)
{
    list_t *list_tmp = list;
    if (!list || !list_tmp)
        return OK;

    for (; list_tmp != NULL; list_tmp = list_tmp->next){
        if (check_already_exit_sub(list_tmp, value, nbr_or_place) != OK)
            return KO;
    }
    return OK;
}

int check_flag_a(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,
char const *const *av, int *i)
{
    int load_memory = 0;
    list_t *list_tmp = base_vm->champ;
    if (!av || !base_vm || !list_tmp)
        return KO;
    if (move_to_end(&list_tmp) != OK)
        return KO;
    if (need_parcers->last_flag != 0 && need_parcers->last_flag != 'n')
        return KO;
    if (av[*i] == NULL || my_str_isnum(av[*i]) != OK)
        return KO;
    if ((load_memory = char_to_int(av[*i])) == KO)
        return KO;
    if (check_already_exit(list_tmp, load_memory, 1) != OK)
        return KO;
    list_tmp->info_champ.load_mem = load_memory;
    need_parcers->last_flag = 'a';
    return OK;
}

int check_flag_n(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,
char const *const *av, int *i)
{
    int nbr_prog = 0;
    list_t *list_tmp = base_vm->champ;
    if (!av || !base_vm || !list_tmp)
        return KO;
    if (move_to_end(&list_tmp) != OK)
        return KO;
    if (need_parcers->last_flag != 0)
        return KO;
    if (av[*i] == NULL || my_str_isnum(av[*i]) != OK)
        return KO;
    if ((nbr_prog = char_to_int(av[*i])) == KO)
        return KO;
    if (nbr_prog < 1 || nbr_prog > 4)
        return KO;
    if (check_already_exit(base_vm->champ, nbr_prog, 0) != OK)
        return KO;
    list_tmp->info_champ.nbr_prog = nbr_prog;
    need_parcers->last_flag = 'n';
    return OK;
}

int check_flag_dump(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,
char const *const *av, int *i)
{
    int dump = 0;
    if (!av || !base_vm || *i - 1 != 1 || need_parcers->last_flag != 0)
        return KO;
    if (av[*i] == NULL || my_str_isnum(av[*i]) != OK)
        return KO;
    if ((dump = char_to_int(av[*i])) == KO)
        return KO;
    base_vm->game_info.dump = dump;
    return OK;
}
