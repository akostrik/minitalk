# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:57:13 by akostrik          #+#    #+#              #
#    Updated: 2023/07/07 20:33:32 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c utils.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS    = -Wall -Wextra -Werror

all: libft server client

server: server.o utils.o
	cc $^ -o $@ -Llibft -lft

client: client.o utils.o
	cc $^ -o $@ -Llibft -lft

%.o: %.c
	cc -c ${CFLAGS} $?

libft:
	make -C libft

clean:
	rm -f ${OBJECTS}
	make -C libft clean

fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all clean fclean re libft