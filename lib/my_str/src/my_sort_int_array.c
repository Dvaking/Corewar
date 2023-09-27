/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

void my_putchar(char c);

void final(int * array, int * i, int * j)
{
    int temp = 0;
    if (array[*i] > array[*j + *i]){
        temp = array[*i];
        array[*i] = array[*j + *i];
        array[*j + *i] = temp;
    }
}

void my_sort_int_array(int * array, int size)
{
    for (int i = 0; i < size - 1; i += 1){
        for (int j = 1; j < size - i; j += 1){
            final(array, &i, &j);
        }
    }
}
