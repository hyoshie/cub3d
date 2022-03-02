# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/02/27 11:12:03 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME		= tutorial
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= ../minilibx-linux
SRCS1		= circle.c
OBJS1		= $(SRCS1:.c=.o)
SRCS2		= rainbow.c
OBJS2		= $(SRCS2:.c=.o)
SRCS3		= transparency.c
OBJS3		= $(SRCS3:.c=.o)

LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIB_MLX		= $(MLX_DIR)/libmlx.a

all: t1 t2 t3

$(LIB_MLX):
	$(MAKE) -C $(MLX_DIR)

t1: $(LIB_MLX) $(OBJS1)
	$(CC) $(CFLAGS) -o t1 $(OBJS1) $(LIBS) 

t2: $(LIB_MLX) $(OBJS2)
	$(CC) $(CFLAGS) -o t2 $(OBJS2) $(LIBS) 

t3: $(LIB_MLX) $(OBJS3)
	$(CC) $(CFLAGS) -o t3 $(OBJS3) $(LIBS) 

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(LIB_MLX)
	$(RM) t1 t2 t3 t4 t5 t6 t7 t8

re: fclean all

# test: $(NAME)
# 	./$(NAME)

.PHONY: all clean fclean re test
