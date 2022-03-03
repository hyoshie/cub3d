/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:09:55 by user42            #+#    #+#             */
/*   Updated: 2022/03/02 17:39:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static bool is_wall(char **map, int x, int y) { return map[y][x] == '1'; }

static void render_tile(t_img *tile, t_img *win_img, int x, int y)
{
	char *dst = win_img->addr + (y * WINDOW_WIDTH * TILE_SIZE * sizeof(int) +
	                             x * TILE_SIZE * sizeof(int));
	for (int i = 0; i < TILE_SIZE; i++, dst += WINDOW_WIDTH * sizeof(int))
	{
		memcpy(dst, tile->addr, TILE_SIZE * sizeof(int));
	}
}

static void render_grid(t_img *win_img)
{
	// for (int y = 0; y < WINDOW_HEIGHT; y += TILE_SIZE) {
	//   for (int x = 0; x < WINDOW_WIDTH; x++) {
	//     my_mlx_pixel_put(win_img, x, y, BLACK);
	//   }
	// }
	// for (int x = 0; x < WINDOW_WIDTH; x += TILE_SIZE) {
	//   for (int y = 0; y < WINDOW_HEIGHT; y++) {
	//     my_mlx_pixel_put(win_img, x, y, BLACK);
	//   }
	// }
	(void)win_img;
}

void render_map(t_map *map, t_img *win_img)
{
	for (int y = 0; y < MAP_NUM_ROWS; y++)
	{
		for (int x = 0; x < MAP_NUM_COLS; x++)
		{
			t_img tile = (is_wall(map->map_ptr, x, y)) ? map->wall : map->floor;
			render_tile(&tile, win_img, x, y);
		}
	}
	render_grid(win_img);
}
