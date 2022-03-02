/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:14:45 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 12:03:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "mlx.h"
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
#define WHITE 0x00FFFFFF
#define BLACK 0x00000000
#define MALOON 0x00800000
#define YELLOW 0x00ffff00
#define DARKORANGE 0x00ff8C00
#define CYAN 0x0000ffff
#define DARK 0x00102030

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
  int current_color;
  int original_color;
} t_game;

int add_shadow(double distance, int color) {
  int shadowed;
  if (distance == 1) {
    shadowed = 0x00000000;
    ;
  } else if (distance == 0.5) {
    shadowed = color;
    ;
    ;
  } else if (distance == 0.25) {
    shadowed = color;
    ;
    ;
  } else if (distance == 0) {
    shadowed = color;
  }
  return shadowed;
}

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
  game->current_color = DARK;
  game->original_color = DARK;
}

int key_press_hook(int keycode, t_game *game) {
  (void)game;
  if (keycode == KEY_ESC) {
    exit(1);
  } else if (keycode == KEY_W) {
    game->current_color = add_shadow(1, game->original_color);
    ;
    ;
  } else if (keycode == KEY_A) {
    ;
    ;
  } else if (keycode == KEY_S) {
    ;
    ;
  } else if (keycode == KEY_D) {
    game->current_color = add_shadow(0, game->original_color);
    ;
    ;
  }
  return 0;
}

void print_color_info(int color) {
  int trans_value = (color >> 24) & 0xFF;
  int red_value = (color >> 16) & 0xFF;
  int green_value = (color >> 8) & 0xFF;
  int blue_value = color & 0xFF;

  printf("[trans]%3d [red]%3d [green]%3d [blue]%3d\n", trans_value, red_value,
         green_value, blue_value);
}

void render_rainbow(t_game *game) {
  for (int i = 0; i < WINDOW_HEIGHT; i++) {
    for (int j = 0; j < WINDOW_WIDTH; j++) {
      my_mlx_pixel_put(&game->image, j, i, game->current_color);
    }
  }
  print_color_info(game->current_color);
  mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.img_ptr, 0,
                          0);
}

int loop_hook(t_game *game) {
  (void)game;
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
