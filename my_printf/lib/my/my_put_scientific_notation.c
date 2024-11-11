/*
** EPITECH PROJECT, 2024
** e_flag
** File description:
** e flag from my_printf
*/
#include <stdarg.h>
#include "flags.h"

static int exponant_pos(double arg)
{
    int argint = (int)arg;
    int exponant = 0;

    exponant = my_intlen(argint);
    return exponant - 1;
}

static int exponant_neg(double arg)
{
    double argneg = arg;
    int exponant = 0;

    for (exponant = 0; argneg < 1; exponant++) {
        argneg = argneg * 10;
    }
    return exponant;
}

static double arg_scientific_float(double arg)
{
    int arg_2 = (int)arg;

    while (arg_2 < 1) {
        arg = arg * 10;
        arg_2 = (int)arg;
    }
    while (arg_2 > 9) {
        arg = arg / 10;
        arg_2 = (int)arg;
    }
    return arg;
}

static void display_e_flag(double arg, char signe, int exponant, char e)
{
    my_put_float(arg);
    my_putchar(e);
    my_putchar(signe);
    if (exponant < 10) {
        my_putchar('0');
    }
    my_put_nbr(exponant);
}

static char e_flag_expo_signe(double arg, int *exponant, char signe)
{
    if (arg > 1) {
        exponant[0] = exponant_pos(arg);
        signe = '+';
    } else {
        exponant[0] = exponant_neg(arg);
        signe = '-';
    }
    return signe;
}

int my_put_scientific_notation(double arg, char e)
{
    int exponant = 0;
    int arg_2 = (int)arg;
    char signe;
    int *ptr = &exponant;

    if (arg == 0) {
        my_putstr("0.000000e+00");
        return 12;
    }
    if (arg < 0) {
        arg = arg * -1;
        my_putchar('-');
    }
    signe = e_flag_expo_signe(arg, ptr, signe);
    arg = arg_scientific_float(arg);
    display_e_flag(arg, signe, exponant, e);
    return 12;
}
