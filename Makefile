##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make units tests
##

SRC =	main.c	\
	my_ls.c	\
	ls_flags.c	\
	files_to_list.c	\
	linked_list/display_list.c	\
	linked_list/display_list_l.c	\
	linked_list/push_to_list.c	\
	linked_list/select_sort.c	\
	linked_list/swap_in_list.c	 \
	linked_list/create_node.c	\
	display_args.c\
	get_info.c	\
	str/my_strcmp.c	\
	str/my_str_dup.c	\
	str/my_strlen.c	\
	str/my_putchar.c	\
	str/my_putstr.c	\
	str/my_put_nbr.c

CFLAGS	+=	-g3 -iquote ./include

NAME	+=	my_ls

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

VALGRIND_DEBUG += -g3 -iquote ./include

debug: fclean $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(VALGRIND_DEBUG)

coding_style: fclean
	clear
	../../coding-style.sh .
	cat coding-style-reports.log
	rm -f coding-style-reports.log
