/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:09:55 by user42            #+#    #+#             */
/*   Updated: 2022/03/03 23:51:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "minimap.h"

static bool	is_wall(char **map, int x, int y)
{
	return (map[y][x] == '1');
}

static void	render_tile(t_img *win_img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE * MINIMAP_SCALE)
	{
		j = 0;
		while (j < TILE_SIZE * MINIMAP_SCALE)
		{
			my_mlx_pixel_put(win_img, x * TILE_SIZE * MINIMAP_SCALE + j, \
							 y * TILE_SIZE * MINIMAP_SCALE + i, color);
			j++;
		}
		i++;
	}
}

// static void render_grid(t_img *win_img)
// {
// 	for (int y = 0; y < WINDOW_HEIGHT * MINIMAP_SCALE;
// 			y += TILE_SIZE * MINIMAP_SCALE) {
// 	  for (int x = 0; x < WINDOW_WIDTH * MINIMAP_SCALE; x++) {
// 	    my_mlx_pixel_put(win_img, x, y, BLACK);
// 	  }
// 	}
// 	for (int x = 0; x < WINDOW_WIDTH * MINIMAP_SCALE;
// 			x += TILE_SIZE * MINIMAP_SCALE) {
// 	  for (int y = 0; y < WINDOW_HEIGHT * MINIMAP_SCALE; y++) {
// 	    my_mlx_pixel_put(win_img, x, y, BLACK);
// 	  }
// 	}
// }

void	render_map(t_map *map, t_img *win_img)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			if (is_wall(map->map_ptr, j, i))
				render_tile(win_img, j, i, GRAY);
			else
				render_tile(win_img, j, i, LIGHTGRAY);
			j++;
		}
		i++;
	}
}
