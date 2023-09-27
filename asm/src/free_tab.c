/*
** EPITECH PROJECT, 2023
** free_tab
** File description:
** free_tab
*/

#include <stddef.h>
#include <stdlib.h>

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
    return;
}
