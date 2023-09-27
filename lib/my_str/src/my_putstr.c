/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** displays, one-by-one, the characters of a string
*/

void my_putchar(char c);
int my_putstr(char const * str);

int my_putstr(char const * str)
{
    int i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}
