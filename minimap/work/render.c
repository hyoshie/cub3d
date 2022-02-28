/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:40:49 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 16:10:52 by user42           ###   ########.fr       */
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

static void render_tile(t_img *tile, t_img *current, int x, int y) {
  char *dst = current->addr + (y * WINDOW_WIDTH * TILE_SIZE * sizeof(int) +
                               x * TILE_SIZE * sizeof(int));
  for (int i = 0; i < TILE_SIZE; i++, dst += WINDOW_WIDTH * sizeof(int)) {
    memcpy(dst, tile->addr, TILE_SIZE * sizeof(int));
  }
}

static void render_map(t_map *map, t_img *current) {
  for (int y = 0; y < MAP_NUM_ROWS; y++) {
    for (int x = 0; x < MAP_NUM_COLS; x++) {
      t_img tile = (is_wall(map->map_ptr, x, y)) ? map->wall : map->floor;
      render_tile(&tile, current, x, y);
    }
  }
}

static void render_player(t_player *player, t_img *current) {
  for (int i = -player->radius; i < player->radius; i++) {
    for (int j = -player->radius; j < player->radius; j++) {
      if (pow(j, 2) + pow(i, 2) < pow(player->radius, 2))
        my_mlx_pixel_put(current, player->x + j, player->y + i, RED);
    }
  }
}

int render(t_game *game) {
  t_img current;

  init_image(&current, game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
  render_map(&game->map, &current);
  render_player(&game->player, &current);
  // render_ray();
  mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current.img_ptr, 0, 0);
  return (0);
}
