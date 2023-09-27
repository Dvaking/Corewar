/*
** EPITECH PROJECT, 2023
** launch_asm.c
** File description:
** launch_asm
*/

#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#include "asm.h"

int asm_launcher(char const *arg)
{
    if (arg == NULL)
        return KO;
    int file_creation = generate_a_bytecode_file(arg);
    if (file_creation == KO)
        return KO;
    char *name_of_the_file = create_the_name_of_the_new_file(arg);
    if (convert_body(name_of_the_file, arg) == KO)
        return KO;
    return OK;
}
