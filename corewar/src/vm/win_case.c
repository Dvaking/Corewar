/*
** EPITECH PROJECT, 2023
** win case
** File description:
** check the case if someone win
*/

#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

#include <unistd.h>

int win_case(base_vm_s_t *base_vm)
{
    list_t *current = base_vm->champ;

    for (; current != NULL; current = current->next) {
        if (current->info_champ.is_alive == true) {
            my_putstr("The player ");
            my_put_nbr(current->info_champ.nbr_prog);
            my_putstr("(");
            my_putstr(current->header.prog_name);
            my_putstr(")has won.\n");
            break;
        }
    }
    return 0;
}
