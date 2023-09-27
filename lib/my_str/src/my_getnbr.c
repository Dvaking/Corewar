/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** return a number sent as a string
*/

int test_max_nb(long int nb)
{
    if ((nb < 2147483647) && (nb > -2147483648)) {
        return (nb);
    } else {
        return (0);
    }
}

int my_getnbr ( char const * str )
{
    long int nb = 0;
    int i = 0;
    int sign = 1;
    while (str[i] != '\0' && (str[i] > '9' || str[i] < '0')) {
        if (str[i] == '-')
            sign = sign * (-1);
        i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = (10 * nb) + (str[i] - 48);
        i++;
        if (test_max_nb (sign * nb) == 0)
            return (0);
    }
    return (sign * nb);
}
