# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/03/04 14:38:56 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minimap
CFLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I./inc

MLX_DIR		=	lib/minilibx-linux
OBJDIR		=	./obj

VPATH		=	src:src/raycast:src/render

SRCS		=	main.c\
				init.c\
				register_hooks.c\
				my_mlx_pixel_put.c\
				render.c\
				render_map.c\
				render_3d_projection.c\
				render_3d_wall.c\
				update.c\
				cast_all_rays.c\
				find_horizontal_intersection.c\
				find_vertical_intersection.c\
				set_closer_intersection.c\
				process_key_press.c

OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DPS			=	$(SRCS:.o=.d)

LIBS		=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# -include $(DPS)

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) 

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test
