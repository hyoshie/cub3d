/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:00:27 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 17:22:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
#define MINIMAP_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "minilibx-linux/mlx.h"

typedef struct s_img {
  void *img_ptr;
  char *addr;
  int bits_per_pixel;
  int size_line;
  int endian;
} t_img;

typedef struct s_map {
  char **map_ptr;
  t_img floor;
  t_img wall;
} t_map;

typedef struct s_player {
  double x;
  double y;
  double radius;
  int walk_direction; // 1 is forward, -1 is back
  int turn_direction; // 1 is right, -1 is left
  double rotation_angle;
  int walk_speed;
  double turn_speed;
} t_player;

// struct Ray {
//   float rayAngle;
//   float wallHitX;
//   float wallHitY;
//   float distance;
//   int wasHitVertical;
//   int isRayFacingUp;
//   int isRayFacingDown;
//   int isRayFacingLeft;
//   int isRayFacingRight;
//   int wallHitContent;
// } rays[NUM_RAYS];

typedef struct s_ray {
  double angle;
  double wall_hit_x;
  double wall_hit_y;
  double distance;
  bool was_hit_vertical;
  bool is_facing_up;
  bool is_facing_down;
  bool is_facing_left;
  bool is_facing_right;
  int wall_hit_content; // need check
} t_ray;

// typedef struct s_game {
//   void *mlx_ptr;
//   void *win_ptr;
//   t_map map;
//   t_player player;
//   t_ray ray[NUM_RAYS];
// } t_game;

typedef struct s_game {
  void *mlx_ptr;
  void *win_ptr;
  t_map map;
  t_player player;
  t_ray *ray;
} t_game;

void init_game(t_game *game);
void init_image(t_img *img, void *mlx_ptr, int width, int height);
void register_hooks(t_game *game);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
void cast_all_rays(t_ray *ray, t_player *player);
void update(t_game *game);
int render(t_game *game);
void render_map(t_map *map, t_img *win_img);

#endif /* MINIMAP_H */
