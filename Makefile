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

CC = cc
CFLAGS = -Wall -Werror -Wextra
LFLAGS	= -L$(MINILIBX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRCS = fdf.c source/calculate_map.c source/hooks.c source/isometric.c source/libx.c source/parse_map.c source/malloc.c
HEADER = fdf.h
NAME = fdf
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L$(LIBFT_PATH) -lft $(LFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
