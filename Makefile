##
## EPITECH PROJECT, 2023
## antman
## File description:
## Makefile
##

NAME	= corewar_project

all:	make_libs	$(NAME)
	make -C asm/
	make -C corewar/

make_libs:
	make -C lib/my_str

clean:
		make clean -C asm/
		make clean -C corewar/
		make clean -C lib/my_str

fclean: clean
		make fclean -C asm/
		make clean -C lib/my_str
		make clean -C corewar/

fclean: clean
		make fclean -C asm/
		make fclean -C corewar/
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean make_libs corewar_project make
