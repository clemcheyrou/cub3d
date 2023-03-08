# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adegain <adegain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:07:29 by adegain           #+#    #+#              #
#    Updated: 2023/03/08 16:51:32 by adegain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= cub3d

SRCS:= 

# --------------------
CC:= gcc
SRCS_PATH:= srcs/
HDR_PATH:= include/
CCHPATH:= obj/
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
OBJ:= $(addprefix $(CCHPATH),$(addsuffix .o, $(SRCS)))
CCHF:= .cache_exists
# ====================

# --------------------

all:		${NAME}

${NAME}:	${OBJ} ${SRCS}
	@echo ${CYAN} " - Compiling $@" ${EOC}
	@${LIBFT} >/dev/null
	@${MLX} >/dev/null
	@${CC} ${CFLAGS} ${SRCS} ${LIBFT_A} -L ${MLXHDR} -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
	@echo ${GREEN} " - OK" ${EOC}

${CCHPATH}%.o: ${SRCPATH}%.c | ${CCHF}
	@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
	@${CC} ${CFLAGS} -I mlx_linux -O3 -c $< -o $@

%.c:
	@echo ${RED}"Missing file : $@" ${EOC}

$(CCHF):
	@mkdir ${CCHPATH}
	@touch ${CCHF}

clean:
	@${MLX} clean >/dev/null
	@${LIBFT} clean >/dev/null
	@rm -rf ${CCHPATH}
	@rm -f ${CCHF}

fclean:		clean
	${MLX} clean >/dev/null
	${LIBFT} fclean >/dev/null
	@rm -f ${NAME}
	@rm -f ${NAME}.dSYM/
	@echo ${GREEN} " - CLEAN" ${EOC}

re:			fclean 
	@${MAKE} all

.PHONY:		all clean fclean re