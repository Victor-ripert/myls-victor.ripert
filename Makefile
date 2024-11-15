##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make units tests
##

SRC =	main.c	\
	my_ls.c	\
	create_node.c	\
	add_node.c	\
	print_node.c	\
	files_loop.c	\
	dir_processing.c	\
	file_info_process.c	\
	nbr_to_str.c	\
	create_node_info.c	\
	add_node_info.c	\
	print_node_info.c	\
	sort_stocked_info.c	\
	my_strlen.c	\
	print_node_info_l.c

NAME	=	ls

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	cd my_printf/ && make re && cd ..
	gcc -o $(NAME) $(SRC) -I./include -L./my_printf -lmy

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
