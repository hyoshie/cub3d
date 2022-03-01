/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:15:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 11:08:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

void init_image(t_img *img, void *mlx_ptr, int width, int height) {
  img->img_ptr = mlx_new_image(mlx_ptr, width, height);
  img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
                                &img->size_line, &img->endian);
}

static void init_monocolor_image(t_img *img, void *mlx_ptr, int color) {
  init_image(img, mlx_ptr, TILE_SIZE, TILE_SIZE);
  for (int y = 0; y < TILE_SIZE; y++) {
    for (int x = 0; x < TILE_SIZE; x++) {
      my_mlx_pixel_put(img, x, y, color);
    }
  }
}

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
  init_monocolor_image(&map->floor, mlx_ptr, GRAY);
  init_monocolor_image(&map->wall, mlx_ptr, OFFWHITE);
}

void init_player(t_player *player) {
  player->x = WINDOW_WIDTH / 2;
  player->y = WINDOW_HEIGHT / 2;
  player->radius = 10;
  player->walk_direction = 0;
  player->turn_direction = 0;
  player->rotation_angle = M_PI / 2 * 3;
  player->walk_speed = WALK_SPEED;
  player->turn_speed = TURN_SPEED;
}

void init_game(t_game *game) {
  game->mlx_ptr = mlx_init();
  // mlx_do_key_autorepeaton(game->mlx_ptr);
  game->win_ptr =
      mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
  init_map(&game->map, game->mlx_ptr);
  init_player(&game->player);
  // init_ray(game);
}
