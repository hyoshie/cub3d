/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:00:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 00:08:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
#define MINIMAP_H

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
  void *mlx_ptr;
  t_img floor;
  t_img wall;
} t_map;

typedef struct s_game {
  void *mlx_ptr;
  void *win_ptr;
  // t_img *win_img;
  t_map map;
} t_game;

void init_game(t_game *game);
void register_hooks(t_game *game);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
void render(t_game *game);
void init_image(t_img **img, void *mlx_ptr, int width, int height);

#endif /* MINIMAP_H */
