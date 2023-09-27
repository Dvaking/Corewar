/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** function that returns the smallest prime number
*/

int my_find_prime_sup(int nb);
int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if ((nb < -2147483648) || (nb > 2147483647)){
        return 0;
    }
    int result = -1;
    int i = nb ;
    if (nb <= 0){
        i = 2;
    }
    while (result == -1){
        if (my_is_prime(i) == 1){
            result = i;
        }
        i += 1;
    }
    return result;
}
