# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 15:23:50 by jalombar          #+#    #+#              #
#    Updated: 2024/07/30 15:23:50 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Werror -Wextra
LFLAGS	= -Lincludes/mlx_linux -lmlx_Linux -Iincludes/mlx_linux -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_PATH) -lft
SRCS = fdf.c source/calculate_map.c source/parse_map.c source/malloc.c
HEADER = fdf.h
NAME = fdf
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L$(LIBFT_PATH) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
