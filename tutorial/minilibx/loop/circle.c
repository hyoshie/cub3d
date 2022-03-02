/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:14:45 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 00:17:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 400
#define RADIUS 100
#define KEY_ESC 0xff1b
#define KEY_A 0x61
#define KEY_D 0x64
#define KEY_S 0x73
#define KEY_W 0x77
#define STEP_X 10
#define STEP_Y 10

typedef struct {
  void *img_ptr;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_image;

typedef struct {
  int centarl_x;
  int centarl_y;
  t_image image;
} t_circle;

typedef struct {
  void *mlx_ptr;
  void *win_ptr;
  t_circle circle;
} t_game;

void my_mlx_pixel_put(t_image *image, int x, int y, int color) {
  char *dst;

  dst =
      image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

static void init_circle(void *mlx_ptr, t_circle *circle) {
  circle->centarl_x = WINDOW_WIDTH / 2;
  circle->centarl_y = WINDOW_HEIGHT / 2;
  circle->image.img_ptr = mlx_new_image(mlx_ptr, RADIUS * 2, RADIUS * 2);
  circle->image.addr =
      mlx_get_data_addr(circle->image.img_ptr, &circle->image.bits_per_pixel,
                        &circle->image.line_length, &circle->image.endian);
  for (int y = 0; y < RADIUS * 2; y++) {
    for (int x = 0; x < RADIUS * 2; x++) {
      if (pow(x - RADIUS, 2) + pow(y - RADIUS, 2) < pow(RADIUS, 2))
        my_mlx_pixel_put(&circle->image, x, y, 0x00FF0000);
      else
        my_mlx_pixel_put(&circle->image, x, y, 0xFF000000);
    }
  }
}

void init_game(t_game *game) {
  game->mlx_ptr = mlx_init();
  game->win_ptr =
      mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Circle!!");
  init_circle(game->mlx_ptr, &game->circle);
}

void render_circle(t_game *game) {
  mlx_put_image_to_window(
      game->mlx_ptr, game->win_ptr, game->circle.image.img_ptr,
      game->circle.centarl_x - RADIUS, game->circle.centarl_y - RADIUS);
}

int key_press_hook(int keycode, t_game *game) {
  (void)game;
  if (keycode == KEY_ESC) {
    exit(1);
  } else if (keycode == KEY_W) {
    game->circle.centarl_y -= STEP_Y;
  } else if (keycode == KEY_A) {
    game->circle.centarl_x -= STEP_X;
  } else if (keycode == KEY_S) {
    game->circle.centarl_y += STEP_Y;
  } else if (keycode == KEY_D) {
    game->circle.centarl_x += STEP_X;
  }
  render_circle(game);
  return 0;
}

void set_hooks(t_game *game) {
  mlx_key_hook(game->win_ptr, key_press_hook, game);
  ;
}

int main(void) {
  t_game game;

  init_game(&game);
  render_circle(&game);
  set_hooks(&game);
  mlx_loop(game.mlx_ptr);
  return (0);
}
