/*
** EPITECH PROJECT, 2023
** get_body
** File description:
** get_body
*/
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "asm_structures.h"
#include "asm.h"

char *get_input(FILE *file, char *input)
{
    size_t n = 0;
    int len = 0;
    len = getline(&input, &n, file);
    if (len == -1)
        return NULL;
    input[len] = '\0';
    return input;
}

body_t *get_command(char **body_parsing, body_t *body, char *input)
{
    if (input == NULL || nb_tok(input, " ,\t\n") < 1)
        return body;
    body_parsing = my_strtok(input, " ,\t\n");
    if (body_parsing == NULL || body_parsing[0][0] == '#')
        return body;
    if (is_in_str(':', body_parsing[0]) == 1 &&
        is_in_str('%', body_parsing[0]) == 0) {
        free(body_parsing[0]);
        body_parsing = &body_parsing[1];
    }
    body = add_at_end(&body_parsing[1], body_parsing[0], body);
    return body;
}

body_t *get_body(char const *pathname)
{
    if (pathname == NULL)
        return NULL;
    FILE *file = fopen(pathname, "r+");
    if (file == NULL)
        return NULL;
    char *input = NULL;
    char **body_parsing = NULL;
    body_t *body = NULL;
    input = get_input(file, input);
    while (input != NULL) {
        while (is_in_str('"', input) >= 1)
            input = get_input(file, input);
        body = get_command(body_parsing, body, input);
        input = get_input(file, input);
    }
    fclose(file);
    return body;
}
