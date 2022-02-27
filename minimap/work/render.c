/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:40:49 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 00:14:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static bool is_wall(char **map, int x, int y) {
  if (map[y][x] == '1')
    return true;
  else
    return false;
}

// static void render_map(t_map *map, void *win_ptr) {
//   t_img *current;

//   for (int y = 0; y < MAP_NUM_ROWS; y++) {
//     for (int x = 0; x < MAP_NUM_COLS; x++) {
//       current = (is_wall(map->map_ptr, x, y)) ? map->wall : map->floor;
//       mlx_put_image_to_window(map->mlx_ptr, win_ptr, current->img_ptr,
//                               TILE_SIZE * x, TILE_SIZE * y);
//     }
//   }
// }

static void render_tile(t_img *tile, t_img *current, int x, int y) {
  char *dst = current->addr + (y * WINDOW_WIDTH * TILE_SIZE * sizeof(int) +
                               x * TILE_SIZE * sizeof(int));
  // printf("[\x1b[32mPASS\x1b[39m]\n");
  for (int i = 0; i < TILE_SIZE; i++, dst += WINDOW_WIDTH * sizeof(int)) {
    memcpy(dst, tile->addr, TILE_SIZE * sizeof(int));
  }
}

static void render_map(t_map *map, t_img *current) {
  t_img tile;
  for (int y = 0; y < MAP_NUM_ROWS; y++) {
    for (int x = 0; x < MAP_NUM_COLS; x++) {
      tile = (is_wall(map->map_ptr, x, y)) ? map->wall : map->floor;
      render_tile(&tile, current, x, y);
    }
  }
}

void render(t_game *game) {
  t_img current;

  current.img_ptr = mlx_new_image(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  current.addr = mlx_get_data_addr(current.img_ptr, &current.bits_per_pixel,
                                   &current.size_line, &current.endian);
  // init_image(&current, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  render_map(&game->map, &current);
  // render_map(game->map, game->win_img);
  // render_map(game->map, game->win_ptr);
  // render_player();
  // render_ray();
  // mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
  // game->win_img->img_ptr,
  //                         0, 0);
  mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current.img_ptr, 0, 0);
}
