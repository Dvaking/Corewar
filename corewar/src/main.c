/*
** EPITECH PROJECT, 2023
** my_scripts
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>

#include "macro.h"
#include "corewar.h"
#include "struct_corewar.h"
#include "proto_lib_my.h"

int main(int ac, char const* const* av)
{
    if (ac < 2)
        return 84;
    if (my_strcmp("-h", av[1]) == OK){
        if (help(ac, av) != OK)
            return 84;
        return OK;
    }
    return virtual_machine(av);
}
