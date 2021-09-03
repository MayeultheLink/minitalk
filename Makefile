# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 18:36:50 by mde-la-s          #+#    #+#              #
#    Updated: 2021/09/02 16:41:45 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	server

SRCSSER	=	srcs/ft_atoi.c \
			srcs/ft_itoa.c \
			srcs/ft_strlen.c \
			server.c
SRCSCLI	=	srcs/ft_atoi.c \
			srcs/ft_itoa.c \
			srcs/ft_strlen.c \
			client.c

# Colors
_GREY=$ \x1b[30m
_RED=$ \x1b[31m
_GREEN=$ \x1b[32m
_YELLOW=$ \x1b[33m
_BLUE=$ \x1b[34m
_PURPLE=$ \x1b[35m
_CYAN=$ \x1b[36m
_WHITE=$ \x1b[37m
_END=$ \x1b[0m

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I./headers

OBJSSER	=	${SRCSSER:.c=.o}
OBJSCLI	=	${SRCSCLI:.c=.o}

all		:	${NAME}

$(NAME)	:	${OBJSSER} ${OBJSCLI}
		${CC} ${CFLAGS} -o server ${OBJSSER}
		@echo "$(_GREEN)SERVER OK${_END}"
		${CC} ${CFLAGS} -o client ${OBJSCLI}
		@echo "$(_GREEN)CLIENT OK${_END}"
		
clean	:
		rm -f ${OBJSSER} ${OBJSCLI}

fclean	:	clean
		rm -f server client

re		:	fclean all

.PHONY	:	all clean fclean re
