/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:09:55 by user42            #+#    #+#             */
/*   Updated: 2022/03/01 11:11:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static bool is_wall(char **map, int x, int y) { return map[y][x] == '1'; }

static void render_tile(t_img *tile, t_img *win_img, int x, int y) {
  char *dst = win_img->addr + (y * WINDOW_WIDTH * TILE_SIZE * sizeof(int) +
                               x * TILE_SIZE * sizeof(int));
  for (int i = 0; i < TILE_SIZE; i++, dst += WINDOW_WIDTH * sizeof(int)) {
    memcpy(dst, tile->addr, TILE_SIZE * sizeof(int));
  }
}

void render_map(t_map *map, t_img *win_img) {
  for (int y = 0; y < MAP_NUM_ROWS; y++) {
    for (int x = 0; x < MAP_NUM_COLS; x++) {
      t_img tile = (is_wall(map->map_ptr, x, y)) ? map->wall : map->floor;
      render_tile(&tile, win_img, x, y);
    }
  }
}
