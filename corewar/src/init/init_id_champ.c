/*
** EPITECH PROJECT, 2023
** init_id_champ
** File description:
** init the id of all the champions
*/

#include "op.h"
#include "macro.h"
#include "linked_list.h"
#include "corewar.h"

#include <stdlib.h>
#include <stdio.h>

list_t *set_champion_id(list_t *current, list_t *champ_list)
{
    for (int i = 1; i <= MAX_ARGS_NUMBER; i++) {
        if (check_already_exit(champ_list, i, 0) == OK) {
            current->info_champ.nbr_prog = i;
            break;
        }
    }
    return current;
}

list_t *init_id_champ(list_t *champ_list)
{
    list_t *current = champ_list;

    for (; current != NULL; current = current->next) {
        if (current->info_champ.nbr_prog == -1)
            current = set_champion_id(current, champ_list);
    }
    return champ_list;
}
