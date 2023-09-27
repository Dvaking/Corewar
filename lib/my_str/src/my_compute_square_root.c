/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** returns the square root
*/

int my_compute_square_root(int nb);

int my_compute_square_root(int nb)
{
    if ((nb < -2147483648) || (nb > 2147483647)){
        return 0;
    }
    int result = 0;
    if (nb == 1){
        return 1;
    }
    for (int i = 0; i < nb; i += 1){
        if ((i * i) == nb){
            result = i;
            break;
        }
    }
    return result;
}
