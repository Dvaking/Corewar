/*
** EPITECH PROJECT, 2023
** endian conversion
** File description:
** endian_conversion
*/

int endian_conversion(int nb_to_convert)
{
    int new_converted_value = 0;
    new_converted_value |= ((0xff & nb_to_convert) << 24);
    new_converted_value |= (((0xff << 8) & nb_to_convert) << 8);
    new_converted_value |= (((0xff << 16) & nb_to_convert) >> 8);
    new_converted_value |= (((0xff << 24) & nb_to_convert) >> 24);
    return new_converted_value;
}
