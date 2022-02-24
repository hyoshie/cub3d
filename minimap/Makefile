# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/02/24 12:10:05 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minimap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= minilibx-linux
SRCS		= main.c
OBJS		= $(SRCS:.cpp=.o)

LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# test: $(NAME)
# 	./$(NAME)

.PHONY: all clean fclean re test
