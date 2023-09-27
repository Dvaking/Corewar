/*
** EPITECH PROJECT, 2023
** my_str_is_printable
** File description:
** a function that returns 1 if the string passed
** as parameter only contains printable
** characters and 0 otherwise
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] < 32 || str[i] > 126){
            return 0;
        }
        i += 1;
    }
    return 1;
}
