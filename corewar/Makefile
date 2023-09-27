##
## EPITECH PROJECT, 2023
## B-CPE-110-BDX-1-1-antman-killian.trouve
## File description:
## Makefile
##

SRC			=	main.c						\
				transform_big_to_little.c 	\
				toolbox/help.c				\
				toolbox/free.c				\
				toolbox/complement.c		\
				init/init_arena.c			\
				init/init_id_champ.c		\
				init/get_len_empty.c			\
				../../op.c					\

VM			=	virtual_machine.c		\
				game.c					\
				command.c				\
				manage_cycles.c			\
				coding_byte.c			\
				move_byte.c				\
				win_case.c				\

PARCS		=	check_flags.c		\
				flags.c				\
				create_champ.c		\
				parcers.c			\

COMMAND		=	add_command.c		\
				aff_command.c		\
				and_command.c		\
				fork_command.c		\
				ld_command.c		\
				ldi_command.c		\
				lfork_command.c		\
				live_command.c		\
				lld_command.c		\
				lldi_command.c		\
				or_command.c		\
				st_command.c		\
				sti_command.c		\
				sti_command_sub.c	\
				sub_command.c		\
				xor_command.c		\
				zjmp_command.c		\

DIR_SRC			=	$(addprefix src/, $(SRC))

DIR_VM			=	$(addprefix src/vm/, $(VM))

DIR_PARCS		=	$(addprefix src/parcers/, $(PARCS))

DIR_COMMAND		=	$(addprefix src/command_functions/, $(COMMAND))

OBJ			=	$(DIR_SRC:.c=.o) $(DIR_PARCS:.c=.o) $(DIR_VM:.c=.o) \
				$(DIR_COMMAND:.c=.o)

LDLIBS		=	-L ../lib/ -lmy

CPPFLAGS	=	-I ../includes/corewar -I ../lib/my/include \
				-I ../includes/combined -ggdb3

CFLAGS		=	-Wall -Wextra

NAME	= corewar

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my/
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

clean:
		make clean -C ../lib/my/
		rm -f $(OBJ)

fclean: clean
		make fclean -C ../lib/my/
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean make_libs
