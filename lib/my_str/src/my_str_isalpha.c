/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** function that returns 1 if the string passed
** as parameter only contains alphabetical
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z'))){
            return 0;
        }
        i += 1;
    }
    return 1;
}
