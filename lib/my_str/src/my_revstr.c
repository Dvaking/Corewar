/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** function that reverses a string
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char temp = 'a';
    int count = my_strlen(str) + 1;
    int action = count / 2;
    for (int i = 0; i < action; i += 1){
        temp = str[i];
        str[i] = str[count - i - 2];
        str[count - i - 2] = temp;
    }
    return str;
}
