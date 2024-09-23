# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 18:16:18 by rda-cunh          #+#    #+#              #
#    Updated: 2024/09/23 16:59:08 by rda-cunh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR	= src
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/error_check.c $(SRC_DIR)/init_a_to_b.c \
	$(SRC_DIR)/init_b_to_a.c $(SRC_DIR)/input_parsing.c $(SRC_DIR)/op_push.c \
	$(SRC_DIR)/op_swap.c $(SRC_DIR)/op_rotate.c $(SRC_DIR)/op_rev_rotate.c \
	$(SRC_DIR)/sort_three.c $(SRC_DIR)/sort_turk.c $(SRC_DIR)/sort_utils.c \
	$(SRC_DIR)/stack_init.c $(SRC_DIR)/stack_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(LIBFT): 
	$(MAKE) -C ${LIBFTDIR}

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
