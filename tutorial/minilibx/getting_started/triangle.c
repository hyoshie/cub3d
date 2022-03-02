/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:36:20 by user42            #+#    #+#             */
/*   Updated: 2022/02/26 22:34:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../minilibx-linux/mlx.h"
#include "getting_started.h"

static void my_mlx_pixel_put(t_img *img, int x, int y, int color) {
  char *dst;

  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

static void init_mlx(t_info *info) {
  info->mlx = mlx_init();
  info->mlx_win =
      mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
  info->img.img_ptr = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
  info->img.addr =
      mlx_get_data_addr(info->img.img_ptr, &info->img.bits_per_pixel,
                        &info->img.line_length, &info->img.endian);
}

static void put_image(const t_info *info, const t_point *base) {
  mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img_ptr, base->x,
                          base->y);
}

// static void draw_line(t_img *img, const t_point *base, int angle, int length)
// {
//   const double rad = (double)angle / 180 * M_PI;

//   for (int i = 0, x, y; i < length; i++) {
//     x = base->x + i * cos(rad);
//     y = base->y + i * sin(rad);
//     my_mlx_pixel_put(img, x, y, GREEN);
//   }
// }

static void draw_line_2point(t_img *img, const t_point *start,
                             const t_point *end) {
  const int dx = end->x - start->x;
  const int dy = end->y - start->y;
  const int length = sqrt(dx * dx + dy * dy);
  const double rad = atan2(dy, dx);

  for (int i = 0, x, y; i < length; i++) {
    x = start->x + i * cos(rad);
    y = start->y + i * sin(rad);
    // if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
    my_mlx_pixel_put(img, x, y, GREEN);
  }
}

static void draw_triangle(t_img *img, const t_point *pa, const t_point *pb,
                          const t_point *pc) {
  draw_line_2point(img, pa, pb);
  draw_line_2point(img, pb, pc);
  draw_line_2point(img, pc, pa);
}

static int close(int keycode, t_info *info) {
  (void)info;
  if (keycode == KEY_ESC)
    exit(EXIT_SUCCESS);
  return 0;
}

int main(void) {
  t_info info;

  init_mlx(&info);
  // const t_point a = {50, 100};
  const t_point b = {400, 300};
  const t_point c = {200, 10};
  // draw_line(&info.img, &a, 30, 100);
  draw_triangle(&info.img, &(t_point){50, 100}, &b, &c);

  const t_point base = {0, 0};
  put_image(&info, &base);

  mlx_key_hook(info.mlx_win, close, &info);
  mlx_loop(info.mlx);
  return (0);
}
