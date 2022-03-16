/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:31:47 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/16 11:08:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

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
	int	y;
	int	x;

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
				player->wall_hit = player->pos;
				set_angle(player, map_ptr[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	init_player(char **map_ptr, t_player *player)
{
	validate_player(map_ptr);
	set_pos_angle(player, map_ptr);
	player->walk_direction = 0;
	player->fov_angle = 60 * (M_PI / 180);
	player->turn_speed = 5 * (M_PI / 180);
	player->auto_turn_speed = 1 * (M_PI / 180);
	player->should_move = false;
	player->should_rotate = true;
}
