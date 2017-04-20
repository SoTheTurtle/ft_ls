# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbanc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/01 15:03:20 by sbanc             #+#    #+#              #
#    Updated: 2017/04/20 11:33:45 by sbanc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = libft/libft.a\
	  add_elem.c\
	  is_dir.c\
	  main.c\
	  max_group.c\
	  max_user.c\
	  maxim_size.c\
	  put_group.c\
	  put_links.c\
	  put_major.c\
	  put_minor.c\
	  put_permissions.c\
	  put_size.c\
	  put_stats.c\
	  put_time.c\
	  put_totsize.c\
	  put_user.c\
	  reverse_sort.c\
	  sort_by_date.c\
	  sort_dir.c\
	  dev_alert.c\
	  max_links.c\
	  put_help.c\
	  put_help2.c\
	  read_dir.c\
	  put_simple.c\
	  time_switch_cond.c
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
