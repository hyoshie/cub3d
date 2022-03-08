/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:31:47 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/08 12:54:40 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

static bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_angle(t_player *player, char c)
{
	if (c == 'E')
		player->rotation_angle = M_PI / 2 * 0;
	else if (c == 'S')
		player->rotation_angle = M_PI / 2 * 1;
	else if (c == 'W')
		player->rotation_angle = M_PI / 2 * 2;
	else if (c == 'N')
		player->rotation_angle = M_PI / 2 * 3;
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
				player->position.y = y * TILE_SIZE;
				player->position.x = x * TILE_SIZE;
				set_angle(player, map_ptr[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	set_player(t_player *player, char **map_ptr)
{
	set_pos_angle(player, map_ptr);
	player->radius = PLAYER_RADIUS * MINIMAP_SCALE;
	player->walk_direction = 0;
	player->should_move = false;
	player->fov_angle = 60 * (M_PI / 180);
	player->walk_speed = WALK_SPEED;
	player->turn_speed = 15 * (M_PI / 180);
}
