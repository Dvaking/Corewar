/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-marc.mendia
** File description:
** add_node
*/

#include <unistd.h>
#include "proto_lib_my.h"
#include "linked_list.h"

list_t *add_node_in_list(list_t *list)
{
    list_t *node = create_node();
    list_t *list_tmp = list;
    if (list_tmp == NULL)
        return node;
    while (list_tmp->next != NULL)
        list_tmp = list_tmp->next;
    list_tmp->next = node;
    return list;
}
