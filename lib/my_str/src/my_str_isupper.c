/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** function that returns 1 if the string passed
** as parameter only contains upper case alphabet
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] < 'A' || str[i] > 'Z'){
            return 0;
        }
        i += 1;
    }
    return 1;
}
