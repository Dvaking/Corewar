/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** tab_genetor
*/

#include <unistd.h>
#include <stdlib.h>

char **tab_generator(int y, int x)
{
    char **tab = malloc(sizeof(char *) * y + 1);
    if (tab == NULL)
        return NULL;
    tab[y] = NULL;
    for (int i = 0; tab[i] != NULL; i += 1){
        tab[i] = malloc(sizeof(char) * x + 1);
        if (tab[i] == NULL)
            return NULL;
        tab[i][x] = '\0';
    }
    return tab;
}
