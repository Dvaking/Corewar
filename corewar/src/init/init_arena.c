/*
** EPITECH PROJECT, 2023
** init_arena
** File description:
** init the arena
*/

#include "corewar.h"
#include "macro.h"
#include <stdlib.h>
#include <stdio.h>

static int *print_body_in_map_loaded(int i, list_t *champ_list, int *map)
{
    if (champ_list->info_champ.prog_body[i] < 0)
        map[(i + champ_list->info_champ.load_mem) % MEM_SIZE] =
        (int)champ_list->info_champ.prog_body[i] + 256;
    else
        map[(i + champ_list->info_champ.load_mem) % MEM_SIZE] =
        champ_list->info_champ.prog_body[i];

    return map;
}

static int *print_body_in_map_unloaded(list_t *champ_list, int *map)
{
    for (int i = 0; i < champ_list->header.prog_size; i++) {
        map = print_body_in_map_loaded(i, champ_list, map);
    }
    return map;
}

static int *find_best_place(int *map, list_t *champ_list)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        int j = get_len_empty(map, i);
        if (j > champ_list->header.prog_size) {
            champ_list->info_champ.load_mem = i;
            map = print_body_in_map_unloaded(champ_list, map);
            return map;
        }
    }
    return map;
}

static int *set_body_in_map(list_t *champ_list, int *map)
{
    for (int i = 0; i < champ_list->header.prog_size; i++) {
        if (map[(i + champ_list->info_champ.load_mem) % MEM_SIZE] != -1)
            return NULL;
        map = print_body_in_map_loaded(i, champ_list, map);
    }
    return map;
}

int *init_map(base_vm_s_t *base_vm)
{
    int *map = malloc(sizeof(int) * MEM_SIZE);
    list_t *tmp = base_vm->champ;
    base_vm->champ = init_id_champ(base_vm->champ);
    for (int i = 0; i < MEM_SIZE; i++) {
        map[i] = -1;
    }
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->info_champ.load_mem == -1)
            continue;
        if ((map = set_body_in_map(tmp, map)) == NULL)
            return NULL;
    }
    for (tmp = base_vm->champ; tmp != NULL; tmp = tmp->next) {
        if (tmp->info_champ.load_mem != -1) {
            continue;
        }
        map = find_best_place(map, tmp);
    }
    return map;
}
