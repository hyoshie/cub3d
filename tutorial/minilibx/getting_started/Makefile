# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/02/23 13:53:05 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME		= tutorial
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= ../minilibx-linux
SRCS1		= init.c
OBJS1		= $(SRCS1:.cpp=.o)
SRCS2		= window.c
OBJS2		= $(SRCS2:.cpp=.o)
SRCS3		= pixel.c
OBJS3		= $(SRCS3:.cpp=.o)
SRCS4		= square.c
OBJS4		= $(SRCS4:.cpp=.o)
SRCS5		= square_filled.c
OBJS5		= $(SRCS5:.cpp=.o)
SRCS6		= circle.c
OBJS6		= $(SRCS6:.cpp=.o)
# SRCS2		= 02_textured_raycast.c
# SRCS3		= 03_img_textured_raycast.c
# SRCS4		= 04_floor_ceiling.c
# SRCS5		= 05_sprite_raycast.c
LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# all: t1 t2 t3 t4 t5
all: t1 t2 t3 t4 t5 t6

t1: $(OBJS1)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o t1 $(OBJS1) $(LIBS) 

t2: $(OBJS2)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o t2 $(OBJS2) $(LIBS) 

t3: $(OBJS3)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o t3 $(OBJS3) $(LIBS) 

t4: $(OBJS4)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o t4 $(OBJS4) $(LIBS) 

t5: $(OBJS5)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o t5 $(OBJS5) $(LIBS) 

t6: $(OBJS6)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o t6 $(OBJS6) $(LIBS) 

# t3: $(SRCS3)
# 	$(CC) $(CFLAGS) -o t3 $(SRCS3) $(LIBS) 

# t4: $(SRCS4)
# 	$(CC) $(CFLAGS) -o t4 $(SRCS4) $(LIBS) 

# t5: $(SRCS5)
# 	$(CC) $(CFLAGS) -o t5 $(SRCS5) $(LIBS) 

clean:
	$(RM) *.o

fclean: clean
	$(RM) t1 t2 t3 t4 t5

re: fclean all

# test: $(NAME)
# 	./$(NAME)

.PHONY: all clean fclean re test
