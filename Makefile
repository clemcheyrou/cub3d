# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adegain <adegain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:07:29 by adegain           #+#    #+#              #
#    Updated: 2023/03/16 12:25:14 by adegain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= cub3D

SRCS:= 	main \
		get_next_line/get_next_line \
		get_next_line/get_next_line_utils \
		/parsing/free \
		/parsing/get_file \
		/parsing/init_struct \
		/parsing/parsing_args \
		/parsing/parsing_elements \
		/parsing/parsing_map \
		/parsing/utils \
		/game/init_game

# --------------------
CC:= gcc
SRCS_PATH:= srcs/
HDR_PATH:= include/
CCH_PATH:= obj/
LIBFT:= make -C ./Libft
LIBFT_HDR:= Libft/
LIBFT_A:= Libft/libft.a
MLX:= make -C ./minilibx
MLX_HDR:= minilibx/
CFLAGS:= -Wall -Werror -Wextra -g3 -I ${HDR_PATH} -I ${MLX_HDR} -I ${LIBFT_HDR}
# ====================

# ------ Colors ------
RED:= "\033[1;31m"
GREEN:= "\033[1;32m"
PURPLE:= "\033[1;35m"
CYAN:= "\033[1;36m"
EOC:= "\033[0;0m"
# ====================

# --- Compilation ----
SRC:= $(addprefix $(SRCS_PATH),$(addsuffix .c, $(SRCS)))
OBJ:= $(addprefix $(CCH_PATH),$(addsuffix .o, $(SRCS)))
# ====================

# --------------------

all:		${NAME}

${NAME}:	${OBJ} ${SRC}
			@echo ${CYAN} " - Compiling $@" ${EOC}
			@${LIBFT} >/dev/null
			@${MLX} >/dev/null
			@${CC} ${CFLAGS} ${SRC} ${LIBFT_A} -L ${MLX_HDR} -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
			@echo ${GREEN} " - OK" ${EOC}

${CCH_PATH}%.o: ${SRCS_PATH}%.c
			@mkdir -p $(@D)
			@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
			@${CC} ${CFLAGS} -I mlx_linux -O3 -c $< -o $@

%.c:
			@echo ${RED}"Missing file : $@" ${EOC}

clean:
			@${MLX} clean >/dev/null
			@${LIBFT} clean >/dev/null
			@rm -rf ${CCH_PATH}

fclean:		clean
			@${MLX} clean >/dev/null
			@${LIBFT} fclean >/dev/null
			@rm -f ${NAME}
			@rm -f ${NAME}.dSYM/
			@rm -rf ${CCH_PATH}
			@echo ${GREEN} " - CLEAN" ${EOC}

re:			fclean 
			@${MAKE} all

.PHONY:		all clean fclean re