/*
** EPITECH PROJECT, 2023
** write_header_in_file
** File description:
** write_header_in_file
*/

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "asm.h"

static int free_and_close(header_t *file_infos, char *name_of_the_file,
FILE *fd)
{
    if (file_infos == NULL || name_of_the_file == NULL || fd == NULL)
        return KO;
    free(file_infos);
    free(name_of_the_file);
    fclose(fd);
    return OK;
}

static int fill_struct(header_t *file_infos, int calculated_prog_size)
{
    if (file_infos == NULL)
        return KO;
    file_infos->magic = COREWAR_EXEC_MAGIC;
    file_infos->magic = endian_conversion(file_infos->magic);
    file_infos->prog_size = calculated_prog_size;
    file_infos->prog_size = endian_conversion(file_infos->prog_size);
    return OK;
}

int write_header_in_file(char const* arg, int calculated_prog_size,
char *name_of_the_file)
{
    if (arg == NULL)
        return KO;
    header_t *file_infos = malloc(sizeof(header_t));
    FILE *fd = NULL;
    (*file_infos) = (header_t){0};

    if (file_infos == NULL)
        return KO;
    if (extract_header_from_file(arg, file_infos) == KO)
        return KO;
    if (fill_struct(file_infos, calculated_prog_size) == KO)
        return KO;
    fd = fopen(name_of_the_file, "w+");
    if (fwrite(file_infos, sizeof(header_t), 1, fd) == 0)
        return KO;
    if (free_and_close(file_infos, name_of_the_file, fd) == KO)
        return KO;
    return OK;
}
