/*
** EPITECH PROJECT, 2023
** extract_header_from_file
** File description:
** extract_header_from_file
*/
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "asm_structures.h"
#include "asm.h"

static void get_header(char **header_parsing, header_t *header)
{
    if (header_parsing == NULL || header_parsing[0] == NULL)
        return;
    if (my_strcmp(header_parsing[0], ".name") == 0)
        my_strcpy(header->prog_name, header_parsing[1]);
    else if (my_strcmp(header_parsing[0], ".comment") == 0)
        my_strcpy(header->comment, header_parsing[1]);
}

char **get_title(char **header_parsing, char *input)
{
    header_parsing = my_strtok(input, "\"");
    char **title = my_strtok(header_parsing[0], " \t\n");
    header_parsing[0] = my_strcpy(header_parsing[0], title[0]);
    free_tab(title);
    return header_parsing;
}

int extract_header_from_file(char const* pathname, header_t *file_infos)
{
    if (pathname == NULL || file_infos == NULL)
        return KO;
    FILE *file = fopen(pathname, "r+");
    if (file == NULL)
        return KO;
    char *input = NULL;
    size_t n = 0;
    int len = getline(&input, &n, file);
    char **header_parsing = NULL;
    while (len != -1) {
        input[len] = '\0';
        if (is_in_str('"', input) == 1)
            header_parsing = get_title(header_parsing, input);
        get_header(header_parsing, file_infos);
        len = getline(&input, &n, file);
    }
    fclose(file);
    free(input);
    free_tab(header_parsing);
    return OK;
}
