/*
** EPITECH PROJECT, 2023
** remove_bottom
** File description:
** Remove the last cell of a chained_list
*/
#include "asm_structures.h"
#include "asm.h"
#include <stddef.h>
#include <stdlib.h>

body_t *remove_body_top(body_t *head)
{
    if (head == NULL)
        return NULL;
    free(head->command);
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    body_t *new_head = head->next;
    free(head);
    return new_head;
}

body_t *remove_bottom(body_t *list)
{
    body_t *current = list;
    while (current->next != NULL)
        current = current->next;
    if (current->previous == NULL) {
        free(list);
        return NULL;
    }
    current = current->previous;
    free(current->next->command);
    free(current->next->next);
    free_tab(current->next->args);
    current->next = NULL;
    return (current);
}
