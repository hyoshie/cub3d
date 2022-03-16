/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:42:08 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:09:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

bool	map_has_wall_at(double x, double y, t_map *map)
{
	const int	map_grid_index_x = x / TILE_SIZE;
	const int	map_grid_index_y = y / TILE_SIZE;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
	{
		return (true);
	}
	else
	{
		return (map->map_ptr[map_grid_index_y][map_grid_index_x] == '1');
	}
}
