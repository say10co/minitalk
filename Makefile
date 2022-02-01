# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:42:24 by adriouic          #+#    #+#              #
#    Updated: 2022/01/31 23:35:18 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft

NAME = client

all: LIB $(NAME) server

%.o: %.c
	cc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): client.o utils.o
	cc client.o utils.o -L./libft -lft  -o client

LIB:
	@make -C $(LIBFT)

server: server.o utils.o
	cc server.o utils.o  -L./libft -lft -o server

clean:
	make clean -C $(LIBFT)
	rm -rf client.o server.o utils.o

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf client server

re: fclean all

bonus: re
