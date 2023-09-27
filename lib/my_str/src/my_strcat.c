/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/

#include <stddef.h>

int my_strcat(char *dest, char const *src)
{
    if (dest == NULL || src == NULL)
        return -1;
    int count = 0;
    while (dest[count] != '\0') {
        count += 1;
    }
    for (int i = 0; src[i] != '\0'; i += 1) {
        dest[count] = src[i];
        count += 1;
    }
    dest[count] = '\0';
    return 0;
}
