/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** function that capitalizes the first letter of each word
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;
    int bool = 1;
    my_strlowcase(str);
    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9'){
            bool = 0;
        }
        if (str[i] == ' ' || str[i] == '+' || str[i] == '-'){
            bool = 1;
        }
        if (bool == 1 && str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
            bool = 0;
        }
        i += 1;
    }
    return str;
}
