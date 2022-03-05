#
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/verif_options.c \
		src/check_size.c \
		src/debug_mode/debug_mode.c \
		src/debug_mode/debug_piece.c \
		src/debug_mode/canon_mode.c \
		src/options/options_game.c \
		src/options/options_key_game.c \
		src/options/options_map_quit.c \
		src/options/recup_option.c 	\
		src/recup_paths.c \
		src/sort_paths.c \
		src/recup_piece/replace_chara.c\
		src/recup_piece/count_size.c\
		src/recup_piece/verif_piece.c \
		src/recup_piece/recup_file.c \
		src/recup_piece/recup_piece.c \
		src/recup_piece/store_pieces.c \
		src/recup_piece/check_size.c \
		src/recup_piece/clean_empty_lines_pieces.c \
		src/display_screen/display_screen.c 	\
		src/display_screen/display_all_array.c\
		src/display_screen/display_tetris.c\
		src/game_loop.c \
		src/recup_key.c \
		src/my_strcmp_beg.c \
		src/initialisation_screen.c \
		src/my_putstr_error.c\
		src/game/init_tetras.c\
		src/game/check_if_can_fall.c\
		src/game/check_line_complete.c\
		src/game/manage_function_after_timer.c \
		src/game/move_tetriminos.c \
		src/game/manage_function_key.c \
		src/game/drop_the_piece.c \
		src/random_tetriminos/random_tetrimino.c\
		src/random_tetriminos/add_new_tetrimino.c\
		src/random_tetriminos/random_position.c \
		src/rotate_piece.c \
		src/game_over.c \
		src/pause_game.c \
		src/game/init_screen.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

INC	=	-I./include -I./lib/my/include

LIBS	=	-L./lib/my -lmy	 \

CFLAGS	=	$(INC) -W -Wextra -Wall

CC	=	gcc

LIB	= 	make -C lib/my/

NCURSES	=	-l ncurses

all:		$(NAME)

$(NAME):	$(OBJ)
		$(LIB)
		$(CC) -o $(NAME) $(NCURSES) $(OBJ) $(LIBS) 

clean:
		$(RM) $(OBJ)
		make clean -C lib/my/

fclean: 	clean
		$(RM) $(NAME)
		make fclean -C lib/my/

re:		fclean all

tests_run :
			make -C tests/
			./units

debug: 		CFLAGS += -g
debug:		re
