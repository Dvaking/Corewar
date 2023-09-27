/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

int my_put_nbr(int nb);
int my_putstr(char const * str);
void my_putchar(char c);

static int display(int nb)
{
    int temp = nb % 10;
    if (nb == 0){
        return 0;
    }
    display(nb / 10);
    my_putchar(temp + 48);
    return nb;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0){
        my_putchar('-');
        nb = - nb;
    }
    if (nb == 0){
        my_putchar('0');
    } else {
        display(nb);
    }
    return 0;
}
