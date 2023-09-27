/*
** EPITECH PROJECT, 2023
** Core_War
** File description:
** coding_byte
*/

#include <unistd.h>
#include <stdio.h>

#include "macro.h"
#include "corewar.h"
#include "linked_list.h"
#include "struct_corewar.h"

int coding_byte_function(int decimal, coding_byte_s_t *coding_byte)
{
    if (decimal > 255 || decimal < 0 || !coding_byte)
        return -1;
    coding_byte->opt4[1] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt4[0] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt3[1] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt3[0] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt2[1] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt2[0] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt1[1] = ((decimal % 2) + '0');
    decimal /= 2;
    coding_byte->opt1[0] = ((decimal % 2) + '0');
    return 0;
}
