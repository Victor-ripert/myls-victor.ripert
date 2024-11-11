##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make units tests
##

SRC =	lib/my/my_printf.c	\
	lib/my/my_putchar.c    \
        lib/my/my_put_nbr.c    \
        lib/my/my_putstr.c     \
        lib/my/my_put_hex.c    \
	lib/my/my_put_long_hex.c	\
	lib/my/my_octal_nbr.c	\
	lib/my/my_put_float.c	\
	lib/my/my_intlen.c	\
	lib/my/my_put_scientific_notation.c	\
        lib/my/d_flag.c        \
        lib/my/s_flag.c        \
        lib/my/c_flag.c        \
        lib/my/u_flag.c        \
        lib/my/f_flag.c        \
        lib/my/p_flag.c        \
        lib/my/e_flag.c        \
	lib/my/maj_e_flag.c	\
        lib/my/a_flag.c        \
        lib/my/x_flag.c        \
        lib/my/maj_x_flag.c    \
        lib/my/o_flag.c        \
        lib/my/prcent_flag.c   \
        lib/my/n_flag.c        \
        lib/my/m_flag.c        \
        lib/my/g_flag.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp lib/my/flags.h ../include

compile:
	gcc -o bin_my_printf main.c -L. -lmy
	./bin_my_printf

clean:
	rm -f $(OBJ)

clean_unit:
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f $(NAME)

fclean_unit:	clean_unit
	rm -f unit_tests

fclean_compile:
	rm bin_my_printf

re:	fclean all

MPF =	lib/my/my_printf.c

TPF =	tests/test_my_printf.c

unit_tests:	fclean all
	gcc -o unit_tests $(MPF) $(TPF) -I. -L. -lmy --coverage -lcriterion

tests_run : fclean_unit unit_tests
	./unit_tests

gcovr_unit:
	gcovr --exclude tests/

clean_all:	fclean fclean_unit fclean_compile
