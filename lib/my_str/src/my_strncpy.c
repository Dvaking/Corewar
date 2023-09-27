/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** function that copies n characters from a string into another
*/

int my_strlen(char const * str);

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i += 1){
        dest[i] = src[i];
    }
    return dest;
}
