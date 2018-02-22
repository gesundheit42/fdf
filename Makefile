# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgorun <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 17:52:20 by cgorun            #+#    #+#              #
#    Updated: 2018/01/28 19:29:28 by cgorun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
SRC = *.c
INCLUDES1 = get_next_line/libft/libft.a
INCLUDES2 = get_next_line/get_next_line.a

all:
	@$(CC) $(CFLAGS) $(SRC) $(INCLUDES1) $(INCLUDES2)
