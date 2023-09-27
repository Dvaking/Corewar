/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** function that returns 1 if the string passed
** as parameter only contains digits and 0 otherwise
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] < '0' || str[i] > '9'){
            return 0;
        }
        i += 1;
    }
    return 1;
}
