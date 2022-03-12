/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:31:47 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/12 10:40:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static void	set_angle(t_player *player, char c)
{
	if (c == 'E')
		player->angle = M_PI / 2 * 0;
	else if (c == 'S')
		player->angle = M_PI / 2 * 1;
	else if (c == 'W')
		player->angle = M_PI / 2 * 2;
	else if (c == 'N')
		player->angle = M_PI / 2 * 3;
}

static void	set_pos_angle(t_player *player, char **map_ptr)
{
	size_t		y;
	size_t		x;

	y = 0;
	while (map_ptr[y])
	{
		x = 0;
		while (map_ptr[y][x])
		{
			if (is_player(map_ptr[y][x]))
			{
				player->pos.y = y * TILE_SIZE + TILE_SIZE / 2;
				player->pos.x = x * TILE_SIZE + TILE_SIZE / 2;
				set_angle(player, map_ptr[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_player *player, char **map_ptr, t_game *game)
{
	validate_player(map_ptr, game);
	set_pos_angle(player, map_ptr);
	player->radius = PLAYER_RADIUS * MINIMAP_SCALE;
	player->walk_direction = 0;
	player->should_move = false;
	player->fov_angle = 60 * (M_PI / 180);
	player->turn_speed = 15 * (M_PI / 180);
}
