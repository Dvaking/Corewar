/*
** EPITECH PROJECT, 2023
** virtual_machine
** File description:
** the virtual machine begin here
*/

#include "op.h"
#include "macro.h"
#include "corewar.h"
#include "struct_corewar.h"
#include <stdio.h>
#include <stdlib.h>

int virtual_machine(char const *const *av)
{
    int *map = 0;
    base_vm_s_t *base_vm = malloc(sizeof(base_vm_s_t));
    if (!base_vm || !av)
        return 84;
    if (parcers(base_vm, av) != OK) {
        free(base_vm);
        return 84;
    }
    if ((map = init_map(base_vm)) == NULL) {
        free_struct(base_vm);
        return 84;
    }
    if (game(base_vm, map) != OK) {
        free_all(map, base_vm);
        return 84;
    }
    free_all(map, base_vm);
    return OK;
}
