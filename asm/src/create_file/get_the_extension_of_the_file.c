/*
** EPITECH PROJECT, 2023
** get_the_extension_of_the_file.c
** File description:
** get_the_extension_of_the_file
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "asm.h"

static int take_the_extension(char const *arg, char **extension,
int *extension_counter, int start)
{
    if (arg == NULL || extension_counter == NULL || (*extension) == NULL)
        return KO;
    for (int i = start; arg[i] != '.' && arg[i] != '\0'; i -= 1) {
        if ((*extension_counter) > 2)
            return false;
        (*extension)[(*extension_counter)] = arg[i];
        (*extension_counter) += 1;
    }
    if ((*extension_counter) == 1)
        return false;
    return true;
}

static int verify_is_extension_a_dot_cor(char *extension)
{
    if (extension == NULL)
        return KO;
    if (my_strcmp(extension, "cor") == 0) {
        free(extension);
        return true;
    } else {
        free(extension);
        return false;
    }
}

static int verify_extension(char const *arg, char *extension,
int extension_counter, int start)
{
    if (arg == NULL || extension == NULL)
        return KO;
    int the_extension = take_the_extension(arg, &extension,
    &extension_counter, start);

    if (the_extension == false) {
        free(extension);
        return false;
    }
    if (the_extension == KO) {
        free(extension);
        return KO;
    }
    my_revstr(extension);
    return verify_is_extension_a_dot_cor(extension);
}

int get_the_extension_of_the_file(char const* arg)
{
    if (arg == NULL)
        return KO;
    int start = (my_strlen(arg) - 1);
    char *extension = malloc(sizeof(char) * 4);
    extension[3] = '\0';
    int extension_counter = 0;

    return verify_extension(arg, extension, extension_counter, start);
}
