# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:42:24 by adriouic          #+#    #+#              #
#    Updated: 2022/01/07 18:33:35 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Werror -Wextra

NAME = client

all: $(NAME) server

%.o: %.c
	cc $(FLAGS) -c $<  -o ${<:.c=.o}

$(NAME): client.o utils.o
	cc client.o utils.o -o client

server: server.o utils.o
	cc server.o utils.o -o server

clean:
	rm -rf client.o server.o utils.o

fclean: clean
	rm -rf client server

re: fclean all

bonus: re
