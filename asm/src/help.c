/*
** EPITECH PROJECT, 2023
** help command and message
** File description:
** help
*/

#include <unistd.h>

#include "asm.h"

int help(void)
{
    if (write(1, "USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in\
assembly language to be converted into file_name.cor, an executable in the \
Virtual Machine.\n", 148) == -1)
        return KO;
    return OK;
}
