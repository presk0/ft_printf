# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2024/10/22 19:06:00 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c

OBJS = ${SRCS:.c=.o}

OBJS_DIR = obj/

OBJS_ABS = $(addprefix ${OBJS_DIR}, ${OBJS})

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: ${NAME}

${NAME}: ${OBJS_ABS}
	@ar rcs $@ $?

${OBJS_DIR}%.o: %.c
	@mkdir -p $(OBJS_DIR)
	${CC} ${CFLAGS} -c $< -o $@

test:
	${CC} ${SRCS}
	./a.out ${ARG1} ${ARG2} ${ARG3}
	rm a.out

debug:
	${CC} -g ${SRCS}
	lldb a.out
	rm a.out

clean:
	rm -rf ${OBJS_ABS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
