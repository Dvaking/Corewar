/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** free
*/

#include <unistd.h>
#include <stdlib.h>

#include "macro.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int free_struct(base_vm_s_t *base_vm)
{
    if (!base_vm)
        return KO;
    if (base_vm->champ != NULL)
        base_vm->champ = free_list(base_vm->champ);
    free(base_vm);
    return OK;
}

int free_all(int *map, base_vm_s_t *base_vm)
{
    if (!base_vm || !map)
        return KO;
    free_struct(base_vm);
    free(map);
    return OK;
}
