# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adegain <adegain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/15 02:57:34 by ccheyrou          #+#    #+#              #
#    Updated: 2022/11/28 15:35:49 by adegain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS =	ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_strlen.c			\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_strdup.c			\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_strmapi.c		\
		ft_striteri.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_lstnew.c		\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstadd_front.c	\
		ft_lstadd_back.c	\
		ft_lstsize.c		\
		ft_lstiter.c		\
		ft_lstlast.c

BONUS =

OBJ = ${SRCS:.c=.o}

OBJ_BONUS = ${BONUS:.c=.o}

CC = clang

CFLAGS = -Wall -Werror -Wextra 

NORM = norminette

RM = rm -f

.PHONY: all
all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ} ${HEADER}

bonus: all ${OBJ_BONUS} ${OBJ}
	ar rcs ${NAME} ${OBJ} ${OBJ_BONUS} ${HEADER}

.PHONY: norminette
norminette:
	@${NORM} ${SRCS} ${BONUS}

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: clean 
clean:
	${RM} ${OBJ} ${OBJ_BONUS}

.PHONY: fclean 
fclean: clean
	${RM} ${NAME}

.PHONY: re 
re: fclean all

