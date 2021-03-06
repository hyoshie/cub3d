/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:00:27 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:17:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/mylibft.h"

typedef int		t_color;
typedef enum e_wall {
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall;

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;
typedef t_img	t_texture;

typedef struct s_map {
	char	**map_ptr;
	size_t	num_cols;
	size_t	num_rows;
	size_t	width;
	size_t	height;
}	t_map;

// should_move, should_rotateの命名がしっくりこないです
typedef struct s_player {
	t_point	pos;
	t_point	wall_hit;
	double	walk_direction;
	double	angle;
	double	fov_angle;
	double	turn_speed;
	double	auto_turn_speed;
	bool	should_move;
	bool	should_rotate;
}	t_player;

// 余裕があったらis_facingを一つの変数にする
typedef struct s_ray {
	double	angle;
	t_point	*light_source;
	t_point	wall_hit;
	double	distance;
	bool	was_hit_vertical;
	bool	is_facing_up;
	bool	is_facing_down;
	bool	is_facing_left;
	bool	is_facing_right;
	t_wall	wall_direction;
}	t_ray;

typedef struct s_design {
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_color		ceil;
	t_color		floor;
}	t_design;

typedef struct s_wall_strip {
	int	height;
	int	top_pixel;
	int	bottom_pixel;
}	t_wall_strip;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_map		map;
	t_design	design;
	t_player	player;
	t_ray		*ray;
}	t_game;

/*	init	*/
void	check_args(int ac, char **av);
void	init_game(t_game *game, char *file_path);
void	init_image(t_img *img, void *mlx_ptr, int width, int height);
void	init_design(t_clst *file_lst, t_design *design, int map_start_line, \
						void *mlx_ptr);
void	init_map(t_clst *file_lst, t_map *map, int map_start_line, \
						int num_nodes);
void	check_map_closed(char **map);
void	init_player(char **map_ptr, t_player *player);
void	parse_file(char *file_path, t_game *game, void *mlx_ptr);
int		path_to_clst(char *file_path, t_clst *file_lst);
t_color	rgb_to_int(int t, int r, int g, int b);
int		rgb_atoi(char *s);
void	validate_map(t_map *map);
void	validate_design(t_dict *design_dict);
void	validate_player(char **map_ptr);
void	*xmlx_init(void);
void	*xmlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*xmlx_new_image(void *mlx_ptr, int width, int height);

/*	game	*/
void	free_all_exit(t_game *game);
void	error_exit(char *message);
int		process_key_press(int keycode, t_game *game);
void	register_hooks(t_game *game);
void	update(t_game *game);

/*	raycast	*/
void	cast_all_rays(t_ray *ray, t_player *player, t_map *map);
t_point	find_horiz_wall_hit(t_ray *ray, t_map *map);
t_point	find_vert_wall_hit(t_ray *ray, t_map *map);
void	set_closer_wall_hit(t_ray *ray, t_point *horiz_hit, t_point *vert_hit);

/*	render	*/
int		get_texel_color(t_wall_strip strip, int y, t_ray *ray,
			t_texture *texture);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		render(t_game *game);
void	render_3d_projection(t_game *game, t_img *win_img);

/*	utils	*/
bool	is_floor(char c);
bool	is_player(char c);
bool	map_has_wall_at(double x, double y, t_map *map);
double	normalize_angle(double ray_angle);

#endif /* CUB3D_H */
