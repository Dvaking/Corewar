/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** function finds the first occurrence of the substring
*/

#include <stddef.h>

int my_strlen(char *str);
int my_strncmp(char const *s1,char const *s2, int n);



static int my_strlen_const (char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i += 1;
    }
    return i;
}

char *my_strstr(char *str, char const *to_find)
{
    int len_find = my_strlen_const(to_find);
    int len = my_strlen(str) - len_find;
    for (int i = 0; i <= len; i += 1){
        if (my_strncmp(&str[i], to_find, len_find) == 0){
            return &str[i];
        }
    }
    return NULL;
}
