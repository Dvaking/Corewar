/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** function compares the two strings s1 and s2
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    while ((s1[i] != '\0' || s2[i] != '\0') && n > i){
        if (s1[i] - s2[i] != 0){
            return (s1[i] - s2[i]);
        }
        i += 1;
    }
    return 0;
}
