##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

SRC			=	main.c											\
				help.c											\
				endian_conversion.c								\
				get_nb_bytes_from_body.c						\
				is_char.c										\
				remove_bottom.c									\
				my_free_strcpy.c								\
				free_tab.c										\
				write_header_in_file.c							\
				launch_asm.c									\
				create_file/get_the_extension_of_the_file.c		\
				create_file/generate_a_bytecode_file.c			\
				create_file/create_the_name_of_the_new_file.c	\
				extract_datas/add_at_end.c						\
				extract_datas/extract_header_from_file.c		\
				extract_datas/is_in_str.c						\
				extract_datas/my_strtok.c						\
				extract_datas/nb_token.c						\
				extract_datas/get_body.c						\
				extract_datas/token_size.c						\
				convert_body.c									\
				exa_convert.c									\
				exa_conversions.c								\
				../../op.c

DIR_SRC =       $(addprefix src/, $(SRC))

OBJ     =       $(DIR_SRC:.c=.o)

LDLIBS		=	-L ../lib/ -l my_str

CPPFLAGS	=	-I ../includes/asm_folder/ -I ../includes/combined/ \
-I ../lib/my_str/include

CFLAGS		=	-Wall -Wextra -g3

NAME	= asm

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my_str/
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

clean:
		make clean -C ../lib/my_str/
		rm -f $(OBJ)

fclean: clean
		make fclean -C ../lib/my_str/
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
