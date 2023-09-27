/*
** EPITECH PROJECT, 2023
** create_the_name_of_the_new_file
** File description:
** create_the_name_of_the_new_file
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "asm.h"

static int is_a_point_in_filename(char const* arg, int *start)
{
    for (int i = (*start); arg[i] != '/' && i >= 0; i -= 1) {
        if (arg[i] == '.')
            return true;
    }
    return false;
}

static int count_char_until_point_or_end(int *start, char const* arg,
bool *name_without_extension, int *count)
{
    (*start) = (my_strlen(arg) - 1);
    int is_there_a_point_in_filename = is_a_point_in_filename(arg, start);

    for ((*start) = (my_strlen(arg) - 1); arg[(*start)] != '/' &&
    (*start) >= 0; (*start) -= 1) {
        if (arg[(*start)] == '.' || is_there_a_point_in_filename == false)
            (*name_without_extension) = true;
        if ((arg[(*start)] != '.' && arg[(*start)] != '\0') &&
        (*name_without_extension) == true) {
            (*count) += 1;
        }
    }
    return OK;
}

char *create_the_name_of_the_new_file(char const* arg)
{
    int start = 0;
    int count = 0;
    int new_str_index = 0;
    bool name_without_extension = false;
    char *new_str = NULL;

    count_char_until_point_or_end(&start, arg, &name_without_extension,
    &count);
    new_str = malloc(sizeof(char) * (count + 5));
    new_str[count] = '\0';
    for (int i = start + 1; arg[i] != '.' && arg[i] != '\0'; i += 1) {
        new_str[new_str_index] = arg[i];
        new_str_index += 1;
    }
    my_strcat(new_str, ".cor");
    return new_str;
}
