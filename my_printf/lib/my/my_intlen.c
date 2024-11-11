/*
** EPITECH PROJECT, 2024
** my_intlen
** File description:
** return the number of character of an int
** my_intlen(100) -> 3
** 1 0 0
** 1 2 3
*/

int my_intlen(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    while (nb > 0) {
        nb = nb / 10;
        count++;
    }
    return count;
}
