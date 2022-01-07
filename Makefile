# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:42:24 by adriouic          #+#    #+#              #
#    Updated: 2022/01/07 18:23:57 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Werror -Wextra

all: client server

%.o: %.c
	cc $(FLAGS) -c $<  -o ${<:.c=.o}

client: client.o utils.o
	cc client.o utils.o -o client

server: server.o utils.o
	cc server.o utils.o -o server

clean:
	rm -rf client.o server.o utils.o

fclean: clean
	rm -rf client server

re: fclean all

bonus: re
