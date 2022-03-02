/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:36:20 by user42            #+#    #+#             */
/*   Updated: 2022/02/25 11:11:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

t_point *point_new(int x, int y) {
  t_point *point = malloc(sizeof(t_point));

  point->x = x;
  point->y = y;
  return (point);
}

t_point **create_random_3point() {
  t_point **point_array = malloc(sizeof(t_point *) * 3);
  srand(time(NULL));
  for (int i = 0; i < 3; i++) {
    int x = abs(rand()) % WIN_WIDTH;
    int y = abs(rand()) % WIN_HEIGHT;
    point_array[i] = point_new(x, y);
  }
  return point_array;
}

int main(void) {
  t_info info;
  t_point **points;

  init_mlx(&info);
  points = create_random_3point();
  draw_triangle(&info.img, points[0], points[1], points[2]);

  const t_point base = {0, 0};
  put_image(&info, &base);

  mlx_key_hook(info.mlx_win, close, &info);
  mlx_loop(info.mlx);
  return (0);
}
