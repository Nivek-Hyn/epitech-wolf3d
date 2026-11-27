##
## EPITECH PROJECT, 2025
## bs_wolf3d
## File description:
## Makefile
##

NAME	=	wolf3d

SRC		=	$(shell find . -type f -name "*.c" ! -path "./bonus/*")

OBJ		=	$(patsubst %.c, obj/%.o, $(SRC))

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

FLAGS	=	-lm -g3

VLGRD	=	--track-origins=yes --leak-check=full

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -I./include $(OBJ) $(CSFML) $(FLAGS)

obj/%.o:	%.c
	mkdir -p $(dir $@)
	gcc -c -I./include $< -o $@ $(CSFML) $(FLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno
	rm -rf obj

fclean:	clean
	rm -f $(NAME)

re:	fclean all

valgrind:
	valgrind $(VLGRD) ./$(NAME)

codstyle:	fclean
	~/my_scripts/coding-style.sh . .; cat coding-style-reports.log
	rm -f coding-style-reports.log
