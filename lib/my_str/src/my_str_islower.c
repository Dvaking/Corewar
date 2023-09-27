/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** function that returns 1 if the string passed
** as parameter only contains lower case alphabet
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] < 'a' || str[i] > 'z'){
            return 0;
        }
        i += 1;
    }
    return 1;
}
