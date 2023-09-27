##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC     =	src/my_isneg.c				\
			src/my_showstr.c			\
			src/my_str_isalpha.c		\
			src/my_strncat.c			\
			src/my_is_prime.c			\
			src/my_show_word_array.c	\
			src/my_str_islower.c		\
			src/my_strncmp.c			\
			src/my_compute_power_rec.c	\
			src/my_putchar.c			\
			src/my_sort_int_array.c		\
			src/my_str_isnum.c			\
			src/my_strncpy.c			\
			src/my_compute_square_root.c\
			src/my_put_nbr.c			\
			src/my_strcapitalize.c		\
			src/my_str_isprintable.c	\
			src/my_strstr.c				\
			src/my_find_prime_sup.c		\
			src/my_putstr.c				\
			src/my_strcat.c				\
			src/my_str_isupper.c		\
			src/my_str_to_word_array.c	\
			src/my_getnbr.c				\
			src/my_revstr.c				\
			src/my_strcmp.c				\
			src/my_strlen.c				\
			src/my_strupcase.c			\
			src/my_showmem.c			\
			src/my_strcpy.c				\
			src/my_strlowcase.c			\
			src/my_swap.c

OBJ     =		$(SRC:.c=.o)

NAME	=		../libmy_str.a

$(NAME):		$(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
