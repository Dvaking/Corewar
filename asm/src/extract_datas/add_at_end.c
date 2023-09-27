/*
** EPITECH PROJECT, 2023
** add_at_end
** File description:
** add node at the edn of the chained list
*/
#include "asm_structures.h"
#include <stddef.h>
#include <stdlib.h>

body_t *add_at_end(char **args, char *command, body_t *list)
{
    body_t *element = malloc(sizeof(body_t));
    element->args = args;
    element->command = command;
    element->next = NULL;
    element->previous = NULL;
    if (list == NULL) {
        list = element;
        return list;
    }
    body_t *current = list;
    while (current->next != NULL)
        current = current->next;
    element->previous = current;
    current->next = element;
    return list;
}
