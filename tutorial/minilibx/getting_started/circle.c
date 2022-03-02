/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:36:20 by user42            #+#    #+#             */
/*   Updated: 2022/02/24 14:24:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../minilibx-linux/mlx.h"
#include "getting_started.h"

static void my_mlx_pixel_put(t_img *img, int x, int y, int color) {
  char *dst;

  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

static bool is_in_circle(t_point p, t_point center, int radius) {
  if (pow(p.x - center.x, 2) + pow(p.y - center.y, 2) < pow(radius, 2))
    return true;
  else
    return false;
}

void draw_cicle_on_image(t_img *img, int radius) {
  const t_point center = {250, 250};

  for (int i = -radius; i < radius; i++) {
    for (int j = -radius; j < radius; j++) {
      t_point current = {center.x + j, center.y + i};
      if (is_in_circle(current, center, radius))
        my_mlx_pixel_put(img, current.x, current.y, BLUE);
    }
  }
}

void init_mlx(t_info *info) {
  info->mlx = mlx_init();
  info->mlx_win =
      mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
  info->img.img_ptr = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
  info->img.addr =
      mlx_get_data_addr(info->img.img_ptr, &info->img.bits_per_pixel,
                        &info->img.line_length, &info->img.endian);
}

void put_image(const t_info *info, const t_point *base) {
  mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img_ptr, base->x,
                          base->y);
}

int main(void) {
  t_info info;

  init_mlx(&info);
  draw_cicle_on_image(&info.img, 50);

  const t_point base = {0, 0};
  put_image(&info, &base);

  mlx_loop(info.mlx);
  return (0);
}
