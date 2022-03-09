/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <hyoshie@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:51:39 by user42            #+#    #+#             */
/*   Updated: 2022/03/09 18:55:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static double	calc_minimap_scale(t_map *map)
{
	double	scale;
	double	aspect_ratio;

	aspect_ratio = (double)map->num_rows / map->num_cols;
	// printf("[aspect_ratio]%f\n", aspect_ratio);
	if (aspect_ratio > WINDOW_ASPECT_RATIO)
		scale = MINIMAP_HEIGHT_MAX / (double)map->height;
	else
		scale = MINIMAP_WIDTH_MAX / (double)map->width;
	if (scale > MINIMAP_SCALE)
		scale = MINIMAP_SCALE;
	return (scale);
}

void	init_minimap(t_minimap *mini, t_map *map, t_point player_pos)
{
	mini->map = map;
	mini->scale = calc_minimap_scale(mini->map);
	mini->tile_size = TILE_SIZE * mini->scale;
	mini->player_pos.x = player_pos.x * mini->scale;
	mini->player_pos.y = player_pos.y * mini->scale;
	mini->player_radius = PLAYER_RADIUS * mini->scale;
}
