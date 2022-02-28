/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:00:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 17:04:19 by user42           ###   ########.fr       */
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
  int x;
  int y;
  int radius;
  int walk_direction; // 1 is down, -1 is up
  int turn_direction; // 1 is right, -1 is left
  double rotation_angle;
  int walk_speed;
  double turn_speed;
} t_player;

typedef struct s_game {
  void *mlx_ptr;
  void *win_ptr;
  t_map map;
  t_player player;
} t_game;

void init_game(t_game *game);
void register_hooks(t_game *game);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
int render(t_game *game);
void init_image(t_img *img, void *mlx_ptr, int width, int height);

#endif /* MINIMAP_H */
