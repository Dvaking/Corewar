/*
** EPITECH PROJECT, 2023
** complement
** File description:
** complement
*/

int complement(int num, int bits)
{
    int mask = 1 << (bits - 1);
    int complement = ~(num - 1);
    return complement & (mask - 1);
}
