##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make units tests
##

SRC =	main.c	\
	my_ls.c

NAME	=	info_file

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	cd my_printf_victor-mathieu/ && make re && cd ..
	gcc -o $(NAME) $(SRC) -I./include -L./my_printf_victor-mathieu -lmy

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
