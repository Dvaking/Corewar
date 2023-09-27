/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** move_byte
*/

#include <unistd.h>

#include "macro.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

static int direct(coding_byte_s_t *coding_byte)
{
    int b = 0;
    if (my_strcmp(coding_byte->opt1, "10") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt2, "10") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt3, "10") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt4, "10") == OK)
        b += 1;
    return b;
}

static int indirect(coding_byte_s_t *coding_byte)
{
    int b = 0;
    if (my_strcmp(coding_byte->opt1, "11") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt2, "11") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt3, "11") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt4, "11") == OK)
        b += 1;
    return b;
}

static int regist(coding_byte_s_t *coding_byte)
{
    int b = 0;
    if (my_strcmp(coding_byte->opt1, "01") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt2, "01") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt3, "01") == OK)
        b += 1;
    if (my_strcmp(coding_byte->opt4, "01") == OK)
        b += 1;
    return b;
}

int move_byte(coding_byte_s_t *coding_byte, int index_or_n)
{
    int move = 0;
    int dir = 0;
    int ind = 0;
    int reg = 0;
    if (!coding_byte)
        return KO;
    dir = direct(coding_byte);
    ind = indirect(coding_byte);
    reg = regist(coding_byte);
    if (index_or_n == 1)
        move = (dir * IND_SIZE) + reg + (ind * IND_SIZE) + 2;
    else
        move = (dir * DIR_SIZE) + reg + (ind * IND_SIZE) + 2;
    return move;
}
