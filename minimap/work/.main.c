/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:02:40 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 13:05:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static void init_mlx(t_mlx *mlx) {
  mlx->mlx_ptr = mlx_init();
  mlx->win_ptr =
      mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_NAME);
}

static void my_mlx_pixel_put(t_img *img, int x, int y, int color) {
  char *dst;

  dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

static t_img *create_monocolor_image(void *mlx_ptr, int color) {
  t_img *color_img;

  color_img = malloc(sizeof(t_img));
  color_img->img_ptr = mlx_new_image(mlx_ptr, CHIP_WIDTH, CHIP_HEIGHT);
  color_img->addr =
      mlx_get_data_addr(color_img->img_ptr, &color_img->bits_per_pixel,
                        &color_img->line_length, &color_img->endian);

  for (int y = 0; y < CHIP_HEIGHT; y++) {
    for (int x = 0; x < CHIP_WIDTH; x++) {
      my_mlx_pixel_put(color_img, x, y, color);
    }
  }

  return color_img;
}

static bool is_wall(int x, int y) {
  if (x == 0 || x == SCREEN_WIDTH / CHIP_WIDTH - 1 || y == 0 ||
      y == SCREEN_HEIGHT / CHIP_HEIGHT - 1)
    return true;
  else
    return false;
}

static void paint_screen(const t_mlx *mlx, const t_img *floor,
                         const t_img *wall) {
  t_img *current;

  for (int y = 0; y < SCREEN_HEIGHT / CHIP_HEIGHT; y++) {
    for (int x = 0; x < SCREEN_WIDTH / CHIP_WIDTH; x++) {
      if (is_wall(x, y))
        current = (t_img *)wall;
      else
        current = (t_img *)floor;
      mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, current->img_ptr,
                              CHIP_WIDTH * x, CHIP_HEIGHT * y);
    }
  }
}

int main(void) {
  t_mlx mlx;
  t_img *floor;
  t_img *wall;

  init_mlx(&mlx);
  floor = create_monocolor_image(mlx.mlx_ptr, GRAY);
  wall = create_monocolor_image(mlx.mlx_ptr, OFFWHITE);
  // printf("[floor]%p\n", floor);
  paint_screen(&mlx, floor, wall);
  mlx_loop(mlx.mlx_ptr);
  return 0;
}
