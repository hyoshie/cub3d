/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:14:45 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 00:45:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF

typedef struct {
  void *img_ptr;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_image;

typedef struct {
  void *mlx_ptr;
  void *win_ptr;
  t_image image;
} t_game;

void my_mlx_pixel_put(t_image *image, int x, int y, int color) {
  char *dst;

  dst =
      image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

void init_game(t_game *game) {
  game->mlx_ptr = mlx_init();
  game->win_ptr = mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
                                 "###RAINBOW###");
  game->image.img_ptr =
      mlx_new_image(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  game->image.addr =
      mlx_get_data_addr(game->image.img_ptr, &game->image.bits_per_pixel,
                        &game->image.line_length, &game->image.endian);
}

int key_press_hook(int keycode, t_game *game) {
  (void)game;
  if (keycode == KEY_ESC) {
    exit(1);
  }
  return 0;
}

void render_rainbow(t_game *game) {
  static int count;
  int color;
  switch (count++ % 3) {
  case 0:
    color = RED;
    break;
  case 1:
    color = GREEN;
    break;
  case 2:
    color = BLUE;
    break;
  }

  for (int i = 0; i < WINDOW_HEIGHT; i++) {
    for (int j = 0; j < WINDOW_WIDTH; j++) {
      my_mlx_pixel_put(&game->image, j, i, color);
    }
  }

  mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.img_ptr, 0,
                          0);
}

int loop_hook(t_game *game) {
  (void)game;
  printf("hogehoge\n");
  fflush(stdout);
  sleep(1);
  render_rainbow(game);
  return (0);
}

void set_hooks(t_game *game) {
  mlx_key_hook(game->win_ptr, key_press_hook, game);
  mlx_loop_hook(game->mlx_ptr, loop_hook, game);
  ;
}

int main(void) {
  t_game game;

  init_game(&game);
  set_hooks(&game);
  mlx_loop(game.mlx_ptr);
  return (0);
}
