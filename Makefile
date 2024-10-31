# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2024/10/31 16:22:21 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c

OBJ = ${SRC:.c=.o}


NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs $@ ${OBJ}

%o.: %.c
	${cc} ${CFLAGS} -o $@ -c $< 

test:
	gcc *.c 

clean:
	rm -rf ${OBJ} ${OBJS_BONUS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all test clean fclen re
