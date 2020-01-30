##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/cat.c	\
		src/my_putstr.c	\
		src/my_strlen.c	\
		src/no_bin.c	\
		src/str_cmp.c	\
		src/my_str_to_word_array_path.c	\
		src/my_str_to_word_array.c	\
		src/binary.c	\
		src/prompt.c	\
		src/str_ncmp.c	\
		src/str_cpy.c	\
		src/my_memset.c	\
		src/unsetenv.c	\
		src/setenv.c	\
		src/cd.c	\
		src/segfault.c	\
		src/setenv_err.c	\
		src/cd_err.c	\

NAME	=	mysh

OBJ	=	libmy.a

CSFML	=	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

VG	=	-g3

ERROR	=	-Wall -W -Wextra

all	:
	gcc -o $(NAME) $(SRC) $(ERROR) $(VG)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
