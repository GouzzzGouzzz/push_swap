# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:58:39 by nmorandi          #+#    #+#              #
#    Updated: 2023/03/11 14:58:17 by gouz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=cc
CFLAGS= -g
LIBFT=-L ./libft -lft
FILES=main.c			\
	parsing.c 			\
	utils.c				\
	free_func.c 		\
	rules1.c 			\
	check_stack.c 		\
	ft_atoi_of.c		\
	large_sort.c		\
	sort_utils.c		\
	push_cmd_a.c		\
	push_cmd_b.c		\
	sort_utils2.c 		\

OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	(cd ./libft; make bonus)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	(cd ./libft; make clean)

fclean: clean
	rm -f $(NAME)
	(cd ./libft; make fclean)

re: fclean all

.PHONY: all re clean fclean
