/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** function that returns 1
*/

int my_is_prime(int nb);

int my_is_prime(int nb)
{
    if ((nb < 1) || (nb == 1) || (nb > 2147483647)){
        return 0;
    }
    for (int i = 2; i < nb; i += 1){
        if ((nb % i) == 0){
            return 0;
        }
    }
    return 1;
}
