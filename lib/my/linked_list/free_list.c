/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-lemin-marc.mendia
** File description:
** free_list
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

list_t *free_list(list_t *list)
{
    list_t *current = list;
    list_t *next = NULL;

    if (!current || !list)
        return NULL;
    while (current != NULL) {
        next = current->next;
        if (current->info_champ.prog_body != NULL){
            free(current->info_champ.prog_body);
        }
        if (current != NULL)
            free(current);
        current = next;
    }
    return current;
}
