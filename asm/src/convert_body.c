/*
** EPITECH PROJECT, 2023
** convert_body
** File description:
** convert_body
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "asm_structures.h"

int need_coding_byte(int command)
{
    if (command == 1 || command == 9 ||
        command == 12 || command == 16 )
        return 0;
    return 1;
}

int need_cap(int command)
{
    if (command == 9 || command == 10 ||
        command == 11 || command == 12)
        return 1;
    return 0;
}

static int coding_byte_writer(int command, body_t *body, FILE *file)
{
    int coding_byte = get_coding_byte(body->args);
    if (need_coding_byte(command) == 1) {
        fwrite(&coding_byte, 1, 1, file);
        if (fseek(file, 0, SEEK_END) == -1)
            return KO;
    }
    return OK;
}

static int write_body(FILE *file, body_t *body)
{
    for (int i = 0; body != NULL; i++) {
        int command = get_function_code(body->command);
        fwrite(&command, 1, 1, file);
        if (fseek(file, 0, SEEK_END) == -1)
            return 84;
        if (coding_byte_writer(command, body, file) == 84)
            return 84;
        get_arg_bytes(body->args, need_cap(command), file);
        if (fseek(file, 0, SEEK_END) == -1)
            return 84;
        for (int i = 0; body->args[i] != NULL; i++)
            free(body->args[i]);
        body = remove_body_top(body);
    }
    return 0;
}

int convert_body(char *filename, char const* arg)
{
    if (filename == NULL || arg == NULL)
        return 84;
    body_t *body = get_body(arg);
    int command = get_function_code(body->command);

    int nb_bytes_calculated = get_nb_bytes(body, command) / 2;
    if (body == NULL)
        return 84;
    FILE *file = fopen(filename, "a+");
    if (file == NULL)
        return 84;
    if (write_header_in_file(arg, nb_bytes_calculated, filename) == KO)
        return KO;
    int res = write_body(file, body);
    fclose(file);
    return res;
}
