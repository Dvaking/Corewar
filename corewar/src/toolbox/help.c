/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** help
*/

#include <unistd.h>

#include "macro.h"
#include "proto_lib_my.h"

static int print_help(char const *const *av)
{
    if (!av)
        return KO;
    if (write(1, "USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps the \
memory after the nbr_cycle execution (if the round isn\'t\nalready over) with \
the following format: 32 bytes/line\nin hexadecimal (A0BCDEFE1DD3...)\n-n \
prog_number sets the next program\'s number. By default, the first free number\
\nin the parameter order\n-a load_address sets the next program\'s loading \
address. When no address is\nspecified, optimize the addresses so that the \
processes are as far\naway from each other as possible. The addresses are \
MEM_SIZE modulo.\n", 585) == KO)
        return KO;
    return OK;
}

int help(int ac, char const *const *av)
{
    if (!av)
        return KO;
    if (ac == 2){
        if (print_help(av) != OK)
            return KO;
    }
    return OK;
}
