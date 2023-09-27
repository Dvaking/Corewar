/*
** EPITECH PROJECT, 2023
** transform big to little
** File description:
** transform a big endian into little endian
*/

int transform_big_to_little(int value)
{
    int new_value = 0;

    new_value |= (value & 0xFF000000) >> 24;
    new_value |= (value & 0x00FF0000) >> 8;
    new_value |= (value & 0x0000FF00) << 8;
    new_value |= (value & 0x000000FF) << 24;

    return new_value;
}
