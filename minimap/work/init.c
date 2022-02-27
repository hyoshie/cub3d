/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 00:13:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

void init_image(t_img **img, void *mlx_ptr, int width, int height) {
  *img = malloc(sizeof(t_img));
  (*img)->img_ptr = mlx_new_image(mlx_ptr, width, height);
  (*img)->addr = mlx_get_data_addr((*img)->img_ptr, &(*img)->bits_per_pixel,
                                   &(*img)->size_line, &(*img)->endian);
  printf("[\x1b[32mPASS\x1b[39m]\n");
}

static void init_monocolor_image(t_img *img, void *mlx_ptr, int color) {
  img->img_ptr = mlx_new_image(mlx_ptr, TILE_SIZE, TILE_SIZE);
  img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
                                &img->size_line, &img->endian);

  // init_image(&color_img, mlx_ptr, TILE_SIZE, TILE_SIZE);
  for (int y = 0; y < TILE_SIZE; y++) {
    for (int x = 0; x < TILE_SIZE; x++) {
      my_mlx_pixel_put(img, x, y, color);
    }
  }
}

// static t_img *create_monocolor_image(void *mlx_ptr, int color) {
//   t_img *color_img;

//   color_img = malloc(sizeof(t_img));
//   color_img->img_ptr = mlx_new_image(mlx_ptr, TILE_SIZE, TILE_SIZE);
//   color_img->addr =
//       mlx_get_data_addr(color_img->img_ptr, &color_img->bits_per_pixel,
//                         &color_img->size_line, &color_img->endian);

//   // init_image(&color_img, mlx_ptr, TILE_SIZE, TILE_SIZE);
//   for (int y = 0; y < TILE_SIZE; y++) {
//     for (int x = 0; x < TILE_SIZE; x++) {
//       my_mlx_pixel_put(color_img, x, y, color);
//     }
//   }
//   return color_img;
// }

// temporary map
char *g_map[MAP_NUM_ROWS + 1] = {"11111111111111111111", "10000000000000000001",
                                 "10000000000000000001", "10001010101010101001",
                                 "10000000000000000001", "10000000000000001001",
                                 "10000000000000001001", "10000000000000001001",
                                 "10000000000001111001", "10000000000000000001",
                                 "10000000000000000001", "10000000000000000001",
                                 "11111111111111111111", NULL};

void init_map(t_map *map, void *mlx_ptr) {
  map->map_ptr = g_map;
  map->mlx_ptr = mlx_ptr;
  init_monocolor_image(&map->floor, mlx_ptr, OFFWHITE);
  init_monocolor_image(&map->wall, mlx_ptr, GRAY);
  // map->floor = create_monocolor_image(mlx_ptr, OFFWHITE);
  // map->wall = create_monocolor_image(mlx_ptr, GRAY);
}

void init_game(t_game *game) {
  game->mlx_ptr = mlx_init();
  game->win_ptr =
      mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
  // init_image(&game->win_img, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  init_map(&game->map, game->mlx_ptr);
  // init_player(game);
  // init_ray(game);
}
