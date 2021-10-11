SRCS 		= 	so_long.c utils/draw.c utils/ft_itoa_long.c utils/valid_map.c utils/key_hook.c utils/enemies.c \
				utils/move_enemies.c g_n_l/get_next_line.c g_n_l/get_next_line_utils.c
SBONUS		=	so_long_bonus.c utils/draw.c utils/ft_itoa_long.c utils/valid_map_bonus.c utils/key_hook.c utils/enemies.c \
				utils/move_enemies.c g_n_l/get_next_line.c g_n_l/get_next_line_utils.c
NAME		= 	so_long
BONUS_NAME	=	so_long_bonus
INCS		=   -I ./includes/ -I ./minilibx/
GCC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all:			${NAME}

${NAME}:
	# @say -v Yuri "Илд*ар, гей!"
	${GCC} ${CFLAGS} ${INCS} -lmlx -framework OpenGL -framework AppKit ${SRCS} -o ${NAME}

bonus:			${BONUS_NAME}

${BONUS_NAME}:
	${GCC} ${CFLAGS} ${INCS} -lmlx -framework OpenGL -framework AppKit ${SBONUS} -o ${BONUS_NAME}

clean:
				${RM} ${NAME} ${BONUS_NAME}

fclean:			clean
				${RM} ${NAME} ${BONUS_NAME}

re:				fclean all
.PHONY:
				all, fclean, clean, re