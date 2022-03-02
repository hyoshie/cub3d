# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/02/27 11:41:46 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME		= tutorial
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= ../minilibx-linux
SRCS1		= bitshift.c
OBJS1		= $(SRCS1:.c=.o)
SRCS2		= get_color.c
OBJS2		= $(SRCS2:.c=.o)
SRCS3		= add_shadow.c
OBJS3		= $(SRCS3:.c=.o)
SRCS4		= resize.c
OBJS4		= $(SRCS4:.c=.o)
SRCS5		= longpress.c
OBJS5		= $(SRCS5:.c=.o)
SRCS6		= mouse.c
OBJS6		= $(SRCS6:.c=.o)

LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIB_MLX	    = $(MLX_DIR)/libmlx.a

all: t1 t2 t3

$(LIB_MLX):
	$(MAKE) -C $(MLX_DIR)

t1: $(LIB_MLX) $(OBJS1)
	$(CC) $(CFLAGS) -o t1 $(OBJS1) $(LIBS) 

t2: $(LIB_MLX) $(OBJS2)
	$(CC) $(CFLAGS) -o t2 $(OBJS2) $(LIBS) 

t3: $(LIB_MLX) $(OBJS3)
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
