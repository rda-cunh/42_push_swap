# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 18:16:18 by rda-cunh          #+#    #+#              #
#    Updated: 2024/09/12 14:58:24 by rda-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR	= ./src
SRCS = error_handling.c input_parsing.c main.c op_push.c op_swap.c \
		op_rotate.c op_rev_rotate.c sort_three.c sort_turk.c sort_utils.c \
		stack_init.c stack_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(LIBFT): 
	$(MAKE) -C ${LIBFTDIR}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
