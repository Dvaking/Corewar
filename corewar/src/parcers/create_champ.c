/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** create_champ
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

static int take_header_data(list_t *list_tmp, char const *filename,
need_parcers_s_t *need_parcers, int *file)
{
    int nread = 0;
    if (!list_tmp || !filename || !need_parcers)
        return KO;
    if ((*file = open(filename, O_RDONLY)) == KO){
        if (write(2, "Failed to open\n", 16) == -1)
            return KO;
        return KO;
    }
    nread = read(*file, &(list_tmp->header), sizeof(header_t));
    if (nread < (int)(sizeof(header_t))){
        close(*file);
        return KO;
    }
    list_tmp->header.magic = transform_big_to_little(list_tmp->header.magic);
    list_tmp->header.prog_size =
    transform_big_to_little(list_tmp->header.prog_size);
    return OK;
}

static int check_good_size(int *file, int nread, int size)
{
    char buf[size];
    nread = read(*file, &buf, size);
    if (nread > 0){
        if (write(2, "Error in the size of the champion's body.\n", 43) == KO)
            return KO;
        return KO;
    }
    return OK;
}

static int take_body_data(list_t *list_tmp, char const *filename, int *file)
{
    int nread = 0;
    if (!list_tmp || !filename)
        return KO;
    list_tmp->info_champ.prog_body =
    malloc(sizeof(char) * list_tmp->header.prog_size);
    nread = read(*file, list_tmp->info_champ.prog_body,\
    list_tmp->header.prog_size);
    if (nread < list_tmp->header.prog_size){
        close(*file);
        return KO;
    }
    if (check_good_size(file, nread, list_tmp->header.prog_size) != OK)
        return KO;
    return 0;
}

int create_champ(base_vm_s_t *base_vm, char const *const *av, int *i,
need_parcers_s_t *need_parcers)
{
    list_t *list_tmp = base_vm->champ;
    int file = 0;
    if (!av || !base_vm || !list_tmp)
        return KO;
    if (move_to_end(&list_tmp) != OK)
        return KO;
    if (take_header_data(list_tmp, av[*i], need_parcers, &file) != OK)
        return KO;
    if (list_tmp->header.prog_size > MEM_SIZE)
        return KO;
    if (list_tmp->header.magic != COREWAR_EXEC_MAGIC)
        return KO;
    if (take_body_data(list_tmp, av[*i], &file) != OK)
        return KO;
    need_parcers->new_champ = 1;
    need_parcers->champ_create = 1;
    close(file);
    return OK;
}
