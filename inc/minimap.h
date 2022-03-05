/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:00:27 by user42            #+#    #+#             */
/*   Updated: 2022/03/05 21:00:08 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP
#define MINIMAP

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/mylibft.h"

typedef struct s_point {
  double x;
  double y;
} t_point;

typedef struct s_img {
  void *img_ptr;
  char *addr;
  int bits_per_pixel;
  int size_line;
  int endian;
} t_img;

typedef struct s_map {
  char **map_ptr;
  size_t	width;
  size_t	height;
} t_map;

typedef struct s_player {
  t_point position;
  double radius;
  double walk_direction; // 0 is forward, M_PI is back
  bool	should_move;
  double rotation_angle;
  double fov_angle;
  int walk_speed;
  double turn_speed;
} t_player;

typedef struct s_ray {
  double angle;
  t_point wall_hit;
  double distance;
  bool was_hit_vertical;
  bool is_facing_up;
  bool is_facing_down;
  bool is_facing_left;
  bool is_facing_right;
  int wall_hit_content; // need check
} t_ray;

typedef struct s_design {
	t_img	*no_texture;
	t_img	*so_texture;
	t_img	*we_texture;
	t_img	*ea_texture;
	int		c_color;
	int		f_color;
} t_design;

typedef struct s_game {
  void *mlx_ptr;
  void *win_ptr;
  t_map map;
  t_player player;
  t_ray *ray;
} t_game;

void	init_game(t_game *game, char *file_path);
void	init_image(t_img *img, void *mlx_ptr, int width, int height);
void	process_key_press(int keycode, t_player *player);
void	register_hooks(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	cast_all_rays(t_ray *ray, t_player *player, t_map *map);
void	update(t_game *game);
int		render(t_game *game);
void	render_map(t_map *map, t_img *win_img);
void	render_3d_projection(t_player *player, t_ray *ray, t_img *win_img);
void	render_3d_wall(t_player *player, t_ray *ray, t_img *win_img);
bool	map_has_wall_at(double x, double y, char **map);
t_point	find_horizontal_intersection(const t_ray *ray, const t_point *player_pos,
                                     const t_map *map);
t_point	find_vertical_intersection(t_ray *ray, t_point *player_pos, t_map *map);
void	set_closer_intersection(t_ray *ray, const t_point *horiz_intersection,
								const t_point *vert_intersection, const t_point *player_pos);
void	check_args(int ac, char **av);
void	parse_file(char *file_path);
#endif /* MINIMAP */
