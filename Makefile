# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 16:05:10 by oadewumi          #+#    #+#              #
#    Updated: 2024/06/14 11:41:06 by oadewumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBMLX = ./MLX42
LIBFT_DIR = ./libft

SOURCES = fractol.c
OFILES = $(SOURCES:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Ofast -I $(LIBFT_DIR) ./include -I $(LIBMLX)/include -v
LDFLAGS = -L $(LIBMLX)/build
LIBS = -lmlx42 -ldl -lglfw -pthread -lm
LIBFT = libft/libft.a

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIBFT) $(OFILES)
	$(CC) $(OFILES) $(LIBFT) $(LDFLAGS) $(LIBS) -o $(NAME) -v

$(LIBFT):
	@make -C $(LIBFT_DIR)

norm:
	norminette -R CheckForbiddenSourceHeader $(SOURCES)

debug: CFLAGS += -g -fsanitize=address
debug: re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES) $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re norm libmlx debug
