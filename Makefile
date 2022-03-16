# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:37:22 by hyoshie           #+#    #+#              #
#    Updated: 2022/03/16 11:38:03 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I./inc -I./$(MLX_DIR) -I$(LIBFT_DIR) -I./bonus/inc

MLX_DIR		=	lib/minilibx-linux
LIBFT_DIR	=	lib/libft
OBJDIR		=	./obj

VPATH		=	src:src/raycast:src/render:src/init:src/game:src/utils:src/minimap\
				bonus/src:bonus/src/raycast:bonus/src/render:bonus/src/init:bonus/src/game:bonus/src/utils:bonus/src/minimap

SRCS		=	main.c\
				free_all_exit.c\
				process_keypress.c\
				register_hooks.c\
				update.c\
				check_args.c\
				check_map_closed.c\
				init.c\
				init_design.c\
				init_map.c\
				init_player.c\
				parse_file.c\
				parse_file_utils.c\
				rgb_utils.c\
				validate_design.c\
				validate_map.c\
				validate_player.c\
				xmlx.c\
				cast_all_rays.c\
				find_horiz_wall_hit.c\
				find_vert_wall_hit.c\
				set_closer_wall_hit.c\
				get_texel_color.c\
				my_mlx_pixel_put.c\
				render_3d_projection.c\
				render.c\
				is_floor.c\
				is_player.c\
				map_has_wall_at.c\
				normalize_angle.c

SRCS_BONUS	=	main.c\
				free_all_exit_bonus.c\
				process_keypress_bonus.c\
				register_hooks_bonus.c\
				update_bonus.c\
				check_args_bonus.c\
				check_map_closed_bonus.c\
				init_bonus.c\
				init_design_bonus.c\
				init_map_bonus.c\
				init_minimap_bonus.c\
				init_player_bonus.c\
				parse_file_bonus.c\
				parse_file_utils_bonus.c\
				rgb_utils_bonus.c\
				validate_design_bonus.c\
				validate_map_bonus.c\
				validate_player_bonus.c\
				xmlx_bonus.c\
				render_all_ray_bonus.c\
				render_minimap_bonus.c\
				cast_all_rays_bonus.c\
				find_horiz_wall_hit_bonus.c\
				find_vert_wall_hit_bonus.c\
				set_closer_wall_hit_bonus.c\
				get_texel_color_bonus.c\
				my_mlx_pixel_put_bonus.c\
				render_3d_projection_bonus.c\
				render_bonus.c\
				is_floor_bonus.c\
				is_player_bonus.c\
				map_has_wall_at_bonus.c\
				normalize_angle_bonus.c

OBJS		=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS	=	$(addprefix $(OBJDIR)/, $(notdir $(SRCS_BONUS:.c=.o)))
BONUS_FLG	=	.bonus_flg

DEPS		=	$(OBJS:.o=.d)
DEPS_BONUS	=	$(OBJS_BONUS:.o=.d)

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
	$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_FLG)

$(BONUS_FLG):	$(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBS) 
	@touch $(BONUS_FLG)

norm: $(NAME)
	norminette inc src lib/libft bonus

nm: $(NAME)
	@nm -u $(NAME) | awk '{print $$2}' | awk -F'@' '{print $$1}' | egrep -v "^_" | egrep -v "open|close|read|write|printf|malloc|free|perror|strerror|exit" | egrep -v "^X" | egrep -v "cos|sin|tan|floor|ceil|pow|sqrt|remainder"

# ignore unknown error
nmgrep:
	-@nm -u $(NAME) | awk '{print $$2}' | awk -F'@' '{print $$1}' | egrep -v "^_" | egrep -v "open|close|read|write|printf|malloc|free|perror|strerror|exit" | egrep -v "^X" | egrep -v "cos|sin|tan|floor|ceil|pow|sqrt|remainder" | xargs -I{} bash -c "echo '[[' {} ']]'; grep -rn {} src lib/libft/*/*.c"

.PHONY: all clean fclean re nm nmgrep bonus norm
