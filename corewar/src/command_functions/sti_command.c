/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** sti_command
*/

#include <unistd.h>

#include "macro.h"
#include "corewar.h"
#include "proto_lib_my.h"
#include "struct_corewar.h"

int take_register_pos(int decimal)
{
    char register_pos[3] = "\0\0\0";
    register_pos[1] = ((decimal % 16) + '0');
    decimal /= 16;
    register_pos[0] = ((decimal % 16) + '0');
    return char_to_int(register_pos) - 1;
}

static int take_index_move(int decimal, int decimal_two)
{
    char decimal_one[3] = "\0\0\0";
    char decimal_tw[3] = "\0\0\0";
    int move = 0;
    int decimal_1 = 0;
    int decimal_2 = 0;
    decimal_one[1] = ((decimal % 16) + '0');
    decimal /= 16;
    decimal_one[0] = ((decimal % 16) + '0');
    decimal_tw[1] = ((decimal_two % 16) + '0');
    decimal_two /= 16;
    decimal_tw[0] = ((decimal_two % 16) + '0');
    if ((decimal_1 = char_to_int(decimal_one)) == KO)
        return KO;
    if ((decimal_2 = char_to_int(decimal_tw)) == KO)
        return KO;
    move = ((decimal_1 * (16)) + decimal_2);
    if (move < 0)
        return KO;
    return move;
}

static int how_byte_move(coding_byte_s_t *coding_byte, list_t *champ,
int *map, int pos)
{
    int move = pos;
    int register_move = 0;
    if (!champ || !map || !coding_byte)
        return KO;
    if (my_strcmp(coding_byte->opt2, "01") != OK)
        move += take_index_move(map[pos + 3], map[pos + 4]);
    else {
        register_move = take_index_move(map[pos + 3], map[pos + 4]);
        move += champ->champ_param.regist[register_move];
    }
    if (my_strcmp(coding_byte->opt3, "01") != OK)
        move += take_index_move(map[pos + 5], map[pos + 6]);
    else {
        register_move = take_index_move(map[pos + 5], map[pos + 6]);
        move += champ->champ_param.regist[register_move];
    }
    return move;
}

static int make_sti(coding_byte_s_t *coding_byte, list_t *champ, int *map,
int pos)
{
    int register_pos = 0;
    int move = 0;
    if (!champ || !map || !coding_byte)
        return KO;
    if ((register_pos = take_register_pos(map[pos + 2])) == KO)
        return KO;
    if ((move = how_byte_move(coding_byte, champ, map, pos)) == KO)
        return KO;
    if (replace_value(champ, map, move, register_pos) != OK)
        return KO;
    return OK;
}

int sti_command(base_vm_s_t *base_vm, list_t *champ, int *map)
{
    coding_byte_s_t coding_byte = {.opt1 = "", .opt2 = "\0\0\0",
    .opt3 = "\0\0\0", .opt4 = "\0\0\0"};
    if (!map || !champ || !base_vm)
        return KO;
    coding_byte_function(map[champ->champ_param.pc + 1], &coding_byte);
    if (make_sti(&coding_byte, champ, map, champ->champ_param.pc) != OK)
        return KO;
    champ->champ_param.pc += move_byte(&coding_byte, 1) % MEM_SIZE;
    return OK;
}
