/*
** EPITECH PROJECT, 2023
** generate_a_bytecode_file.c
** File description:
** generate_a_bytecode_file
*/

#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "asm.h"

static int count_char_in_str(char *input, char char_to_find)
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i += 1) {
        if (input[i] == char_to_find)
            count += 1;
    }
    return count;
}

int intern_error_handling(char const* arg)
{
    if (arg == NULL)
        return KO;
    FILE *file = fopen(arg, "r+");
    if (file == NULL)
        return KO;
    char *input = NULL;

    input = get_input(file, input);
    while (my_strlen(input) != 1 && input[0] != '\n') {
        if (count_char_in_str(input, '"') != 2)
            return KO;
        input = get_input(file, input);
    }
    fclose(file);
    return OK;
}

static int create_dot_cor_file(char const* arg, int *is_already_cor_file,
char **name_of_the_file)
{
    (*is_already_cor_file) = get_the_extension_of_the_file(arg);
    if ((*is_already_cor_file) == KO)
        return KO;
    if ((*is_already_cor_file) == false)
        (*name_of_the_file) = create_the_name_of_the_new_file(arg);
    else
        return OK;
    return OK;
}

int generate_a_bytecode_file(char const* arg)
{
    if (arg == NULL)
        return KO;
    int fd = open(arg, O_RDONLY);
    char *name_of_the_file = NULL;
    int is_already_cor_file = 0;

    if (fd == -1)
        return KO;
    close(fd);
    if (create_dot_cor_file(arg, &is_already_cor_file, &name_of_the_file) ==
    KO)
        return KO;
    if (intern_error_handling(arg) == KO)
        return KO;
    fd = open(name_of_the_file, O_CREAT | O_WRONLY | O_APPEND, 00777);
    if (fd == -1)
        return KO;
    close(fd);
    free(name_of_the_file);
    return OK;
}
