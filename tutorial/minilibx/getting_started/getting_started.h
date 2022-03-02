/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_started.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:36:13 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 10:52:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTING_STARTED_H
#define GETTING_STARTED_H

#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF

#define WIN_WIDTH 500
#define WIN_HEIGHT 500
#define KEY_ESC 0xff1b

typedef struct s_img {
  void *img_ptr;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_img;

typedef struct s_info {
  void *mlx;
  void *mlx_win;
  t_img img;
} t_info;

typedef struct s_point {
  int x;
  int y;
} t_point;

typedef struct s_hexa {
  t_point p1;
  t_point p2;
  t_point p3;
  t_point p4;
  t_point p5;
  t_point p6;
} t_hexa;

#endif /* GETTING_STARTED_H */
