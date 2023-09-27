/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** char_to_int
*/

#include "proto_lib_my.h"

int char_to_int(char const *str)
{
    long int nbr = 0;
    int sign = 1;
    int i = 0;
    if (!str)
        return -1;
    if (str[0] == '-'){
        sign = -1;
        i ++;
    }
    for (; str[i] != '\0'; i += 1){
        if (str[i] < '0' || str[i] > '9'){
            return -1;
        }
        nbr = (nbr * 10) + (str[i] - '0');
    }
    nbr *= sign;
    if (nbr > 2147483647 || nbr < -2147483648)
        return -1;
    i = (int)(nbr);
    return i;
}
