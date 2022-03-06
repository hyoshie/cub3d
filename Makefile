# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/03/05 21:02:19 by yshimazu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	cub3D
CFLAGS		=	-Wall -Wextra -Werror -g
INCLUDES	=	-I./inc -I./$(MLX_DIR) -I$(LIBFT_DIR)

MLX_DIR		=	lib/minilibx-linux
LIBFT_DIR	=	lib/libft
OBJDIR		=	./obj

VPATH		=	src:src/raycast:src/render:src/init

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
				process_key_press.c\
				check_args.c\
				parse_file.c

OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DPS			=	$(SRCS:.o=.d)
LIBS 		=	-L$(LIBFT_DIR) -lft


UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
# MacOS での処理
INCLUDES	+=	-I/usr/X11/include
LIBS		+=	-L$(MLX_DIR) -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11
else
ifeq ($(UNAME), Linux)
# Linux での処理
LIBS		+=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif
endif

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# -include $(DPS)

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) 

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_DIR)/libft.a
	$(RM) $(MLX_DIR)/libmlx.a
	$(RM) $(MLX_DIR)/libmlx_Darwin.a
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test