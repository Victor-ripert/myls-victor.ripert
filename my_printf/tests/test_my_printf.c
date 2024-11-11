/*
** EPITECH PROJECT, 2024
** test_mini_printf
** File description:
** desc
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "flags.h"
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, string_with_flag_s, .init = redirect_all_std)
{
    my_printf("hello %s", "world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, string_with_flag_d, .init = redirect_all_std)
{
    my_printf("I am %d years old", 15);
    cr_assert_stdout_eq_str("I am 15 years old");
}

Test (my_printf, string_with_flag_i, .init = redirect_all_std)
{
    my_printf("I am %i years old", 15);
    cr_assert_stdout_eq_str("I am 15 years old");
}

Test (my_printf, string_with_negative_nb, .init = redirect_all_std)
{
    my_printf("I am %i years old", -15);
    cr_assert_stdout_eq_str("I am -15 years old");
}

Test (my_printf, string_with_flag_c, .init = redirect_all_std)
{
    my_printf("hello %corld", 'w');
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, string_with_flag_pourcent, .init = redirect_all_std)
{
    my_printf("I have 100%% covering in my unit test");
    cr_assert_stdout_eq_str("I have 100% covering in my unit test");
}

Test (my_printf, string_with_all_flag, .init = redirect_all_std)
{
    my_printf("My name is %s, i am %d years old and i'm 50%% English", "Mathieu", 18);
    cr_assert_stdout_eq_str("My name is Mathieu, i am 18 years old and i'm 50% English");
}

Test (my_printf, empty_string, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test (my_printf, returning_length, .init = redirect_all_std)
{
    int n = my_printf("Hello %s", "world");
    cr_assert(n == 11);
}

Test (my_printf, u_flag_negative_value, .init = redirect_all_std)
{
    my_printf("I have %u€ in my bank account !", -50);
    cr_assert_stdout_eq_str("I have 4294967246€ in my bank account !");
}

Test (my_printf, u_flag_positive_value, .init = redirect_all_std)
{
    my_printf("I have %u€ in my bank account !", 50);
    cr_assert_stdout_eq_str("I have 50€ in my bank account !");
}

Test (my_printf, p_flag_adress, .init = redirect_all_std)
{
    int adresse = 287;
    char resultat[14];
    my_printf("%p", &adresse);
    sprintf(resultat, "%p", &adresse);
    cr_assert_stdout_eq_str(resultat);
}

Test (my_printf, p_flag_length, .init = redirect_all_std)
{
    int adresse = 345678;
    int n;
    
    n = my_printf("%p", &adresse);
    cr_assert(n == 14);
}

Test (my_printf, n_flag_adresse_input_1, .init = redirect_all_std)
{
    int nb = 0;

    my_printf("il y a 8%n caractère jusqu'au n", &nb);
    cr_assert(nb == 8);
}

Test (my_printf, n_flag_adresse_input_2, .init = redirect_all_std)
{
    int nb = 0;
    int *ptr = &nb;

    my_printf("il y a 8%n caractère jusqu'au n", ptr);
    cr_assert(nb == 8);
}

Test (my_printf, n_flag_length, .init = redirect_all_std)
{
    int nb = 0;
    int sum = 0;
    
    sum = my_printf("il y a 8%n caractère jusqu'au n", &nb);
    cr_assert(sum == 30);
}

Test (my_printf, n_flag_with_str_int, .init = redirect_all_std)
{
    int nb = 0;
    int sum = 0;

    sum = my_printf("je m'appelle %s et j'ai %d ans je suis%n a epitech", "Victor", 18, &nb);
    cr_assert(nb == 42 && sum == 52);
}

Test (my_printf, o_flag_return_value, .init = redirect_all_std)
{
    int nb = 0;

    nb = my_printf("550 in octal is %o", 550);
    cr_assert(nb == 20);
}

Test (my_printf, o_flag_unsigned_int, .init = redirect_all_std)
{
    my_printf("550 in octal is %o", 550);
    cr_assert_stdout_eq_str("550 in octal is 1046");
}

Test (my_printf, o_flag_zero, .init = redirect_all_std)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test (my_printf, e_flag_basic_shit, .init = redirect_all_std)
{
    double nb = 1234.567;
    my_printf("%e", nb);
    cr_assert_stdout_eq_str("1.234567e+03");
}

Test (my_printf, e_flag_inf_zero, .init = redirect_all_std)
{
    double nb = 0.0123;
    my_printf("%e", nb);
    cr_assert_stdout_eq_str("1.230000e-02");
}

Test (my_printf, e_flag_negative_value, .init = redirect_all_std)
{
    double nb = -1234.567;
    my_printf("%e", nb);
    cr_assert_stdout_eq_str("-1.234567e+03");
}

Test (my_printf, e_flag_negative_value_inf_zero, .init = redirect_all_std)
{
    double nb = -0.0123;
    my_printf("%e", nb);
    cr_assert_stdout_eq_str("-1.230000e-02");
}

Test (my_printf, maj_e_flag_basic_shit, .init = redirect_all_std)
{
    double nb = 1234.567;
    my_printf("%E", nb);
    cr_assert_stdout_eq_str("1.234567E+03");
}

Test (my_printf, maj_e_flag_inf_zero, .init = redirect_all_std)
{
    double nb = 0.0123;
    my_printf("%E", nb);
    cr_assert_stdout_eq_str("1.230000E-02");
}

Test (my_printf, maj_e_flag_negative_value, .init = redirect_all_std)
{
    double nb = -1234.567;
    my_printf("%E", nb);
    cr_assert_stdout_eq_str("-1.234567E+03");
}

Test (my_printf, maj_e_flag_negative_value_inf_zero, .init = redirect_all_std)
{
    double nb = -0.0123;
    my_printf("%E", nb);
    cr_assert_stdout_eq_str("-1.230000E-02");
}




/*Test (my_printf, string_with_non_existing_flags, .init = redirect_all_std)
{
    int n = my_printf("Hello %y");
    cr_assert(n < 0);
}
*/
