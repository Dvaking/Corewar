/*
** EPITECH PROJECT, 2023
** create_node
** File description:
** create_node
*/

#include <unistd.h>
#include <stdlib.h>


#include "proto_lib_my.h"
#include "linked_list.h"

list_t *create_node(void)
{
    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;
    new_node->next = NULL;
    new_node->previous = NULL;
    new_node->info_champ.nbr_prog = -1;
    new_node->info_champ.load_mem = -1;
    new_node->info_champ.cycle_to_die = CYCLE_TO_DIE;
    new_node->info_champ.prog_body = NULL;
    new_node->champ_param.time_off = 0;
    new_node->champ_param.carry = 0;
    new_node->champ_param.command = -1;
    new_node->info_champ.is_alive = true;
    return new_node;
}
