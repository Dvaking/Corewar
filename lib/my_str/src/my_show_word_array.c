/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** function that displays the content of an array of words
*/

void my_putchar(char c);
int my_putstr(char const * str);

int my_show_word_array(char *const *tab)
{
    int i = 0;
    while (tab[i] != 0){
        my_putstr(tab[i]);
        my_putchar('\n');
        i += 1;
    }
    return 0;
}
