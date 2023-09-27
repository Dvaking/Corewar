/*
** EPITECH PROJECT, 2023
** my_scripts
** File description:
** main
*/

#include "asm.h"
#include "asm_structures.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char const* const* argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help();
    if (argc != 2 || argv[1] == NULL)
        return KO;
    return asm_launcher(argv[1]);
}
