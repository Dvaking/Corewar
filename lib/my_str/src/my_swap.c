/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int * b);

void my_swap(int *a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
