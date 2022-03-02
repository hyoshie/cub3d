# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/03/02 13:43:01 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minimap
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= minilibx-linux
SRCS		= main.c\
			  init.c\
			  register_hooks.c\
			  my_mlx_pixel_put.c\
			  render.c\
			  render_map.c\
			  update.c\
			  cast_all_rays.c\
			  find_horizontal_intersection.c
OBJS		= $(SRCS:.c=.o)

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

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test
