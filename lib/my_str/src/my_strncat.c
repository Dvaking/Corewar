/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    while (dest[i] != '\0'){
        i += 1;
    }
    int j = 0;
    while (src[j] != '\0' && j < nb){
        dest[i] = src[j];
        j += 1;
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
