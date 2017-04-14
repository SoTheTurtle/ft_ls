# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbanc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/01 15:03:20 by sbanc             #+#    #+#              #
#    Updated: 2017/04/01 15:14:45 by sbanc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = libft/libft.a\
	  main.c
DIRS = libft/

all:
	cd $(DIRS) && make
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	cd $(DIRS) && make clean

fclean:
	rm -f $(NAME)
	cd $(DIRS) && make fclean
re:fclean all
