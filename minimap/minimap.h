/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:00:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/24 13:33:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
#define MINIMAP_H

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480
#define SCREEN_NAME "####Minimap####"
#define CHIP_WIDTH 60
#define CHIP_HEIGHT 60

// #define RED 0x00FF0000
// #define GREEN 0x0000FF00
// #define BLUE 0x000000FF
#define GRAY 0x002F3128
#define OFFWHITE 0x00FFF9EE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "minilibx-linux/mlx.h"

typedef struct {
  void *mlx_ptr;
  void *win_ptr;
} t_mlx;

typedef struct {
  void *img_ptr;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_img;

#endif /* MINIMAP_H */

/*   getting_started.h                                  :+:      :+:    :+:   */

// #ifndef GETTING_STARTED_H
// #define GETTING_STARTED_H

// #define WIN_WIDTH 500
// #define WIN_HEIGHT 500

// typedef struct s_info {
//   void *mlx;
//   void *mlx_win;
//   t_img img;
// } t_info;

// typedef struct s_point {
//   int x;
//   int y;
// } t_point;

// #endif /* GETTING_STARTED_H */
